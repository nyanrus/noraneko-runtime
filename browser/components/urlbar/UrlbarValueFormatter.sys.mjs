/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

const lazy = {};

ChromeUtils.defineESModuleGetters(lazy, {
  BrowserUIUtils: "resource:///modules/BrowserUIUtils.sys.mjs",
  PrivateBrowsingUtils: "resource://gre/modules/PrivateBrowsingUtils.sys.mjs",
  UrlbarPrefs: "resource:///modules/UrlbarPrefs.sys.mjs",
  UrlbarUtils: "resource:///modules/UrlbarUtils.sys.mjs",
});

/**
 * Applies URL highlighting and other styling to the text in the urlbar input,
 * depending on the text.
 */
export class UrlbarValueFormatter {
  /**
   * @param {UrlbarInput} urlbarInput
   *   The parent instance of UrlbarInput
   */
  constructor(urlbarInput) {
    this.urlbarInput = urlbarInput;
    this.window = this.urlbarInput.window;
    this.document = this.window.document;

    // This is used only as an optimization to avoid removing formatting in
    // the _remove* format methods when no formatting is actually applied.
    this._formattingApplied = false;

    this.window.addEventListener("resize", this);
  }

  get inputField() {
    return this.urlbarInput.inputField;
  }

  get scheme() {
    return this.urlbarInput.querySelector("#urlbar-scheme");
  }

  async update() {
    let instance = (this._updateInstance = {});

    // _getUrlMetaData does URI fixup, which depends on the search service, so
    // make sure it's initialized, or URIFixup may force synchronous
    // initialization. It can be uninitialized here on session restore. Skip
    // this if the service is already initialized in order to avoid the async
    // call in the common case. However, we can't access Service.search before
    // first paint (delayed startup) because there's a performance test that
    // prohibits it, so first await delayed startup.
    if (!this.window.gBrowserInit.delayedStartupFinished) {
      await this.window.delayedStartupPromise;
      if (this._updateInstance != instance) {
        return;
      }
    }
    if (!Services.search.isInitialized) {
      try {
        await Services.search.init();
      } catch {}

      if (this._updateInstance != instance) {
        return;
      }
    }

    // If this window is being torn down, stop here
    if (!this.window.docShell) {
      return;
    }

    // Cleanup that must be done in any case, even if there's no value.
    this.urlbarInput.removeAttribute("domaindir");
    this.scheme.value = "";

    if (!this.urlbarInput.value) {
      return;
    }

    // Remove the current formatting.
    this._removeURLFormat();
    this._removeSearchAliasFormat();

    // Apply new formatting.  Formatter methods should return true if they
    // successfully formatted the value and false if not.  We apply only
    // one formatter at a time, so we stop at the first successful one.
    this.window.requestAnimationFrame(() => {
      if (this._updateInstance != instance) {
        return;
      }
      this._formattingApplied = this._formatURL() || this._formatSearchAlias();
    });
  }

