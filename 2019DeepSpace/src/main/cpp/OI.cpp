/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "OI.h"
//#include "commands/ArmInCommand.h"
//#include "commands/ArmOutCommand.h"
#include <frc/WPILib.h>

const uint32_t JOYSTICK_LX_AXIS = 0;
const uint32_t JOYSTICK_LY_AXIS = 1;
const uint32_t JOYSTICK_LTRIG_AXIS = 2;
const uint32_t JOYSTICK_RTRIG_AXIS = 3;
const uint32_t JOYSTICK_RX_AXIS = 4;
const uint32_t JOYSTICK_RY_AXIS = 5;

const uint32_t JOYSTICK_BUTTON_A = 1;
const uint32_t JOYSTICK_BUTTON_B = 2;
const uint32_t JOYSTICK_BUTTON_X = 3;
const uint32_t JOYSTICK_BUTTON_Y = 4;
const uint32_t JOYSTICK_BUTTON_LB = 5;
const uint32_t JOYSTICK_BUTTON_RB = 6;
const uint32_t JOYSTICK_BUTTON_BACK = 7;
const uint32_t JOYSTICK_BUTTON_START = 8;
const uint32_t JOYSTICK_BUTTON_LEFT = 9;
const uint32_t JOYSTICK_BUTTON_RIGHT = 10;
const float JOYSTICK_DEAD_ZONE = 0.1;

OI::OI() {
  driverjoystick = new Joystick(0);
  /*armIn = new ArmInCommand();
  armOut = new ArmOutCommand();

  (new JoystickButton(driverjoystick, JOYSTICK_BUTTON_B))->WhileHeld(armIn);
  (new JoystickButton(driverjoystick, JOYSTICK_BUTTON_X))->WhileHeld(armOut);
  */
  // Process operator interface input here.
}
/*

float OI::RightJoystickY(){
  float value = driverjoystick->GetRawAxis(JOYSTICK_RY_AXIS);
  return (fabs(value) > JOYSTICK_DEAD_ZONE) ? -value : 0;
}

float OI::LeftJoystickY(){
  float value = driverjoystick->GetRawAxis(JOYSTICK_LY_AXIS);
  return (fabs(value) > JOYSTICK_DEAD_ZONE) ? -value : 0;
} */

float OI::LeftTrigger(){
  float value = driverjoystick->GetRawAxis(JOYSTICK_LTRIG_AXIS);
  return (fabs(value) > JOYSTICK_DEAD_ZONE) ? value :0;
}
float OI::RightTrigger(){
  float value = driverjoystick->GetRawAxis(JOYSTICK_RTRIG_AXIS);
  return (fabs(value) > JOYSTICK_DEAD_ZONE) ? value :0;
}
