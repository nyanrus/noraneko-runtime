/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

package org.mozilla.fenix.home.sessioncontrol

import io.mockk.every
import io.mockk.mockk
import mozilla.components.feature.tab.collections.TabCollection
import mozilla.components.feature.top.sites.TopSite
import mozilla.components.service.nimbus.messaging.Message
import mozilla.components.service.pocket.PocketStory
import mozilla.components.service.pocket.PocketStory.PocketRecommendedStory
import org.junit.Assert.assertEquals
import org.junit.Assert.assertFalse
import org.junit.Assert.assertTrue
import org.junit.Test
import org.mozilla.fenix.home.bookmarks.Bookmark
import org.mozilla.fenix.home.ext.showWallpaperOnboardingDialog
import org.mozilla.fenix.home.recentvisits.RecentlyVisitedItem.RecentHistoryGroup
import org.mozilla.fenix.utils.Settings

class SessionControlViewTest {

    @Test
    fun `GIVEN recent Bookmarks WHEN normalModeAdapterItems is called THEN show bookmarks section`() {
        val settings: Settings = mockk()
        val topSites = emptyList<TopSite>()
        val collections = emptyList<TabCollection>()
        val expandedCollections = emptySet<Long>()
        val bookmarks = listOf(Bookmark())
        val historyMetadata = emptyList<RecentHistoryGroup>()
        val pocketStories = emptyList<PocketStory>()

        every { settings.showTopSitesFeature } returns true
        every { settings.showRecentTabsFeature } returns true
        every { settings.showBookmarksHomeFeature } returns true
        every { settings.historyMetadataUIFeature } returns true
        every { settings.showPocketRecommendationsFeature } returns true
        every { settings.showSetupChecklist } returns false

        val results = normalModeAdapterItems(
            settings,
            topSites,
            collections,
            expandedCollections,
            bookmarks,
            false,
            null,
            false,
            showRecentSyncedTab = false,
            recentVisits = historyMetadata,
            pocketStories = pocketStories,
        )

        assertEquals(4, results.size)
        assertTrue(results[0] is AdapterItem.TopPlaceholderItem)
        assertTrue(results[1] is AdapterItem.BookmarksHeader)
        assertTrue(results[2] is AdapterItem.Bookmarks)
        assertTrue(results[3] is AdapterItem.BottomSpacer)
    }

    @Test
    fun `GIVEN a nimbusMessageCard WHEN normalModeAdapterItems is called THEN add a NimbusMessageCard`() {
        val settings: Settings = mockk()
        val topSites = emptyList<TopSite>()
        val collections = emptyList<TabCollection>()
        val expandedCollections = emptySet<Long>()
        val bookmarks = listOf(Bookmark())
        val historyMetadata = emptyList<RecentHistoryGroup>()
        val pocketStories = emptyList<PocketStory>()
        val nimbusMessageCard: Message = mockk()

        every { settings.showTopSitesFeature } returns true
        every { settings.showRecentTabsFeature } returns true
        every { settings.showBookmarksHomeFeature } returns true
        every { settings.historyMetadataUIFeature } returns true
        every { settings.showPocketRecommendationsFeature } returns true
        every { settings.showSetupChecklist } returns false

        val results = normalModeAdapterItems(
            settings,
            topSites,
            collections,
            expandedCollections,
            bookmarks,
            false,
            nimbusMessageCard,
            false,
            showRecentSyncedTab = false,
            historyMetadata,
            pocketStories,
        )

        assertTrue(results.contains(AdapterItem.NimbusMessageCard(nimbusMessageCard)))
    }

    @Test
    fun `GIVEN recent tabs WHEN normalModeAdapterItems is called THEN show jump back in section`() {
        val settings: Settings = mockk()
        val topSites = emptyList<TopSite>()
        val collections = emptyList<TabCollection>()
        val expandedCollections = emptySet<Long>()
        val bookmarks = listOf<Bookmark>()
        val historyMetadata = emptyList<RecentHistoryGroup>()
        val pocketStories = emptyList<PocketStory>()

        every { settings.showTopSitesFeature } returns true
        every { settings.showRecentTabsFeature } returns true
        every { settings.showBookmarksHomeFeature } returns true
        every { settings.historyMetadataUIFeature } returns true
        every { settings.showPocketRecommendationsFeature } returns true
        every { settings.showSetupChecklist } returns false

        val results = normalModeAdapterItems(
            settings,
            topSites,
            collections,
            expandedCollections,
            bookmarks,
            false,
            null,
            true,
            showRecentSyncedTab = false,
            historyMetadata,
            pocketStories,
        )

        assertEquals(4, results.size)
        assertTrue(results[0] is AdapterItem.TopPlaceholderItem)
        assertTrue(results[1] is AdapterItem.RecentTabsHeader)
        assertTrue(results[2] is AdapterItem.RecentTabItem)
        assertTrue(results[3] is AdapterItem.BottomSpacer)
    }

