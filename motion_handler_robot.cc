/**
 * @file motion_handler_robot.cc
 *
 * @copyright 2018 3081 Staff, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/motion_handler_robot.h"
#include "src/motion_behavior_differential.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
// @TODO add clamped

void MotionHandlerRobot::TurnLeft() {
  set_velocity(
    get_velocity().left  - get_angle_delta(),
    get_velocity().right + get_angle_delta());
}

void MotionHandlerRobot::TurnRight() {
  set_velocity(
    get_velocity().left  + get_angle_delta(),
    get_velocity().right - get_angle_delta());
}

void MotionHandlerRobot::Stop() {
  set_velocity(
    0.0,
    0.0);
}

void MotionHandlerRobot::IncreaseSpeed() {
  if ((get_velocity().left <= (ROBOT_MAX_SPEED - ROBOT_SPEED_DELTA)) &&
  (get_velocity().right <= (ROBOT_MAX_SPEED - ROBOT_SPEED_DELTA))) {
    set_velocity(
      get_velocity().left  + get_speed_delta(),
      get_velocity().right + get_speed_delta());
  }
}

void MotionHandlerRobot::DecreaseSpeed() {
  if ((get_velocity().left >= ROBOT_SPEED_DELTA) &&
  (get_velocity().right >= ROBOT_SPEED_DELTA)) {
    set_velocity(
      get_velocity().left  - get_speed_delta(),
      get_velocity().right - get_speed_delta());
  }
}

void MotionHandlerRobot::UpdateVelocity() {
  if (entity_->get_touch_sensor()->get_output()) {
    entity_->RelativeChangeHeading(+180);
  }
}

double MotionHandlerRobot::clamp_vel(double vel) {
  // @TODO: don't go backwards
  double clamped = 0.0;
  if (vel > 0) {
    clamped = (vel > get_max_speed()) ?
              get_max_speed():
              vel;
  } else {
    clamped = (vel < -get_max_speed()) ?
              -get_max_speed():
              vel;
  }
  return clamped;
} /* clamp_vel() */

NAMESPACE_END(csci3081);
