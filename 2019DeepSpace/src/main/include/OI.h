#pragma once
#include "commands/ElevatorCommand.h"
#include "frc/WPIlib.h"
#include "commands/ElevatorMode.h"
using namespace frc;


class OI {
 public: 

  Joystick* driverjoystick;

  ElevatorCommand* elevatorCommand;
  ElevatorMode* elevatorMode;

//======= OI Methods =======//
  OI();
  float GetLeftTrigger();
  float GetRightTrigger();
  bool GetButtonA();
  bool GetButtonBack();
};