    @Test
    fun `GIVEN history metadata WHEN normalModeAdapterItems is called THEN show recently visited section`() {
        val settings: Settings = mockk()
        val topSites = emptyList<TopSite>()
        val collections = emptyList<TabCollection>()
        val expandedCollections = emptySet<Long>()
        val bookmarks = listOf<Bookmark>()
        val historyMetadata = listOf(RecentHistoryGroup("title", emptyList()))
        val pocketStories = emptyList<PocketStory>()

        every { settings.showTopSitesFeature } returns true
        every { settings.showRecentTabsFeature } returns true
        every { settings.showBookmarksHomeFeature } returns true
        every { settings.historyMetadataUIFeature } returns true
        every { settings.showPocketRecommendationsFeature } returns true
        every { settings.showSetupChecklist } returns false

        val results = normalModeAdapterItems(
            settings,
            topSites,
            collections,
            expandedCollections,
            bookmarks,
            false,
            null,
            false,
            showRecentSyncedTab = false,
            historyMetadata,
            pocketStories,
        )

        assertEquals(4, results.size)
        assertTrue(results[0] is AdapterItem.TopPlaceholderItem)
        assertTrue(results[1] is AdapterItem.RecentVisitsHeader)
        assertTrue(results[2] is AdapterItem.RecentVisitsItems)
        assertTrue(results[3] is AdapterItem.BottomSpacer)
    }

    @Test
    fun `GIVEN pocket articles WHEN normalModeAdapterItems is called THEN show stories section`() {
        val settings: Settings = mockk()
        val topSites = emptyList<TopSite>()
        val collections = emptyList<TabCollection>()
        val expandedCollections = emptySet<Long>()
        val bookmarks = listOf<Bookmark>()
        val historyMetadata = emptyList<RecentHistoryGroup>()
        val pocketStories = listOf(PocketRecommendedStory("", "", "", "", "", 1, 1))

        every { settings.showTopSitesFeature } returns true
        every { settings.showRecentTabsFeature } returns true
        every { settings.showBookmarksHomeFeature } returns true
        every { settings.historyMetadataUIFeature } returns true
        every { settings.showPocketRecommendationsFeature } returns true
        every { settings.showSetupChecklist } returns false

        val results = normalModeAdapterItems(
            settings,
            topSites,
            collections,
            expandedCollections,
            bookmarks,
            false,
            null,
            false,
            showRecentSyncedTab = false,
            historyMetadata,
            pocketStories,
            true,
        )

        assertEquals(3, results.size)
        assertTrue(results[0] is AdapterItem.TopPlaceholderItem)
        assertTrue(results[1] is AdapterItem.PocketStoriesItem)
        assertTrue(results[2] is AdapterItem.BottomSpacer)

        // When the first frame has not yet drawn don't add pocket.
        val results2 = normalModeAdapterItems(
            settings,
            topSites,
            collections,
            expandedCollections,
            bookmarks,
            false,
            null,
            false,
            showRecentSyncedTab = false,
            historyMetadata,
            pocketStories,
            false,
        )

        assertEquals(2, results2.size)
        assertTrue(results2[0] is AdapterItem.TopPlaceholderItem)
        assertTrue(results2[1] is AdapterItem.BottomSpacer)
    }

    @Test
    fun `GIVEN none bookmarks, recentTabs, historyMetadata or pocketArticles WHEN normalModeAdapterItems is called THEN the customize home button is not added`() {
        val settings: Settings = mockk()
        val topSites = emptyList<TopSite>()
        val collections = emptyList<TabCollection>()
        val expandedCollections = emptySet<Long>()
        val bookmarks = listOf<Bookmark>()
        val historyMetadata = emptyList<RecentHistoryGroup>()
        val pocketStories = emptyList<PocketStory>()

        every { settings.showTopSitesFeature } returns true
        every { settings.showRecentTabsFeature } returns true
        every { settings.showBookmarksHomeFeature } returns true
        every { settings.historyMetadataUIFeature } returns true
        every { settings.showPocketRecommendationsFeature } returns true
        every { settings.showSetupChecklist } returns false

        val results = normalModeAdapterItems(
            settings,
            topSites,
            collections,
            expandedCollections,
            bookmarks,
            false,
            null,
            false,
            showRecentSyncedTab = false,
            historyMetadata,
            pocketStories,
        )
        assertEquals(results.size, 2)
        assertTrue(results[0] is AdapterItem.TopPlaceholderItem)
    }

