/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

package mozilla.components.concept.engine.webextension

import mozilla.components.concept.engine.EngineSession

/**
 * Notifies applications or other components of engine events related to web
 * extensions e.g. an extension was installed, or an extension wants to open
 * a new tab.
 */
interface WebExtensionDelegate {

    /**
     * Invoked when a web extension was installed successfully.
     *
     * @param extension The installed extension.
     */
    fun onInstalled(extension: WebExtension) = Unit

    /**
     * Invoked when a web extension was uninstalled successfully.
     *
     * @param extension The uninstalled extension.
     */
    fun onUninstalled(extension: WebExtension) = Unit

    /**
     * Invoked when a web extension was enabled successfully.
     *
     * @param extension The enabled extension.
     */
    fun onEnabled(extension: WebExtension) = Unit

    /**
     * Invoked when a web extension was disabled successfully.
     *
     * @param extension The disabled extension.
     */
    fun onDisabled(extension: WebExtension) = Unit

    /**
     * Invoked when a web extension was started successfully.
     *
     * @param extension The extension that has completed its startup.
     */
    fun onReady(extension: WebExtension) = Unit

    /**
     * Invoked when optional permissions for a web extension have changed.
     *
     * @param extension The [WebExtension] for which permissions have changed.
     */
    fun onOptionalPermissionsChanged(extension: WebExtension) = Unit

    /**
     * Invoked when a web extension in private browsing allowed is set.
     *
     * @param extension the modified [WebExtension] instance.
     */
    fun onAllowedInPrivateBrowsingChanged(extension: WebExtension) = Unit

    /**
     * Invoked when a web extension attempts to open a new tab via
     * browser.tabs.create. Note that browser.tabs.update and browser.tabs.remove
     * can only be observed using session-specific handlers,
     * see [WebExtension.registerTabHandler].
     *
     * @param extension The [WebExtension] that wants to open a new tab.
     * @param engineSession an instance of engine session to open a new tab with.
     * @param active whether or not the new tab should be active/selected.
     * @param url the target url to be loaded in a new tab.
     */
    fun onNewTab(extension: WebExtension, engineSession: EngineSession, active: Boolean, url: String) = Unit

    /**
     * Invoked when a web extension defines a browser action. To listen for session-specific
     * overrides of [Action]s and other action-specific events (e.g. opening a popup)
     * see [WebExtension.registerActionHandler].
     *
     * @param extension The [WebExtension] defining the browser action.
     * @param action the defined browser [Action].
     */
    fun onBrowserActionDefined(extension: WebExtension, action: Action) = Unit

    /**
     * Invoked when a web extension defines a page action. To listen for session-specific
     * overrides of [Action]s and other action-specific events (e.g. opening a popup)
     * see [WebExtension.registerActionHandler].
     *
     * @param extension The [WebExtension] defining the browser action.
     * @param action the defined page [Action].
     */
    fun onPageActionDefined(extension: WebExtension, action: Action) = Unit

    /**
     * Invoked when a browser or page action wants to toggle a popup view.
     *
     * @param extension The [WebExtension] that wants to display the popup.
     * @param engineSession The [EngineSession] to use for displaying the popup.
     * @param action the [Action] that defines the popup.
     * @return the [EngineSession] used to display the popup, or null if no popup
     * was displayed.
     */
    fun onToggleActionPopup(
        extension: WebExtension,
        engineSession: EngineSession,
        action: Action,
    ): EngineSession? = null

    /**
     * Invoked during installation of a [WebExtension] to confirm the required permissions.
     *
     * @param extension the extension being installed. The required permissions can be accessed using
     * [WebExtension.getMetadata] and [Metadata.requiredPermissions]/[Metadata.requiredOrigins]/.
     * @param onConfirm A callback to indicate the user's selection on the prompt.
     * @param permissions Contains a list of all the permissions requested for install.
     * @param origins Contains a list of all the origins requested for install.
     * @param dataCollectionPermissions Contains a list of all the data collection permissions requested for install.
     * @return whether or not installation should process i.e. the permissions have been granted.
     */
    fun onInstallPermissionRequest(
        extension: WebExtension,
        permissions: List<String>,
        origins: List<String>,
        dataCollectionPermissions: List<String>,
        onConfirm: (PermissionPromptResponse) -> Unit,
    ) = Unit

    /**
     * Invoked whenever the installation of a [WebExtension] failed.
     *
     * @param extension extension the extension that failed to be installed. It can be null when the
     * extension couldn't be downloaded or the extension couldn't be parsed for example.
     * @param exception the reason why the installation failed.
     */
    fun onInstallationFailedRequest(
        extension: WebExtension?,
        exception: WebExtensionInstallException,
    ) = Unit

    /**
     * Invoked when a web extension has changed its permissions while trying to update to a
     * new version. This requires user interaction as the updated extension will not be installed,
     * until the user grants the new permissions.
     *
     * @param current The current [WebExtension].
     * @param updated The update [WebExtension] that requires extra permissions.
     * @param newPermissions Contains a list of all the new permissions.
     * @param onPermissionsGranted A callback to indicate if the new permissions from the [updated] extension
     * are granted or not.
     */
    fun onUpdatePermissionRequest(
        current: WebExtension,
        updated: WebExtension,
        newPermissions: List<String>,
        onPermissionsGranted: ((Boolean) -> Unit),
    ) = Unit

    /**
     * Invoked when a web extension requests optional permissions. This requires user interaction since the
     * user needs to grant or revoke these optional permissions.
     *
     * @param extension The [WebExtension].
     * @param permissions The list of all the optional permissions.
     * @param origins The list of all the optional host permissions.
     * @param onPermissionsGranted A callback to indicate if the optional permissions have been granted or not.
     */
    fun onOptionalPermissionsRequest(
        extension: WebExtension,
        permissions: List<String>,
        origins: List<String>,
        onPermissionsGranted: ((Boolean) -> Unit),
    ) = Unit

    /**
     * Invoked when the list of installed extensions has been updated in the engine
     * (the web extension runtime). This happens as a result of debugging tools (e.g
     * web-ext) installing temporary extensions. It does not happen in the regular flow
     * of installing / uninstalling extensions by the user.
     */
    fun onExtensionListUpdated() = Unit

    /**
     * Invoked when the extension process spawning has been disabled. This can occur because
     * it has been killed or crashed too many times. A client should determine what to do next.
     */
    fun onDisabledExtensionProcessSpawning() = Unit
}
