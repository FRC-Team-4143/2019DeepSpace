#pragma once
#include "commands/ElevatorCommand.h"
#include "frc/WPIlib.h"
using namespace frc;


class OI {
 public: 

  Joystick* driverjoystick;

  ElevatorCommand* elevatorMotor;

//======= OI Methods =======//
  OI();
  float GetLeftTrigger();
  float GetRightTrigger();
  void ButtonPressed();
};
