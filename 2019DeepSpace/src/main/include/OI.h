#pragma once
#include "commands/ElevatorCommand.h"
#include "frc/WPIlib.h"
#include "commands/SetEndGame.h"
#include "commands/ToggleGameMode.h"
#include "commands/AcquireGamePiece.h"
#include "commands/EjectGamePiece.h"
#include "commands/HatchServo.h"
#include "commands/SetWheelOffsets.h"
#include "commands/ZeroYaw.h"
#include "commands/CrabDrive.h"
#include "commands/NextTargetPosition.h"
#include "commands/PreviousTargetPosition.h"
#include "commands/ElevatorManualControl.h"
#include "commands/ArmManualControl.h"

using namespace frc;


class OI {
 public: 

  Joystick* driverjoystick;

  ElevatorCommand* elevatorCommand;
  ToggleGameMode* toggleGameMode;
  SetEndGame* setEndGame;
  AcquireGamePiece* acquireGamePiece;
  EjectGamePiece* ejectGamePiece;
  HatchServo* hatchServo;
  ZeroYaw* zeroYaw;
  CrabDrive* crabDrive;
  NextTargetPosition* nextTargetPosition;
  PreviousTargetPosition* previousTargetPosition;


//======= OI Methods =======//
  OI();
  float GetJoystickX();
  float GetJoystickY();
  float GetJoystickZ();
  float GetLeftTrigger();
  float GetRightTrigger();
  bool GetButtonLeft();
  bool GetButtonB();
  bool GetButtonX();
  bool GetButtonA();
  bool GetButtonY();
  bool GetButtonBack();
  bool GetButtonStart();
  bool GetRightBumper();
  bool GetLeftBumper();
  
};
