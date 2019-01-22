#pragma once

#include "frc/WPIlib.h"
using namespace frc;


class OI {
 public: 

  Joystick* driverjoystick;

//======= OI Methods =======//
  OI();
  float GetLeftTrigger();
  float GetRightTrigger();
  bool GetJoystickButtonA();
};
