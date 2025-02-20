// Copyright 2024 Mathias Bynens. All rights reserved.
// This code is governed by the BSD license found in the LICENSE file.

/*---
author: Mathias Bynens
description: >
  Unicode property escapes for `Script_Extensions=Ugaritic`
info: |
  Generated by https://github.com/mathiasbynens/unicode-property-escapes-tests
  Unicode v16.0.0
esid: sec-static-semantics-unicodematchproperty-p
features: [regexp-unicode-property-escapes]
includes: [regExpUtils.js]
---*/

const matchSymbols = buildString({
  loneCodePoints: [
    0x01039F
  ],
  ranges: [
    [0x010380, 0x01039D]
  ]
});
testPropertyEscapes(
  /^\p{Script_Extensions=Ugaritic}+$/u,
  matchSymbols,
  "\\p{Script_Extensions=Ugaritic}"
);
testPropertyEscapes(
  /^\p{Script_Extensions=Ugar}+$/u,
  matchSymbols,
  "\\p{Script_Extensions=Ugar}"
);
testPropertyEscapes(
  /^\p{scx=Ugaritic}+$/u,
  matchSymbols,
  "\\p{scx=Ugaritic}"
);
testPropertyEscapes(
  /^\p{scx=Ugar}+$/u,
  matchSymbols,
  "\\p{scx=Ugar}"
);

const nonMatchSymbols = buildString({
  loneCodePoints: [
    0x01039E
  ],
  ranges: [
    [0x00DC00, 0x00DFFF],
    [0x000000, 0x00DBFF],
    [0x00E000, 0x01037F],
    [0x0103A0, 0x10FFFF]
  ]
});
testPropertyEscapes(
  /^\P{Script_Extensions=Ugaritic}+$/u,
  nonMatchSymbols,
  "\\P{Script_Extensions=Ugaritic}"
);
testPropertyEscapes(
  /^\P{Script_Extensions=Ugar}+$/u,
  nonMatchSymbols,
  "\\P{Script_Extensions=Ugar}"
);
testPropertyEscapes(
  /^\P{scx=Ugaritic}+$/u,
  nonMatchSymbols,
  "\\P{scx=Ugaritic}"
);
testPropertyEscapes(
  /^\P{scx=Ugar}+$/u,
  nonMatchSymbols,
  "\\P{scx=Ugar}"
);

reportCompare(0, 0);
