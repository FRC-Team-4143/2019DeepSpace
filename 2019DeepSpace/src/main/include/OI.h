#pragma once
#include "commands/ElevatorCommand.h"
#include "frc/WPIlib.h"
#include "commands/SetEndGame.h"
#include "commands/ToggleGameMode.h"
using namespace frc;


class OI {
 public: 

  Joystick* driverjoystick;

  ElevatorCommand* elevatorCommand;
  ToggleGameMode* toggleGameMode;
  SetEndGame* setEndGame;

//======= OI Methods =======//
  OI();
  float GetLeftTrigger();
  float GetRightTrigger();
  bool GetButtonA();
  bool GetButtonBack();
};
