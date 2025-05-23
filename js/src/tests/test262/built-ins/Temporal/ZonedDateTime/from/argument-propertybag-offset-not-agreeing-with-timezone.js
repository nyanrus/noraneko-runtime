// |reftest| shell-option(--enable-temporal) skip-if(!this.hasOwnProperty('Temporal')||!xulRuntime.shell) -- Temporal is not enabled unconditionally, requires shell-options
// Copyright (C) 2022 Igalia, S.L. All rights reserved.
// This code is governed by the BSD license found in the LICENSE file.

/*---
esid: sec-temporal.zoneddatetime.from
description: Property bag with offset property is rejected if offset does not agree with time zone
features: [Temporal]
---*/

const timeZone = "+01:00";

const properties = { year: 2021, month: 10, day: 28, offset: "-07:00", timeZone };
assert.throws(RangeError, () => Temporal.ZonedDateTime.from(properties), "offset property not matching time zone is rejected");
assert.throws(RangeError, () => Temporal.ZonedDateTime.from(properties, { offset: "reject" }), "offset property not matching time zone is rejected");

reportCompare(0, 0);
