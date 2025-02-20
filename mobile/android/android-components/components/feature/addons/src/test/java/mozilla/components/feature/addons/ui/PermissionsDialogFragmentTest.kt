/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

package mozilla.components.feature.addons.ui

import android.view.Gravity.TOP
import android.view.ViewGroup
import android.widget.Button
import android.widget.TextView
import androidx.appcompat.widget.AppCompatCheckBox
import androidx.core.view.isVisible
import androidx.fragment.app.FragmentManager
import androidx.fragment.app.FragmentTransaction
import androidx.recyclerview.widget.RecyclerView
import androidx.test.ext.junit.runners.AndroidJUnit4
import mozilla.components.feature.addons.Addon
import mozilla.components.feature.addons.R
import mozilla.components.feature.addons.ui.AddonDialogFragment.PromptsStyling
import mozilla.components.support.test.mock
import mozilla.components.support.test.robolectric.testContext
import mozilla.components.support.utils.ext.getParcelableCompat
import org.junit.Assert
import org.junit.Assert.assertEquals
import org.junit.Assert.assertFalse
import org.junit.Assert.assertSame
import org.junit.Assert.assertTrue
import org.junit.Test
import org.junit.runner.RunWith
import org.mockito.Mockito.doNothing
import org.mockito.Mockito.doReturn
import org.mockito.Mockito.spy

@RunWith(AndroidJUnit4::class)
class PermissionsDialogFragmentTest {

    @Test
    fun `build dialog`() {
        val addon = Addon(
            "id",
            translatableName = mapOf(Addon.DEFAULT_LOCALE to "my_addon"),
            permissions = listOf("privacy", "<all_urls>", "tabs"),
        )
        val fragment = createPermissionsDialogFragment(addon, permissions = addon.permissions)

        doReturn(testContext).`when`(fragment).requireContext()
        val dialog = fragment.onCreateDialog(null)
        dialog.show()

        val name = addon.translateName(testContext)
        val titleTextView = dialog.findViewById<TextView>(R.id.title)
        val optionalOrRequiredTextView = dialog.findViewById<TextView>(R.id.optional_or_required_text)
        val permissionsRecyclerView = dialog.findViewById<RecyclerView>(R.id.permissions)
        val recyclerAdapter = permissionsRecyclerView.adapter!! as RequiredPermissionsAdapter
        val permissionList = fragment.buildPermissionsList()
        val optionalOrRequiredText = fragment.buildOptionalOrRequiredText(hasPermissions = permissionList.isNotEmpty())
        val allowedInPrivateBrowsing =
            dialog.findViewById<AppCompatCheckBox>(R.id.allow_in_private_browsing)

        assertTrue(titleTextView.text.contains(name))
        assertTrue(optionalOrRequiredText.contains(testContext.getString(R.string.mozac_feature_addons_permissions_dialog_subtitle)))
        assertTrue(permissionList.contains(testContext.getString(R.string.mozac_feature_addons_permissions_privacy_description)))
        assertTrue(permissionList.contains(testContext.getString(R.string.mozac_feature_addons_permissions_all_urls_description)))
        assertTrue(permissionList.contains(testContext.getString(R.string.mozac_feature_addons_permissions_tabs_description)))
        assertTrue(allowedInPrivateBrowsing.isVisible)

        assertTrue(optionalOrRequiredTextView.text.contains(testContext.getString(R.string.mozac_feature_addons_permissions_dialog_subtitle)))
        Assert.assertNotNull(recyclerAdapter)
        assertEquals(3, recyclerAdapter.itemCount)
        assertTrue(recyclerAdapter.getItemAtPosition(0).contains(testContext.getString(R.string.mozac_feature_addons_permissions_privacy_description)))
        assertTrue(recyclerAdapter.getItemAtPosition(1).contains(testContext.getString(R.string.mozac_feature_addons_permissions_all_urls_description)))
        assertTrue(recyclerAdapter.getItemAtPosition(2).contains(testContext.getString(R.string.mozac_feature_addons_permissions_tabs_description)))
    }

