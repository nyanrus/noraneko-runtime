/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

"use strict";

const { shallow, mount } = require("enzyme");

const {
  createFactory,
} = require("resource://devtools/client/shared/vendor/react.mjs");

const Provider = createFactory(
  require("resource://devtools/client/shared/vendor/react-redux.js").Provider
);
const {
  setupStore,
} = require("resource://devtools/client/accessibility/test/node/helpers.js");

const Badge = require("resource://devtools/client/accessibility/components/Badge.js");
const TextLabelBadgeClass = require("resource://devtools/client/accessibility/components/TextLabelBadge.js");
const TextLabelBadge = createFactory(TextLabelBadgeClass);
const {
  accessibility: { SCORES },
} = require("resource://devtools/shared/constants.js");

function testBadge(wrapper) {
  expect(wrapper.html()).toMatchSnapshot();
  expect(wrapper.children().length).toBe(1);
  const textLabelBadge = wrapper.find(TextLabelBadgeClass);
  const badge = textLabelBadge.childAt(0);
  expect(badge.type()).toBe(Badge);
  expect(badge.props()).toMatchObject({
    label: "text label",
    tooltip: "Does not meet WCAG standards for text alternative.",
  });
}

describe("TextLabelBadge component:", () => {
  const store = setupStore();

  it("error render", () => {
    const wrapper = shallow(TextLabelBadge({ error: true }));
    expect(wrapper.html()).toMatchSnapshot();
    expect(wrapper.isEmptyRender()).toBe(true);
  });

  it("fail render", () => {
    const wrapper = mount(
      Provider(
        { store },
        TextLabelBadge({
          score: SCORES.FAIL,
        })
      )
    );

    testBadge(wrapper);
  });

  it("warning render", () => {
    const wrapper = mount(
      Provider(
        { store },
        TextLabelBadge({
          score: SCORES.WARNING,
        })
      )
    );

    testBadge(wrapper);
  });

  it("best practices render", () => {
    const wrapper = mount(
      Provider(
        { store },
        TextLabelBadge({
          score: SCORES.BEST_PRACTICES,
        })
      )
    );

    testBadge(wrapper);
  });
});