    @Test
    fun `GIVEN setup checklist is enabled THEN it is added to the adapter items`() {
        val settings: Settings = mockk()
        val topSites = emptyList<TopSite>()
        val collections = emptyList<TabCollection>()
        val expandedCollections = emptySet<Long>()
        val bookmarks = emptyList<Bookmark>()
        val historyMetadata = emptyList<RecentHistoryGroup>()
        val pocketStories = emptyList<PocketStory>()

        every { settings.showTopSitesFeature } returns false
        every { settings.showRecentTabsFeature } returns false
        every { settings.showBookmarksHomeFeature } returns false
        every { settings.historyMetadataUIFeature } returns false
        every { settings.showPocketRecommendationsFeature } returns false
        every { settings.showSetupChecklist } returns true

        val results = normalModeAdapterItems(
            settings = settings,
            topSites = topSites,
            collections = collections,
            expandedCollections = expandedCollections,
            bookmarks = bookmarks,
            showCollectionsPlaceholder = false,
            nimbusMessageCard = null,
            showRecentTab = false,
            showRecentSyncedTab = true,
            recentVisits = historyMetadata,
            pocketStories = pocketStories,
        )

        val expected = listOf(
            AdapterItem.TopPlaceholderItem,
            AdapterItem.SetupChecklist,
            AdapterItem.BottomSpacer,
        )
        assertEquals(expected, results)
        assertTrue(results[1] is AdapterItem.SetupChecklist)
    }

    @Test
    fun `GIVEN all items THEN top placeholder item is always the first item`() {
        val settings: Settings = mockk()
        val collection = mockk<TabCollection> {
            every { id } returns 123L
        }
        val topSites = listOf<TopSite>(mockk())
        val collections = listOf(collection)
        val expandedCollections = emptySet<Long>()
        val bookmarks = listOf<Bookmark>(mockk())
        val historyMetadata = listOf<RecentHistoryGroup>(mockk())
        val pocketStories = listOf<PocketStory>(mockk())

        every { settings.showTopSitesFeature } returns true
        every { settings.showRecentTabsFeature } returns true
        every { settings.showBookmarksHomeFeature } returns true
        every { settings.historyMetadataUIFeature } returns true
        every { settings.showPocketRecommendationsFeature } returns true
        every { settings.showSetupChecklist } returns true

        val results = normalModeAdapterItems(
            settings,
            topSites,
            collections,
            expandedCollections,
            bookmarks,
            false,
            null,
            true,
            showRecentSyncedTab = true,
            historyMetadata,
            pocketStories,
        )

        assertTrue(results[0] is AdapterItem.TopPlaceholderItem)
    }

    @Test
    fun `GIVEN app opened three times, should show the dialog and wallpaper feature has not been recommended WHEN showWallpaperOnboardingDialog THEN returns true`() {
        val settings = mockk<Settings>()
        every { settings.numberOfAppLaunches } returns 3
        every { settings.showWallpaperOnboarding } returns true

        assertTrue(settings.showWallpaperOnboardingDialog(false))
    }

    @Test
    fun `GIVEN app opened two times, should show the dialog and wallpaper feature has not been recommended WHEN showWallpaperOnboardingDialog THEN returns false`() {
        val settings = mockk<Settings>()
        every { settings.numberOfAppLaunches } returns 2
        every { settings.showWallpaperOnboarding } returns true

        assertFalse(settings.showWallpaperOnboardingDialog(false))
    }

    @Test
    fun `GIVEN app opened three times, should not show the dialog and wallpaper feature has not been recommended WHEN showWallpaperOnboardingDialog THEN returns false`() {
        val settings = mockk<Settings>()
        every { settings.numberOfAppLaunches } returns 3
        every { settings.showWallpaperOnboarding } returns false

        assertFalse(settings.showWallpaperOnboardingDialog(false))
    }

    @Test
    fun `GIVEN app opened three times, should show the dialog and wallpaper feature already recommended WHEN showWallpaperOnboardingDialog THEN returns false`() {
        val settings = mockk<Settings>()
        every { settings.numberOfAppLaunches } returns 3
        every { settings.showWallpaperOnboarding } returns false

        assertFalse(settings.showWallpaperOnboardingDialog(true))
    }
}
