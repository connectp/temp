/**
 * @file base.cc
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/base.h"
#include "src/params.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
Base::Base() : ArenaImmobileEntity(), captured_(false) {
  set_type(kBase);
  set_color(BASE_COLOR);
  set_pose(SetPoseRandomly());
  set_radius(BASE_RADIUS);
}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void Base::Reset() {
  set_pose(SetPoseRandomly());
  set_color(BASE_COLOR);
  captured_ = false;
} /* Reset */

NAMESPACE_END(csci3081);
