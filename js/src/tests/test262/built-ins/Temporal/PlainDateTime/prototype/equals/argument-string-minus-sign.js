// |reftest| shell-option(--enable-temporal) skip-if(!this.hasOwnProperty('Temporal')||!xulRuntime.shell) -- Temporal is not enabled unconditionally, requires shell-options
// Copyright (C) 2024 Igalia, S.L. All rights reserved.
// This code is governed by the BSD license found in the LICENSE file.

/*---
esid: sec-temporal.plaindatetime.prototype.equals
description: Non-ASCII minus sign is not acceptable
features: [Temporal]
---*/

const invalidStrings = [
  "1976-11-18T15:23:30.12\u221202:00",
  "\u2212009999-11-18T15:23:30.12",
];
const instance = new Temporal.PlainDateTime(2000, 5, 2, 12, 34, 56, 987, 654, 321);
invalidStrings.forEach((arg) => {
  assert.throws(
    RangeError,
    () => instance.equals(arg),
    `variant minus sign: ${arg}`
  );
});

reportCompare(0, 0);
