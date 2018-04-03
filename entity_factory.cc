/**
 * @file entity_factory.cc
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string>
#include <ctime>
#include <iostream>

#include "src/common.h"
#include "src/entity_factory.h"
#include "src/entity_type.h"
#include "src/params.h"
#include "src/pose.h"
#include "src/rgb_color.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/

EntityFactory::EntityFactory() {
  srand(time(nullptr));
}

ArenaEntity* EntityFactory::CreateEntity(EntityType etype) {
  switch (etype) {
    case (kRobot):
      return CreateRobot();
      break;
    case (kObstacle):
      return CreateObstacle();
      break;
    case (kBase):
      return CreateBase();
      break;
    default:
      std::cout << "FATAL: Bad entity type on creation\n";
      assert(false);
  }
  return nullptr;
}

Robot* EntityFactory::CreateRobot() {
  auto* robot = new Robot;
  robot->set_type(kRobot);
  robot->set_color(ROBOT_COLOR);
  robot->set_pose(SetPoseRandomly());
  robot->set_radius(ROBOT_RADIUS);
  ++entity_count_;
  ++robot_count_;
  robot->set_id(robot_count_);
  return robot;
}

double EntityFactory::SetRadiusRandomly() {
  // OBSTACLE_MIN_RAIDUS and OBSTACLE_MAX_RADIUS are available from params.h
  double val = static_cast<double>(rand());
  val /= RAND_MAX;
  return OBSTACLE_MIN_RADIUS + val*(OBSTACLE_MAX_RADIUS - OBSTACLE_MIN_RADIUS);
}

Obstacle* EntityFactory::CreateObstacle() {
  auto* obstacle = new Obstacle;
  obstacle->set_type(kObstacle);
  obstacle->set_color(OBSTACLE_COLOR);
  obstacle->set_pose(SetPoseRandomly());
  obstacle->set_radius(SetRadiusRandomly());
  ++entity_count_;
  ++obstacle_count_;
  obstacle->set_id(obstacle_count_);
  return obstacle;
}

Base* EntityFactory::CreateBase() {
  auto* base = new Base;
  base->set_type(kBase);
  base->set_color(BASE_COLOR);
  base->set_pose(SetPoseRandomly());
  base->set_radius(BASE_RADIUS);
  ++entity_count_;
  ++base_count_;
  base->set_id(base_count_);
  return base;
}

Pose EntityFactory::SetPoseRandomly() {
  // Dividing arena into 19x14 grid. Each grid square is 50x50
  return {static_cast<double>((30 + (random() % 19) * 50)),
        static_cast<double>((30 + (random() % 14) * 50))};
}

NAMESPACE_END(csci3081);
