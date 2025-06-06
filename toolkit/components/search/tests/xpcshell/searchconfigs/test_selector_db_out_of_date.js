/* Any copyright is dedicated to the Public Domain.
   http://creativecommons.org/publicdomain/zero/1.0/ */

"use strict";

ChromeUtils.defineESModuleGetters(this, {
  RemoteSettingsWorker:
    "resource://services-settings/RemoteSettingsWorker.sys.mjs",
});

do_get_profile();

add_task(async function test_selector_db_out_of_date() {
  updateAppInfo({
    name: "firefox",
    ID: "xpcshell@tests.mozilla.org",
    version: "128",
    platformVersion: "128",
  });

  let searchConfig = RemoteSettings(SearchUtils.SETTINGS_KEY);

  // Do an initial get to pre-seed the database.
  await searchConfig.get();

  // Now clear the database and re-fill it.
  let db = searchConfig.db;
  await db.clear();
  let databaseEntries = await db.list();
  Assert.equal(databaseEntries.length, 0, "Should have cleared the database.");

  // Add a dummy record with an out-of-date last modified.
  await RemoteSettingsWorker._execute("_test_only_import", [
    "main",
    SearchUtils.SETTINGS_KEY,
    [
      {
        id: "b70edfdd-1c3f-4b7b-ab55-38cb048636c0",
        identifier: "outofdate",
        recordType: "engine",
        base: {},
        variants: [
          {
            environment: {
              allRegionsAndLocales: true,
            },
          },
        ],
        last_modified: 1606227264000,
      },
    ],
    1606227264000,
  ]);

  // Now load the configuration and check we get what we expect.
  let engineSelector = new SearchEngineSelector();

  let result = await engineSelector.fetchEngineConfiguration({
    // Use the fallback default locale/regions to get a simple list.
    locale: "default",
    region: "default",
  });

  Assert.deepEqual(
    result.engines.map(e => e.identifier),
    ["google", "bing", "ddg", "wikipedia"],
    "Should have returned the correct data."
  );
});