    @Test
    fun `clicking on dialog buttons notifies lambdas`() {
        val addon = Addon("id", translatableName = mapOf(Addon.DEFAULT_LOCALE to "my_addon"))

        val fragment = createPermissionsDialogFragment(addon, permissions = emptyList())
        var allowedWasExecuted = false
        var denyWasExecuted = false
        var learnMoreWasExecuted = false

        fragment.onPositiveButtonClicked = { _, _ ->
            allowedWasExecuted = true
        }

        fragment.onNegativeButtonClicked = {
            denyWasExecuted = true
        }

        fragment.onLearnMoreClicked = {
            learnMoreWasExecuted = true
        }

        doReturn(testContext).`when`(fragment).requireContext()

        val dialog = fragment.onCreateDialog(null)
        dialog.show()

        val positiveButton = dialog.findViewById<Button>(R.id.allow_button)
        val negativeButton = dialog.findViewById<Button>(R.id.deny_button)
        val learnMoreLink = dialog.findViewById<TextView>(R.id.learn_more_link)

        positiveButton.performClick()
        negativeButton.performClick()
        learnMoreLink.performClick()

        assertTrue(allowedWasExecuted)
        assertTrue(denyWasExecuted)
        assertTrue(learnMoreWasExecuted)
    }

    @Test
    fun `dismissing the dialog notifies deny lambda`() {
        val addon = Addon("id", translatableName = mapOf(Addon.DEFAULT_LOCALE to "my_addon"))

        val fragment = createPermissionsDialogFragment(addon, permissions = emptyList())
        var denyWasExecuted = false

        fragment.onNegativeButtonClicked = {
            denyWasExecuted = true
        }

        doReturn(testContext).`when`(fragment).requireContext()

        doReturn(mockFragmentManager()).`when`(fragment).parentFragmentManager

        val dialog = fragment.onCreateDialog(null)
        dialog.show()

        fragment.onCancel(mock())

        assertTrue(denyWasExecuted)
    }

    @Test
    fun `dialog must have all the styles of the feature promptsStyling object`() {
        val addon = Addon("id", translatableName = mapOf(Addon.DEFAULT_LOCALE to "my_addon"))
        val styling = PromptsStyling(TOP, true)
        val fragment = createPermissionsDialogFragment(addon, permissions = emptyList(), styling)

        doReturn(testContext).`when`(fragment).requireContext()

        val dialog = fragment.onCreateDialog(null)

        val dialogAttributes = dialog.window!!.attributes

        assertTrue(dialogAttributes.gravity == TOP)
        assertTrue(dialogAttributes.width == ViewGroup.LayoutParams.MATCH_PARENT)
    }

    @Test
    fun `handles add-ons without permissions`() {
        val addon = Addon(
            "id",
            translatableName = mapOf(Addon.DEFAULT_LOCALE to "my_addon"),
        )
        val fragment = createPermissionsDialogFragment(addon, permissions = emptyList())

        doReturn(testContext).`when`(fragment).requireContext()
        val dialog = fragment.onCreateDialog(null)
        dialog.show()

        val name = addon.translateName(testContext)
        val titleTextView = dialog.findViewById<TextView>(R.id.title)
        val optionalOrRequiredTextView = dialog.findViewById<TextView>(R.id.optional_or_required_text)
        val permissionsRecyclerView = dialog.findViewById<RecyclerView>(R.id.permissions)
        val recyclerAdapter = permissionsRecyclerView.adapter!! as RequiredPermissionsAdapter
        val permissionList = fragment.buildPermissionsList()
        val optionalOrRequiredText = fragment.buildOptionalOrRequiredText(hasPermissions = permissionList.isNotEmpty())

        assertTrue(titleTextView.text.contains(name))
        assertFalse(optionalOrRequiredText.contains(testContext.getString(R.string.mozac_feature_addons_permissions_dialog_subtitle)))
        assertFalse(optionalOrRequiredTextView.text.contains(testContext.getString(R.string.mozac_feature_addons_permissions_dialog_subtitle)))
        assertEquals(0, recyclerAdapter.itemCount)
        assertFalse(permissionList.contains(testContext.getString(R.string.mozac_feature_addons_permissions_privacy_description)))
        assertFalse(permissionList.contains(testContext.getString(R.string.mozac_feature_addons_permissions_all_urls_description)))
        assertFalse(permissionList.contains(testContext.getString(R.string.mozac_feature_addons_permissions_tabs_description)))
    }

