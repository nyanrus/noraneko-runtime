/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

"use strict";

const {
  getAdHocFrontOrPrimitiveGrip,
  // eslint-disable-next-line mozilla/reject-some-requires
} = require("resource://devtools/client/fronts/object.js");

class ScriptCommand {
  constructor({ commands }) {
    this._commands = commands;
  }

  /**
   * Execute a JavaScript expression.
   *
   * @param {String} expression: The code you want to evaluate.
   * @param {Object} options: Options for evaluation:
   * @param {Object} options.frameActor: a FrameActor ID. The actor holds a reference to
   *        a Debugger.Frame. This option allows you to evaluate the string in the frame
   *        of the given FrameActor.
   * @param {String} options.url: the url to evaluate the script as. Defaults to "debugger eval code".
   * @param {TargetFront} options.selectedTargetFront: When passed, the expression will be
   *        evaluated in the context of the target (as opposed to the default, top-level one).
   * @param {String} options.selectedNodeActor: A NodeActor ID that may be used by helper
   *        functions that can reference the currently selected node in the Inspector, like $0.
   * @param {String} options.selectedObjectActor: the actorID of a given objectActor.
   *        This is used by context menu entries to get a reference to an object, in order
   *        to perform some operation on it (copy it, store it as a global variable, …).
   * @param {Number} options.innerWindowID: An optional window id to be used for the evaluation,
   *        instead of the regular webConsoleActor.evalWindow.
   *        This is used by functions that may want to evaluate in a different window (for
   *        example a non-remote iframe), like getting the elements of a given document.
   * @param {object} options.mapped: An optional object indicating if the original expression
   *        entered by the users have been modified
   * @param {boolean} options.mapped.await: true if the expression was a top-level await
   *        expression that was wrapped in an async-iife
   * @param {boolean} options.disableBreaks: Set to true to avoid triggering any
   *        type of breakpoint when evaluating the source. Also, the evaluated source won't be
   *        visible in the debugger UI.
   * @param {boolean} options.preferConsoleCommandsOverLocalSymbols: Set to true to force
   *        overriding local symbols defined by the page with same-name console commands.
   * @param {boolean} options.evalInTracer: Set to true to store the evaluation result object
   *        actors within the Tracer Object Actor Pool.
   *        So that if the evaluation result object has already been processed by the JS Tracer,
   *        we will receive the same Object Actor.
   *        This helps later match the object when doing a search per value.
   *
   * @return {Promise}: A promise that resolves with the response.
   */
  async execute(expression, options = {}) {
    const {
      selectedObjectActor,
      selectedNodeActor,
      frameActor,
      selectedTargetFront,
    } = options;

    // Retrieve the right WebConsole front that relates either to (by order of priority):
    // - the currently selected target in the context selector
    //   (selectedTargetFront argument),
    // - the object picked in the console (when using store as global) (selectedObjectActor),
    // - the currently selected Node in the inspector (selectedNodeActor),
    // - the currently selected frame in the debugger (when paused) (frameActor),
    // - the currently selected target in the iframe dropdown
    //   (selectedTargetFront from the TargetCommand)
    let targetFront = this._commands.targetCommand.selectedTargetFront;

    const selectedActor =
      selectedObjectActor || selectedNodeActor || frameActor;

    if (selectedTargetFront) {
      targetFront = selectedTargetFront;
    } else if (selectedActor) {
      const selectedFront = this._commands.client.getFrontByID(selectedActor);
      if (selectedFront) {
        targetFront = selectedFront.targetFront;
      }
    }

    const consoleFront = await targetFront.getFront("console");

    // We call `evaluateJSAsync` RDP request, which immediately returns a simple `resultID`,
    // for which we later receive a related `evaluationResult` RDP event, with the same resultID.
    // The evaluation result will be contained in this RDP event.
    let resultID;
    const response = await new Promise(resolve => {
      const offEvaluationResult = consoleFront.on(
        "evaluationResult",
        async packet => {
          // In some cases, the evaluationResult event can be received before the call to
          // evaluationJSAsync completes. So make sure to wait for the corresponding promise
          // before handling the evaluationResult event.
          await onEvaluateJSAsync;

          if (packet.resultID === resultID) {
            resolve(packet);
            offEvaluationResult();
          }
        }
      );

      const onEvaluateJSAsync = consoleFront
        .evaluateJSAsync({
          text: expression,
          eager: options.eager,
          frameActor,
          innerWindowID: options.innerWindowID,
          mapped: options.mapped,
          selectedNodeActor,
          selectedObjectActor,
          url: options.url,
          disableBreaks: options.disableBreaks,
          preferConsoleCommandsOverLocalSymbols:
            options.preferConsoleCommandsOverLocalSymbols,
          evalInTracer: options.evalInTracer,
        })
        .then(packet => {
          resultID = packet.resultID;
        });
    });

    // `response` is the packet sent via `evaluationResult` RDP event.
    if (response.error) {
      throw response;
    }

    if (response.result) {
      response.result = getAdHocFrontOrPrimitiveGrip(
        response.result,
        consoleFront
      );
    }

    if (response.helperResult?.object) {
      response.helperResult.object = getAdHocFrontOrPrimitiveGrip(
        response.helperResult.object,
        consoleFront
      );
    }

    if (response.exception) {
      response.exception = getAdHocFrontOrPrimitiveGrip(
        response.exception,
        consoleFront
      );
    }

    if (response.exceptionMessage) {
      response.exceptionMessage = getAdHocFrontOrPrimitiveGrip(
        response.exceptionMessage,
        consoleFront
      );
    }

    return response;
  }
}

module.exports = ScriptCommand;
