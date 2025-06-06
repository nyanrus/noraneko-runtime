// |reftest| shell-option(--enable-temporal) skip-if(!this.hasOwnProperty('Temporal')||!xulRuntime.shell) -- Temporal is not enabled unconditionally, requires shell-options
// Copyright (C) 2024 Igalia, S.L. All rights reserved.
// This code is governed by the BSD license found in the LICENSE file.

/*---
esid: sec-temporal.plaindate.prototype.weekofyear
description: >
  In the ISO 8601 week calendar, calendar week number 1 of a calendar year is 
  the week including the first Thursday of that year (based on the principle 
  that a week belongs to the same calendar year as the majority of its calendar 
  days). Because of this, some calendar days of the first calendar week of a 
  calendar year may be part of the preceding date calendar year, and some 
  calendar days of the last calendar week of a calendar year may be part of
  the next calendar year.
features: [Temporal]
---*/

// 

let calendar = "gregory";
const date = new Temporal.PlainDate(2021, 1, 1, calendar);

assert.sameValue(date.weekOfYear, 1);

calendar = "iso8601";
const isodate = new Temporal.PlainDate(2021, 1, 1, calendar);

assert.sameValue(isodate.weekOfYear, 53);

reportCompare(0, 0);
