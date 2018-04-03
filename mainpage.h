/*! \mainpage Robot Simulation Project
 *
 * \Introduction
 *
 * Robot Simulation Project is a 2d game that uses nanogui and mingfx to generate a robot that fights obstacles and rests at bases. The project follows a MVC paradigm. There are 2 primary components: the robot viewer and robot land. Robots live in robot land and are quite oblivious to being viewed by the viewer. The viewer is in control of everything in that it sends a message to robot_land to update, meaning move the robots the appropriate amount given how much time has passed since the last update. It then gets the appropriate positional information from each robot and draws these to the screen. All the while, the system is listening for keyboard and mouse activity by the user. If any action occurs, the associated callback is executed.
 *
 * You can browse through the documentation by clicking on classes and invidually selecting which class you want to see.
 */
