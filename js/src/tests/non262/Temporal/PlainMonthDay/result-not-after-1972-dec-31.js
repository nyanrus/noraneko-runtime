// |reftest| shell-option(--enable-temporal) skip-if(!this.hasOwnProperty("Temporal"))

const monthCodes = [
  "M01",
  "M02",
  "M03",
  "M04",
  "M05",
  "M06",
  "M07",
  "M08",
  "M09",
  "M10",
  "M11",
  "M12",

  // Short epagomenal month.
  "M13",

  // Leap months.
  "M01L",
  "M02L",
  "M03L",
  "M04L",
  "M05L",
  "M06L",
  "M07L",
  "M08L",
  "M09L",
  "M10L",
  "M11L",
  "M12L",
];

// Chinese and Dangi are excluded to avoid unnecessary slow-downs, see also
// from-chinese*.js tests.
const calendars = [
  "buddhist",
  // "chinese",
  "coptic",
  // "dangi",
  "ethiopic",
  "ethioaa",
  "gregory",
  "hebrew",
  "indian",
  // Islamic calendars are broken in ICU4X 1.5.
  // https://github.com/unicode-org/icu4x/issues/5069
  // "islamic",
  "islamic-civil",
  // "islamic-rgsa",
  "islamic-tbla",
  // "islamic-umalqura",
  "japanese",
  "persian",
  "roc",
];

for (let calendar of calendars) {
  const day = 31;
  for (let monthCode of monthCodes) {
    let pmd;
    try {
      pmd = Temporal.PlainMonthDay.from({calendar, monthCode, day});
    } catch {
      continue;
    }
    assertEq(pmd.monthCode, monthCode);
    assertEq(pmd.day <= day, true);
    assertEq(ISOFields(pmd).isoYear <= 1972, true);
  }
}

if (typeof reportCompare === "function")
  reportCompare(true, true);
