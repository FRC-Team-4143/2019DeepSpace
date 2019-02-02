#pragma once
#include "commands/ElevatorCommand.h"
#include "frc/WPIlib.h"
#include "commands/SetEndGame.h"
#include "commands/ToggleGameMode.h"
#include "commands/ExtendWheelsCommand.h"
#include "commands/RetractWheelsCommand.h"
#include "commands/BallPickup.h"
#include "commands/BallRelease.h"
#include "commands/ClampGrab.h"
#include "commands/ClampRelease.h"

using namespace frc;


class OI {
 public: 

  Joystick* driverjoystick;

  ElevatorCommand* elevatorCommand;
  ToggleGameMode* toggleGameMode;
  SetEndGame* setEndGame;
  ExtendWheelsCommand* extendWheelsCommand;
  RetractWheelsCommand* retractWheelsCommand;
  BallPickup* ballPickup;
  BallRelease* ballRelease;
  ClampGrab* clampGrab;
  ClampRelease* clampRelease;

//======= OI Methods =======//
  OI();
  float GetLeftTrigger();
  float GetRightTrigger();
  bool GetButtonA();
  bool GetButtonBack();
  bool GetButtonStart();
  bool GetRightBumper();
  bool GetLeftBumper();
};