    @Test
    fun `build dialog for optional permissions`() {
        val addon = Addon(
            "id",
            translatableName = mapOf(Addon.DEFAULT_LOCALE to "my_addon"),
            permissions = listOf("privacy", "https://example.org/", "tabs"),
        )
        val fragment = createPermissionsDialogFragment(addon, forOptionalPermissions = true, permissions = addon.permissions)

        doReturn(testContext).`when`(fragment).requireContext()
        val dialog = fragment.onCreateDialog(null)
        dialog.show()

        val addonName = addon.translateName(testContext)
        val titleTextView = dialog.findViewById<TextView>(R.id.title)
        val optionalOrRequiredTextView = dialog.findViewById<TextView>(R.id.optional_or_required_text)
        val permissionsRecyclerView = dialog.findViewById<RecyclerView>(R.id.permissions)
        val recyclerAdapter = permissionsRecyclerView.adapter!! as RequiredPermissionsAdapter
        val allowButton = dialog.findViewById<Button>(R.id.allow_button)
        val denyButton = dialog.findViewById<Button>(R.id.deny_button)
        val permissionsList = fragment.buildPermissionsList()
        val optionalOrRequiredText = fragment.buildOptionalOrRequiredText(hasPermissions = permissionsList.isNotEmpty())
        val privateBrowsingCheckbox = dialog.findViewById<AppCompatCheckBox>(R.id.allow_in_private_browsing)

        assertEquals(
            titleTextView.text,
            testContext.getString(R.string.mozac_feature_addons_optional_permissions_dialog_title, addonName),
        )

        assertTrue(optionalOrRequiredText.contains(testContext.getString(R.string.mozac_feature_addons_optional_permissions_dialog_subtitle)))
        assertTrue(permissionsList.contains(testContext.getString(R.string.mozac_feature_addons_permissions_privacy_description)))
        assertTrue(
            permissionsList.contains(
                testContext.getString(
                    R.string.mozac_feature_addons_permissions_one_site_description,
                    "example.org",
                ),
            ),
        )
        assertTrue(permissionsList.contains(testContext.getString(R.string.mozac_feature_addons_permissions_tabs_description)))

        assertTrue(optionalOrRequiredTextView.text.contains(testContext.getString(R.string.mozac_feature_addons_optional_permissions_dialog_subtitle)))
        assertTrue(recyclerAdapter.getItemAtPosition(0).contains(testContext.getString(R.string.mozac_feature_addons_permissions_privacy_description)))
        assertTrue(recyclerAdapter.getItemAtPosition(1).contains(testContext.getString(R.string.mozac_feature_addons_permissions_tabs_description)))
        assertTrue(
            recyclerAdapter.getItemAtPosition(2).contains(
                testContext.getString(
                    R.string.mozac_feature_addons_permissions_one_site_description,
                    "example.org",
                ),
            ),
        )

        assertFalse(privateBrowsingCheckbox.isVisible)
        assertEquals(allowButton.text, testContext.getString(R.string.mozac_feature_addons_permissions_dialog_allow))
        assertEquals(denyButton.text, testContext.getString(R.string.mozac_feature_addons_permissions_dialog_deny))
    }

    @Test
    fun `hide private browsing checkbox when the add-on does not allow running in private windows`() {
        val permissions = listOf("privacy", "<all_urls>", "tabs")
        val addon = Addon(
            "id",
            translatableName = mapOf(Addon.DEFAULT_LOCALE to "my_addon"),
            permissions = permissions,
            incognito = Addon.Incognito.NOT_ALLOWED,
        )
        val fragment = createPermissionsDialogFragment(addon, permissions)

        assertSame(
            addon,
            fragment.arguments?.getParcelableCompat(KEY_ADDON, Addon::class.java),
        )

        doReturn(testContext).`when`(fragment).requireContext()

        val dialog = fragment.onCreateDialog(null)

        dialog.show()

        val name = addon.translateName(testContext)
        val titleTextView = dialog.findViewById<TextView>(R.id.title)
        val allowedInPrivateBrowsing =
            dialog.findViewById<AppCompatCheckBox>(R.id.allow_in_private_browsing)

        assertTrue(titleTextView.text.contains(name))
        assertFalse(allowedInPrivateBrowsing.isVisible)
    }

    private fun createPermissionsDialogFragment(
        addon: Addon,
        permissions: List<String>,
        promptsStyling: PromptsStyling? = null,
        forOptionalPermissions: Boolean = false,
    ): PermissionsDialogFragment {
        return spy(
            PermissionsDialogFragment.newInstance(
                addon = addon,
                permissions = permissions,
                promptsStyling = promptsStyling,
                forOptionalPermissions = forOptionalPermissions,
            ),
        ).apply {
            doNothing().`when`(this).dismiss()
        }
    }

    private fun mockFragmentManager(): FragmentManager {
        val fragmentManager: FragmentManager = mock()
        val transaction: FragmentTransaction = mock()
        doReturn(transaction).`when`(fragmentManager).beginTransaction()
        return fragmentManager
    }
}
