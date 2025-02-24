/* Any copyright is dedicated to the Public Domain.
   http://creativecommons.org/publicdomain/zero/1.0/ */
/* eslint no-unused-vars: [2, {"vars": "local", "args": "none"}] */
/* import-globals-from head.js */

"use strict";

/**
 * Helper methods for the HTMLTooltip integration tests.
 */

const HTML_NS = "http://www.w3.org/1999/xhtml";
const {
  editableField,
} = require("resource://devtools/client/shared/inplace-editor.js");
const { colorUtils } = require("resource://devtools/shared/css/color.js");

/**
 * Create an inplace editor linked to a span element and click on the span to
 * to turn to edit mode.
 *
 * @param {Object} options
 *        Options passed to the InplaceEditor/editableField constructor.
 * @param {Document} doc
 *        Document where the span element will be created.
 * @param {String} textContent
 *        (optional) String that will be used as the text content of the span.
 */
const createInplaceEditorAndClick = async function (options, doc, textContent) {
  const span = (options.element = createSpan(doc));
  if (textContent) {
    span.textContent = textContent;
  }

  info("Creating an inplace-editor field");
  editableField(options);

  info("Clicking on the inplace-editor field to turn to edit mode");
  span.click();
};

/**
 * Helper to create a span in the provided document.
 *
 * @param {Document} doc
 *        Document where the span element will be created.
 * @return {Element} the created span element.
 */
function createSpan(doc) {
  info("Creating a new span element");
  const div = doc.createElementNS(HTML_NS, "div");
  const span = doc.createElementNS(HTML_NS, "span");
  span.setAttribute("tabindex", "0");
  span.style.fontSize = "11px";
  span.style.display = "inline-block";
  span.style.width = "100px";
  span.style.border = "1px solid red";
  span.style.fontFamily = "monospace";

  div.style.height = "100%";
  div.style.position = "absolute";
  div.appendChild(span);

  const parent = doc.querySelector("window") || doc.body;
  parent.appendChild(div);
  return span;
}

/**
 * Test helper simulating a key event in an InplaceEditor and checking that the
 * autocompletion works as expected.
 *
 * @param {Array} testData
 *        - {String|Object} key, the key to send. An object can be passed with a `key` property.
 *                          The other properties will be the options for the event (e.g. `shiftKey`)
 *        - {String} completion, the expected value of the auto-completion
 *        - {Number} index, the index of the selected suggestion in the popup
 *        - {Number|Array} items, the number of suggestions in the popup, or, alternatively
 *                         an array of the items label
 *        - {String} postLabel, the expected post label for the selected suggestion
 *        - {Boolean} colorSwatch, if there is a swatch of color expected to be visible
 *        - {Boolean} noSuggestion, true if the keypress doesn't trigger an "after-suggest" event
 * @param {InplaceEditor} editor
 *        The InplaceEditor instance being tested
 */
async function testCompletion(
  [key, completion, index, items, postLabel, colorSwatch, noSuggestion],
  editor
) {
  let eventOptions = {};
  if (typeof key === "object") {
    ({ key, ...eventOptions } = key);
  }

  info(`Pressing key <${key}> | options: ${JSON.stringify(eventOptions)}`);
  info("Expecting " + completion);

  let onVisibilityChange = null;
  const total = Array.isArray(items) ? items.length : items;
  const open = total > 0;
  if (editor.popup.isOpen != open) {
    onVisibilityChange = editor.popup.once(
      open ? "popup-opened" : "popup-closed"
    );
  }

  let onSuggest;
  if (/(left|right|back_space|escape)/gi.test(key) || noSuggestion) {
    info("Waiting for next keypress event");
    onSuggest = once(editor.input, "keypress");
  } else {
    info("Waiting for after-suggest event on the editor");
    onSuggest = editor.once("after-suggest");
  }

  info("Synthesizing key " + key);
  EventUtils.synthesizeKey(key, eventOptions, editor.input.defaultView);

  await onSuggest;
  await onVisibilityChange;
  await waitForTime(5);

  info("Checking the state");
  if (completion !== null) {
    is(editor.input.value, completion, "Correct value is autocompleted");
  }

  if (postLabel) {
    const selectedItem = editor.popup.getItems()[index];
    const selectedElement = editor.popup.elements.get(selectedItem);
    ok(
      selectedElement.textContent.includes(postLabel),
      "Selected popup element contains the expected post-label"
    );

    // Determines if there is a color swatch attached to the label
    // and if the color swatch's background color matches the post label
    const swatchSpan = selectedElement.getElementsByClassName(
      "autocomplete-swatch autocomplete-colorswatch"
    );
    if (colorSwatch) {
      Assert.strictEqual(
        swatchSpan.length,
        1,
        "Displayed the expected color swatch"
      );
      const color = new colorUtils.CssColor(
        swatchSpan[0].style.backgroundColor
      );
      const swatchColor = color.rgba;
      const postColor = new colorUtils.CssColor(postLabel).rgba;
      Assert.equal(
        swatchColor,
        postColor,
        "Color swatch matches postLabel value"
      );
    } else {
      Assert.strictEqual(
        swatchSpan.length,
        0,
        "As expected no swatches were available"
      );
    }
  }

  if (total === 0) {
    ok(!(editor.popup && editor.popup.isOpen), "Popup is closed");
  } else {
    ok(editor.popup.isOpen, "Popup is open");
    const popupItems = editor.popup.getItems();
    if (Array.isArray(items)) {
      Assert.deepEqual(
        popupItems.map(item => item.label),
        items,
        "Suggestions match"
      );
    } else {
      is(
        popupItems.length,
        total,
        "Number of suggestions match" +
          (popupItems.length !== total
            ? ` - got ${JSON.stringify(popupItems.map(item => item.label))}`
            : "")
      );
    }
    is(editor.popup.selectedIndex, index, "Expected item is selected");
  }
}
