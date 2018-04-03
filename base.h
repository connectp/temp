/**
 * @file base.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_BASE_H_
#define SRC_BASE_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string>

#include "src/arena_immobile_entity.h"
#include "src/common.h"
#include "src/entity_type.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief Class representing a immobile base within the Arena.
 *
 * Base can enhance a Robot. If a Robot touches the Base, it becomes
 * a super robot.
 *
 * Base have the capability of updating their own position when asked, and
 * also track their own velocity and heading. They have a touch sensor for
 * responding to collision events which is activated/deactivated on collision
 * events.
 *
 */
class Base : public ArenaImmobileEntity {
 public:
  /**
   * @brief Constructor.
   *
   * @param params A base_params passed down from main.cc for the
   * initialization of the Base.
   */
  Base();

  /**
   * @brief Reset the Base using the initialization parameters received
   * by the constructor.
   */
  void Reset() override;

  /**
   * @brief Get the name of the Base for visualization purposes, and to
   * aid in debugging.
   *
   * @return Name of the Base.
   */
  std::string get_name() const override { return "Base"; }

  /**
   * @brief Getter for captured_, which is the state of the base
   *
   * @return true if captured.
   */
  bool IsCaptured() const { return captured_; }

  /**
   * @brief Setter for captured_, which is the state of the base
   */
  void set_captured(bool state) { captured_ = state; }

 private:
  bool captured_;
};

NAMESPACE_END(csci3081);

#endif  // SRC_BASE_H_
