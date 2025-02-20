/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/. */

import { html, ifDefined } from "chrome://global/content/vendor/lit.all.mjs";
import { MozLitElement } from "chrome://global/content/lit-utils.mjs";

const stylesTemplate = () =>
  html` <link
    rel="stylesheet"
    href="chrome://browser/content/aboutlogins/components/login-message-popup.css"
  />`;

export const MessagePopup = ({ l10nid, message, webTitle = "" }) => {
  return html` <div class="tooltip-container">
    <div class="arrow-box">
      <p
        class="tooltip-message"
        data-l10n-id=${ifDefined(l10nid)}
        data-l10n-args=${JSON.stringify({ webTitle })}
      >
        ${ifDefined(message)}
      </p>
    </div>
  </div>`;
};

export class PasswordWarning extends MozLitElement {
  static get properties() {
    return {
      isNewLogin: { type: Boolean, reflect: true },
      webTitle: { type: String, reflect: true },
      arrowDirection: { type: String },
      message: { type: String },
    };
  }

  constructor() {
    super();
    this.isNewLogin = false;
    this.arrowDirection = "left";
  }
  render() {
    if (this.message) {
      return html`${stylesTemplate()}
      ${MessagePopup({
        message: this.message,
      })}`;
    }

    return this.isNewLogin
      ? html`${stylesTemplate()}
        ${MessagePopup({
          l10nid: "about-logins-add-password-tooltip",
        })}`
      : html`${stylesTemplate()}
        ${MessagePopup({
          l10nid: "about-logins-edit-password-tooltip",
          webTitle: this.webTitle,
        })}`;
  }
}

export class OriginWarning extends MozLitElement {
  static get properties() {
    return {
      l10nId: { type: String },
      message: { type: String },
      arrowDirection: { type: String },
    };
  }

  constructor() {
    super();
    this.arrowDirection = "left";
  }

  render() {
    return html`${stylesTemplate()}
    ${MessagePopup({ l10nid: this.l10nId, message: this.message })}`;
  }
}

customElements.define("password-warning", PasswordWarning);
customElements.define("origin-warning", OriginWarning);
