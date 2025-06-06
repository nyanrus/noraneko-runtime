// |reftest| shell-option(--enable-temporal) skip-if(!this.hasOwnProperty('Temporal')||!xulRuntime.shell) -- Temporal is not enabled unconditionally, requires shell-options
// Copyright (C) 2022 Igalia, S.L. All rights reserved.
// This code is governed by the BSD license found in the LICENSE file.

/*---
esid: sec-temporal.plaindate.prototype.toplaindatetime
description: UTC offset not valid with format that does not include a time
features: [Temporal]
includes: [temporalHelpers.js]
---*/

const instance = new Temporal.PlainDate(2000, 5, 2);

const validStrings = [
  "12:34:56.987654321+00:00",
  "12:34:56.987654321+00:00[UTC]",
  "12:34:56.987654321+00:00[!UTC]",
  "12:34:56.987654321-02:30[America/St_Johns]",
  "1976-11-18T12:34:56.987654321+00:00",
  "1976-11-18T12:34:56.987654321+00:00[UTC]",
  "1976-11-18T12:34:56.987654321+00:00[!UTC]",
  "1976-11-18T12:34:56.987654321-02:30[America/St_Johns]",
];

for (const arg of validStrings) {
  const result = instance.toPlainDateTime(arg);

  TemporalHelpers.assertPlainDateTime(
    result,
    2000, 5, "M05", 2, 12, 34, 56, 987, 654, 321,
    `"${arg}" is a valid UTC offset with time for PlainTime`
  );
}

const invalidStrings = [
  "2022-09-15Z",
  "2022-09-15Z[UTC]",
  "2022-09-15Z[Europe/Vienna]",
  "2022-09-15+00:00",
  "2022-09-15+00:00[UTC]",
  "2022-09-15-02:30",
  "2022-09-15-02:30[America/St_Johns]",
];

for (const arg of invalidStrings) {
  assert.throws(
    RangeError,
    () => instance.toPlainDateTime(arg),
    `"${arg}" UTC offset without time is not valid for PlainTime`
  );
}

reportCompare(0, 0);
