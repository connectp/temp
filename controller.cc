/**
 * @file controller.cc
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <nanogui/nanogui.h>
#include <string>

#include "src/arena_params.h"
#include "src/common.h"
#include "src/controller.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

Controller::Controller() : last_dt(0) {
  // Initialize default properties for various arena entities
  arena_params aparams;
  aparams.n_obstacles = N_OBSTACLES;
  aparams.x_dim = ARENA_X_DIM;
  aparams.y_dim = ARENA_Y_DIM;
  aparams.n_bases = N_BASES;

  arena_ = new Arena(&aparams);

  // Start up the graphics (which creates the arena).
  // Run() will enter the nanogui::mainloop().
  viewer_ = new GraphicsArenaViewer(&aparams, arena_, this);
}

void Controller::Run() { viewer_->Run(); }

void Controller::AdvanceTime(double dt) {
  if ((last_dt + dt) <= .05) {
    last_dt += dt;
    return;
  }
  last_dt = 0;
  if (arena_->get_game_status() == PLAYING) {
    arena_->AdvanceTime(dt);
  }
}

void Controller::AcceptCommunication(Communication com) {
  arena_->AcceptCommand(ConvertComm(com));
}

/** Converts communication from one source to appropriate communication to
 * the other source. For example, the viewer sends a kKeyUp communication,
 * and this translates to a kIncreaseSpeed communication to Arena.
 */
/**
  * 
  */
Communication Controller::ConvertComm(Communication com) {
  // No need for break statements 'cause each case is returning a Communication
  switch (com) {
    case (kKeyUp) : return kIncreaseSpeed;
    case (kKeyDown) : return kDecreaseSpeed;
    case (kKeyLeft) : return kTurnLeft;
    case (kKeyRight) : return kTurnRight;
    case (kPlay) : return kPlay;
    case (kPause) : return kPause;
    case (kNewGame) : return kReset;
    default: return kNone;
  }
}

NAMESPACE_END(csci3081);
