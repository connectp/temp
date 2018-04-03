/**
 * @file motion_handler_obstacle.cc
 *
 * @copyright 2018 3081 Staff, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/motion_handler_obstacle.h"
#include "src/motion_behavior_differential.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
// @TODO add clamped

void MotionHandlerObstacle::TurnLeft() {}

void MotionHandlerObstacle::TurnRight() {}

void MotionHandlerObstacle::Stop() {
  set_velocity(
    0.0,
    0.0);
}


void MotionHandlerObstacle::IncreaseSpeed() {}

void MotionHandlerObstacle::DecreaseSpeed() {}

void MotionHandlerObstacle::UpdateVelocity() {
  if (entity_->get_touch_sensor()->get_output()) {
    entity_->RelativeChangeHeading(+180);
  }
  int collision_timer = get_collision_timer();
  if (collision_timer > 0) {
    entity_->RelativeChangeHeading(+9.0);
    set_collision_timer(collision_timer - 1);
    if (collision_timer == 0) {
      entity_->RelativeChangeHeading(+180);
    }
  }
}

double MotionHandlerObstacle::clamp_vel(double vel) {
  return vel;
}

NAMESPACE_END(csci3081);
