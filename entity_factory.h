/**
 * @file entity_factory.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_ENTITY_FACTORY_H_
#define SRC_ENTITY_FACTORY_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string>

#include "src/base.h"
#include "src/common.h"
#include "src/entity_type.h"
#include "src/obstacle.h"
#include "src/params.h"
#include "src/pose.h"
#include "src/rgb_color.h"
#include "src/robot.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief A factory for the instantiation of all types of arena entities.
 *
 * The factory keeps track of the number of entities of each type and overall.
 * It assigns ID's to the entity when it creates it.
 * The factory randomly places entities, and in doing so, attempts to not
 * have them overlap.
 */
class EntityFactory {
 public:
  /**
   * @brief EntityFactory constructor.
   *
   */
  EntityFactory();

  /**
   * @brief Default destructor.
   */
  virtual ~EntityFactory() = default;

  /**
  * @brief CreateEntity is primary purpose of this class.
  *
  * @param[in] etype The type to make.
  * @param[out] new dynamically created entity.
  *
  * Currently, the Arena gets the entity and places it in the appropriate data
  * structure. It might be useful to instead have the factory place on the
  * appropriate data structure so that the call to Arena is the same regardless
  * of the entity type.
  */
  ArenaEntity* CreateEntity(EntityType etype);

 private:
   /**
   * @brief CreateRobot called from within CreateEntity.
   */
  Robot* CreateRobot();

  /**
  * @brief CreateObstacle called from within CreateEntity.
  */
  Obstacle* CreateObstacle();

  /**
  * @brief CreateBase called from within CreateEntity.
  */
  Base* CreateBase();

  /**
  * @brief An attempt to not overlap any of the newly constructed entities.
  */
  Pose SetPoseRandomly();

  /**
  * @brief Returns a random radius between OBSTACLE_MIN_RADIUS and OBSTACLE_MAX_RADIUS
  */
  double SetRadiusRandomly();

  /* Factory tracks the number of created entities. There is no accounting for
   * the destruction of entities */
  int entity_count_{0};
  int robot_count_{0};
  int obstacle_count_{0};
  int base_count_{0};
};

NAMESPACE_END(csci3081);

#endif /* SRC_ENTITY_FACTORY_H_ */
