/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

"use strict";

const Targets = require("resource://devtools/server/actors/targets/index.js");

const {
  STATES: THREAD_STATES,
} = require("resource://devtools/server/actors/thread.js");

/**
 * Start watching for all JS sources related to a given Target Actor.
 * This will notify about existing sources, but also the ones created in future.
 *
 * @param TargetActor targetActor
 *        The target actor from which we should observe sources
 * @param Object options
 *        Dictionary object with following attributes:
 *        - onAvailable: mandatory function
 *          This will be called for each resource.
 */
class SourceWatcher {
  constructor() {
    this.onNewSource = this.onNewSource.bind(this);
  }

  async watch(targetActor, { onAvailable }) {
    // The Browser Toolbox uses the Content Process target's Thread actor to debug all scripts
    // running into a given process. This includes WindowGlobal scripts.
    // Because of this, and in such configuration, we have to ignore the WindowGlobal targets.
    if (
      targetActor.sessionContext.type == "all" &&
      !targetActor.sessionContext.enableWindowGlobalThreadActors &&
      targetActor.targetType === Targets.TYPES.FRAME &&
      targetActor.typeName != "parentProcessTarget"
    ) {
      return;
    }

    const { threadActor } = targetActor;
    this.sourcesManager = targetActor.sourcesManager;
    this.onAvailable = onAvailable;

    threadActor.attach({});

    // Disable `ThreadActor.newSource` RDP event in order to avoid unnecessary traffic
    threadActor.disableNewSourceEvents();

    threadActor.sourcesManager.on("newSource", this.onNewSource);

    // For WindowGlobal, Content process and Service Worker targets,
    // the thread actor is fully managed by the server codebase.
    // For these targets, the actor should be "attached" (initialized) right away in order
    // to start observing the sources.
    //
    // For regular and shared Workers, the thread actor is still managed by the client.
    // The client will call `attach` (bug 1691986) later, which will also resume worker execution.
    const isTargetCreation = threadActor.state == THREAD_STATES.DETACHED;
    const { targetType } = targetActor;
    if (
      isTargetCreation &&
      targetType != Targets.TYPES.WORKER &&
      targetType != Targets.TYPES.SHARED_WORKER
    ) {
      await threadActor.attach({});
    }

    // Before fetching all sources, process existing ones.
    // The ThreadActor is already up and running before this code runs
    // and have sources already registered and for which newSource event already fired.
    const sources = [];
    for (const sourceActor of threadActor.sourcesManager.iter()) {
      const resource = sourceActor.form();
      sources.push(resource);
    }
    onAvailable(sources);

    // Requesting all sources should end up emitting newSource on threadActor.sourcesManager
    threadActor.addAllSources();
  }

  /**
   * Stop watching for sources
   */
  destroy() {
    if (this.sourcesManager) {
      this.sourcesManager.off("newSource", this.onNewSource);
    }
  }

  onNewSource(source) {
    const resource = source.form();
    this.onAvailable([resource]);
  }
}

module.exports = SourceWatcher;
