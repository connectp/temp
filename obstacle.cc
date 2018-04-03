/**
 * @file obstacle.cc
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/obstacle.h"
#include "src/params.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
Obstacle::Obstacle() : motion_handler_(this), motion_behavior_(this) {
  motion_handler_.set_velocity(1, 1);
  set_color(OBSTACLE_COLOR);
  set_pose(OBSTACLE_POSITION);
  set_radius(OBSTACLE_RADIUS);
  set_type(kObstacle);
}

void Obstacle::TimestepUpdate(unsigned int dt) {
  // Update heading as indicated by touch sensor
  motion_handler_.UpdateVelocity();

  // Use velocity and position to update position
  motion_behavior_.UpdatePose(dt, motion_handler_.get_velocity());

  // Reset Sensor for next cycle
  sensor_touch_->Reset();
}

void Obstacle::Reset() {
  set_pose(SetPoseRandomly());
  set_radius(SetRadiusRandomly());
  set_color(OBSTACLE_COLOR);
  sensor_touch_->Reset();
  motion_handler_.set_velocity(1, 1);
}

void Obstacle::HandleCollision(EntityType object_type, ArenaEntity * object) {
  motion_handler_.set_collision_timer(20);
  sensor_touch_->HandleCollision(object_type, object);
  switch (object_type) {
    case kRightWall:
    case kLeftWall:
    case kTopWall:
    case kBottomWall:
      break;
    case kRobot:
      break;
    case kBase:
      break;
    default:
      break;
  }
}


NAMESPACE_END(csci3081);
