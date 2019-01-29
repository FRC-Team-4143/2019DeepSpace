#pragma once
#include "commands/ElevatorCommand.h"
#include "frc/WPIlib.h"
#include "commands/SetEndGame.h"
#include "commands/ToggleGameMode.h"
#include "commands/ExtendWheelsCommand.h"
#include "commands/RetractWheelsCommand.h"
using namespace frc;


class OI {
 public: 

  Joystick* driverjoystick;

  ElevatorCommand* elevatorCommand;
  ToggleGameMode* toggleGameMode;
  SetEndGame* setEndGame;
  ExtendWheelsCommand* extendWheelsCommand;
  RetractWheelsCommand* retractWheelsCommand;

//======= OI Methods =======//
  OI();
  float GetLeftTrigger();
  float GetRightTrigger();
  bool GetButtonA();
  bool GetButtonBack();
  bool GetRightBumper();
  bool GetLeftBumper();
};