  #ensureFormattedHostVisible(urlMetaData) {
    // Make sure the host is always visible. Since it is aligned on
    // the first strong directional character, we set scrollLeft
    // appropriately to ensure the domain stays visible in case of an
    // overflow.
    // In the future, for example in bug 525831, we may add a forceRTL
    // char just after the domain, and in such a case we should not
    // scroll to the left.
    urlMetaData = urlMetaData || this._getUrlMetaData();
    if (!urlMetaData) {
      this.urlbarInput.removeAttribute("domaindir");
      return;
    }
    let { url, preDomain, domain } = urlMetaData;
    let directionality = this.window.windowUtils.getDirectionFromText(domain);
    if (
      directionality == this.window.windowUtils.DIRECTION_RTL &&
      url[preDomain.length + domain.length] != "\u200E"
    ) {
      this.urlbarInput.setAttribute("domaindir", "rtl");
      this.inputField.scrollLeft = this.inputField.scrollLeftMax;
    } else {
      this.urlbarInput.setAttribute("domaindir", "ltr");
      this.inputField.scrollLeft = 0;
    }
    this.urlbarInput.updateTextOverflow();
  }

  _getUrlMetaData() {
    if (this.urlbarInput.focused) {
      return null;
    }

    let inputValue = this.urlbarInput.value;
    // getFixupURIInfo logs an error if the URL is empty. Avoid that by
    // returning early.
    if (!inputValue) {
      return null;
    }
    let browser = this.window.gBrowser.selectedBrowser;
    let browserState = this.urlbarInput.getBrowserState(browser);

    // Since doing a full URIFixup and offset calculations is expensive, we
    // keep the metadata cached in the browser itself, so when switching tabs
    // we can skip most of this.
    if (
      browserState.urlMetaData &&
      browserState.urlMetaData.inputValue == inputValue &&
      browserState.urlMetaData.untrimmedValue == this.urlbarInput.untrimmedValue
    ) {
      return browserState.urlMetaData.data;
    }
    browserState.urlMetaData = {
      inputValue,
      untrimmedValue: this.urlbarInput.untrimmedValue,
      data: null,
    };

    // Get the URL from the fixup service:
    let flags =
      Services.uriFixup.FIXUP_FLAG_FIX_SCHEME_TYPOS |
      Services.uriFixup.FIXUP_FLAG_ALLOW_KEYWORD_LOOKUP;
    if (lazy.PrivateBrowsingUtils.isWindowPrivate(this.window)) {
      flags |= Services.uriFixup.FIXUP_FLAG_PRIVATE_CONTEXT;
    }

    let uriInfo;
    try {
      uriInfo = Services.uriFixup.getFixupURIInfo(
        this.urlbarInput.untrimmedValue,
        flags
      );
    } catch (ex) {}
    // Ignore if we couldn't make a URI out of this, the URI resulted in a search,
    // or the URI has a non-http(s)/ftp protocol.
    if (
      !uriInfo ||
      !uriInfo.fixedURI ||
      uriInfo.keywordProviderName ||
      !["http", "https", "ftp"].includes(uriInfo.fixedURI.scheme)
    ) {
      return null;
    }

    // We must ensure the protocol is present in the parsed string, so we don't
    // get confused by user:pass@host. It may not have been present originally,
    // or it may have been trimmed. We later use trimmedLength to ensure we
    // don't count the length of a trimmed protocol when determining which parts
    // of the input value to de-emphasize as `preDomain`.
    let url = inputValue;
    let trimmedLength = 0;
    let trimmedProtocol = lazy.BrowserUIUtils.trimURLProtocol;
    if (
      this.urlbarInput.untrimmedValue.startsWith(trimmedProtocol) &&
      !inputValue.startsWith(trimmedProtocol)
    ) {
      // The protocol has been trimmed, so we add it back.
      url = trimmedProtocol + inputValue;
      trimmedLength = trimmedProtocol.length;
    } else if (
      uriInfo.schemelessInput == Ci.nsILoadInfo.SchemelessInputTypeSchemeless
    ) {
      // The original string didn't have a protocol, but it was identified as
      // a URL. It's not important which scheme we use for parsing, so we'll
      // just copy URIFixup.
      let scheme = uriInfo.fixedURI.scheme + "://";
      url = scheme + url;
      trimmedLength = scheme.length;
    }

    // This RegExp is not a perfect match, and for specially crafted URLs it may
    // get the host wrong; for safety reasons we will later compare the found
    // host with the one that will actually be loaded.
    let matchedURL = url.match(
      /^(([a-z]+:\/\/)(?:[^\/#?]+@)?)(\S+?)(?::\d+)?\s*(?:[\/#?]|$)/
    );
    if (!matchedURL) {
      return null;
    }
    let [, preDomain, schemeWSlashes, domain] = matchedURL;

    // If the found host differs from the fixed URI one, we can't properly
    // highlight it. To stay on the safe side, we clobber user's input with
    // the fixed URI and apply highlight to that one instead.
    let replaceUrl = false;
    try {
      replaceUrl =
        Services.io.newURI("http://" + domain).displayHost !=
        uriInfo.fixedURI.displayHost;
    } catch (ex) {
      return null;
    }
    if (replaceUrl) {
      if (this._inGetUrlMetaData) {
        // Protect from infinite recursion.
        return null;
      }
      try {
        this._inGetUrlMetaData = true;
        this.window.gBrowser.userTypedValue = null;
        this.urlbarInput.setURI(uriInfo.fixedURI);
        return this._getUrlMetaData();
      } finally {
        this._inGetUrlMetaData = false;
      }
    }

    return (browserState.urlMetaData.data = {
      domain,
      origin: uriInfo.fixedURI.host,
      preDomain,
      schemeWSlashes,
      trimmedLength,
      url,
    });
  }

  _removeURLFormat() {
    if (!this._formattingApplied) {
      return;
    }
    let controller = this.urlbarInput.editor.selectionController;
    let strikeOut = controller.getSelection(controller.SELECTION_URLSTRIKEOUT);
    strikeOut.removeAllRanges();
    let selection = controller.getSelection(controller.SELECTION_URLSECONDARY);
    selection.removeAllRanges();
    this._formatScheme(controller.SELECTION_URLSTRIKEOUT, true);
    this._formatScheme(controller.SELECTION_URLSECONDARY, true);
    this.inputField.style.setProperty("--urlbar-scheme-size", "0px");
  }

  /**
   * Whether formatting is enabled.
   *
   * @returns {boolean}
   */
  get formattingEnabled() {
    return lazy.UrlbarPrefs.get("formatting.enabled");
  }

  /**
   * Whether a striked out active mixed content protocol will show for the
   * currently loaded input field value.
   *
   * @param {string} val The value to evaluate. If it's not the currently
   *   loaded page, this will return false, as we cannot know if a page has
   *   active mixed content until it's loaded.
   * @returns {boolean}
   */
  willShowFormattedMixedContentProtocol(val) {
    return (
      this.formattingEnabled &&
      !lazy.UrlbarPrefs.get("security.insecure_connection_text.enabled") &&
      val.startsWith("https://") &&
      val == this.urlbarInput.value &&
      this.#showingMixedContentLoadedPageUrl
    );
  }

  /**
   * Whether the currently loaded page is in mixed content mode.
   *
   * @returns {boolean} whether the loaded page has active mixed content.
   */
  get #showingMixedContentLoadedPageUrl() {
    return (
      this.urlbarInput.getAttribute("pageproxystate") == "valid" &&
      this.window.gBrowser.securityUI.state &
        Ci.nsIWebProgressListener.STATE_LOADED_MIXED_ACTIVE_CONTENT
    );
  }

  /**
   * If the input value is a URL and the input is not focused, this
   * formatter method highlights the domain, and if mixed content is present,
   * it crosses out the https scheme.  It also ensures that the host is
   * visible (not scrolled out of sight).
   *
   * @returns {boolean}
   *   True if formatting was applied and false if not.
   */
  _formatURL() {
    let urlMetaData = this._getUrlMetaData();
    if (!urlMetaData) {
      return false;
    }
    let state = this.urlbarInput.getBrowserState(
      this.window.gBrowser.selectedBrowser
    );
    if (state.searchTerms) {
      return false;
    }

    let { domain, origin, preDomain, schemeWSlashes, trimmedLength, url } =
      urlMetaData;

    // When RTL domains cause the address bar to overflow to the left, the
    // protocol may get hidden, if it was not trimmed. We then set the
    // `--urlbar-scheme-size` property to show the protocol in a floating box.
    // We don't show the floating protocol box if:
    //  - The insecure label is enabled, as it is a sufficient indicator.
    //  - The current page is mixed content but formatting is disabled, as it
    //    may be confusing for the user to see a non striked out protocol.
    //  - The protocol was trimmed.
    let isUnformattedMixedContent =
      this.#showingMixedContentLoadedPageUrl && !this.formattingEnabled;
    if (
      !lazy.UrlbarPrefs.get("security.insecure_connection_text.enabled") &&
      !isUnformattedMixedContent &&
      this.urlbarInput.value.startsWith(schemeWSlashes)
    ) {
      this.scheme.value = schemeWSlashes;
      this.inputField.style.setProperty(
        "--urlbar-scheme-size",
        schemeWSlashes.length + "ch"
      );
    }

    this.#ensureFormattedHostVisible(urlMetaData);

    if (!this.formattingEnabled) {
      return false;
    }

    let editor = this.urlbarInput.editor;
    let controller = editor.selectionController;

    this._formatScheme(controller.SELECTION_URLSECONDARY);

    let textNode = editor.rootElement.firstChild;

    // Strike out the "https" part if mixed active content status should be
    // shown.
    if (this.willShowFormattedMixedContentProtocol(this.urlbarInput.value)) {
      let range = this.document.createRange();
      range.setStart(textNode, 0);
      range.setEnd(textNode, 5);
      let strikeOut = controller.getSelection(
        controller.SELECTION_URLSTRIKEOUT
      );
      strikeOut.addRange(range);
      this._formatScheme(controller.SELECTION_URLSTRIKEOUT);
    }

    let baseDomain = domain;
    let subDomain = "";
    try {
      baseDomain = Services.eTLD.getBaseDomainFromHost(origin);
      if (!domain.endsWith(baseDomain)) {
        // getBaseDomainFromHost converts its resultant to ACE.
        let IDNService = Cc["@mozilla.org/network/idn-service;1"].getService(
          Ci.nsIIDNService
        );
        // XXX This should probably convert to display IDN instead.
        // https://bugzilla.mozilla.org/show_bug.cgi?id=1906048
        baseDomain = IDNService.convertACEtoUTF8(baseDomain);
      }
    } catch (e) {}
    if (baseDomain != domain) {
      subDomain = domain.slice(0, -baseDomain.length);
    }

    let selection = controller.getSelection(controller.SELECTION_URLSECONDARY);

    let rangeLength = preDomain.length + subDomain.length - trimmedLength;
    if (rangeLength) {
      let range = this.document.createRange();
      range.setStart(textNode, 0);
      range.setEnd(textNode, rangeLength);
      selection.addRange(range);
    }

    let startRest = preDomain.length + domain.length - trimmedLength;
    if (startRest < url.length - trimmedLength) {
      let range = this.document.createRange();
      range.setStart(textNode, startRest);
      range.setEnd(textNode, url.length - trimmedLength);
      selection.addRange(range);
    }

    return true;
  }

  _formatScheme(selectionType, clear) {
    let editor = this.scheme.editor;
    let controller = editor.selectionController;
    let textNode = editor.rootElement.firstChild;
    let selection = controller.getSelection(selectionType);
    if (clear) {
      selection.removeAllRanges();
    } else {
      let r = this.document.createRange();
      r.setStart(textNode, 0);
      r.setEnd(textNode, textNode.textContent.length);
      selection.addRange(r);
    }
  }

  _removeSearchAliasFormat() {
    if (!this._formattingApplied) {
      return;
    }
    let selection = this.urlbarInput.editor.selectionController.getSelection(
      Ci.nsISelectionController.SELECTION_FIND
    );
    selection.removeAllRanges();
  }

  /**
   * If the input value starts with an @engine search alias, this highlights it.
   *
   * @returns {boolean}
   *   True if formatting was applied and false if not.
   */
  _formatSearchAlias() {
    if (!this.formattingEnabled) {
      return false;
    }

    let editor = this.urlbarInput.editor;
    let textNode = editor.rootElement.firstChild;
    let value = textNode.textContent;
    let trimmedValue = value.trim();

    if (
      !trimmedValue.startsWith("@") ||
      (this.urlbarInput.popup || this.urlbarInput.view).oneOffSearchButtons
        .selectedButton
    ) {
      return false;
    }

    let alias = this._findEngineAliasOrRestrictKeyword();
    if (!alias) {
      return false;
    }

    // Make sure the current input starts with the alias because it can change
    // without the popup results changing.  Most notably that happens when the
    // user performs a search using an alias: The popup closes (preserving its
    // results), the search results page loads, and the input value is set to
    // the URL of the page.
    if (trimmedValue != alias && !trimmedValue.startsWith(alias + " ")) {
      return false;
    }

    let index = value.indexOf(alias);
    if (index < 0) {
      return false;
    }

    // We abuse the SELECTION_FIND selection type to do our highlighting.
    // It's the only type that works with Selection.setColors().
    let selection = editor.selectionController.getSelection(
      Ci.nsISelectionController.SELECTION_FIND
    );

    let range = this.document.createRange();
    range.setStart(textNode, index);
    range.setEnd(textNode, index + alias.length);
    selection.addRange(range);

    let fg = "#2362d7";
    let bg = "#d2e6fd";

    // Selection.setColors() will swap the given foreground and background
    // colors if it detects that the contrast between the background
    // color and the frame color is too low.  Normally we don't want that
    // to happen; we want it to use our colors as given (even if setColors
    // thinks the contrast is too low).  But it's a nice feature for non-
    // default themes, where the contrast between our background color and
    // the input's frame color might actually be too low.  We can
    // (hackily) force setColors to use our colors as given by passing
    // them as the alternate colors.  Otherwise, allow setColors to swap
    // them, which we can do by passing "currentColor".  See
    // nsTextPaintStyle::GetHighlightColors for details.
    if (
      this.document.documentElement.hasAttribute("lwtheme") ||
      this.window.matchMedia("(prefers-contrast)").matches
    ) {
      // non-default theme(s)
      selection.setColors(fg, bg, "currentColor", "currentColor");
    } else {
      // default themes
      selection.setColors(fg, bg, fg, bg);
    }

    return true;
  }

  _findEngineAliasOrRestrictKeyword() {
    // To determine whether the input contains a valid alias, check if the
    // selected result is a search result with an alias. If there is no selected
    // result, we check the first result in the view, for cases when we do not
    // highlight token alias results. The selected result is null when the popup
    // is closed, but we want to continue highlighting the alias when the popup
    // is closed, and that's why we keep around the previously selected result
    // in _selectedResult.
    this._selectedResult =
      this.urlbarInput.view.selectedResult ||
      this.urlbarInput.view.getResultAtIndex(0) ||
      this._selectedResult;

    if (!this._selectedResult) {
      return null;
    }

    let { type, payload } = this._selectedResult;

    if (type === lazy.UrlbarUtils.RESULT_TYPE.SEARCH) {
      return payload.keyword || null;
    }

    if (type === lazy.UrlbarUtils.RESULT_TYPE.RESTRICT) {
      return payload.autofillKeyword || null;
    }

    return null;
  }

  /**
   * Passes DOM events to the _on_<event type> methods.
   *
   * @param {Event} event
   *   DOM event.
   */
  handleEvent(event) {
    let methodName = "_on_" + event.type;
    if (methodName in this) {
      this[methodName](event);
    } else {
      throw new Error("Unrecognized UrlbarValueFormatter event: " + event.type);
    }
  }

  _on_resize(event) {
    if (event.target != this.window) {
      return;
    }
    // Make sure the host remains visible in the input field when the window is
    // resized.  We don't want to hurt resize performance though, so do this
    // only after resize events have stopped and a small timeout has elapsed.
    if (this._resizeThrottleTimeout) {
      this.window.clearTimeout(this._resizeThrottleTimeout);
    }
    this._resizeThrottleTimeout = this.window.setTimeout(() => {
      this._resizeThrottleTimeout = null;
      let instance = (this._resizeInstance = {});
      this.window.requestAnimationFrame(() => {
        if (instance == this._resizeInstance) {
          this.#ensureFormattedHostVisible();
        }
      });
    }, 100);
  }
}
