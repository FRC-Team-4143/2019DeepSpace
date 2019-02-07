#pragma once
#include "commands/ElevatorCommand.h"
#include "frc/WPIlib.h"
#include "commands/SetEndGame.h"
#include "commands/ToggleGameMode.h"
#include "commands/ExtendWheelsCommand.h"
#include "commands/RetractWheelsCommand.h"
#include "commands/AcquireGamePiece.h"
#include "commands/EjectGamePiece.h"
#include "commands/HatchServo.h"

using namespace frc;


class OI {
 public: 

  Joystick* driverjoystick;

  ElevatorCommand* elevatorCommand;
  ToggleGameMode* toggleGameMode;
  SetEndGame* setEndGame;
  ExtendWheelsCommand* extendWheelsCommand;
  RetractWheelsCommand* retractWheelsCommand;
  AcquireGamePiece* acquireGamePiece;
  EjectGamePiece* ejectGamePiece;
  HatchServo* hatchServo;


//======= OI Methods =======//
  OI();
  float GetLeftTrigger();
  float GetRightTrigger();
  bool GetButtonB();
  bool GetButtonX();
  bool GetButtonA();
  bool GetButtonY();
  bool GetButtonAPressed();
  bool GetButtonYPressed();
  bool GetButtonBack();
  bool GetButtonStart();
  bool GetRightBumper();
  bool GetLeftBumper();
  float GetLJoystickY();
};
