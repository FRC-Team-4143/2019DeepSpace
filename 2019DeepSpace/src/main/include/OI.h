#pragma once
#include "commands/ElevatorCommand.h"
#include "frc/WPIlib.h"
#include "commands/SetEndGame.h"
#include "commands/ToggleGameMode.h"
#include "commands/AcquireGamePiece.h"
#include "commands/EjectGamePiece.h"
#include "commands/SetWheelOffsets.h"
#include "commands/CrabDrive.h"
#include "commands/NextTargetPosition.h"
#include "commands/PreviousTargetPosition.h"
#include "commands/ElevatorManualControl.h"
#include "commands/ArmUpCommand.h"
#include "commands/ArmDownCommand.h"
#include "commands/ZeroYaw.h"
#include "commands/HatchLineUp.h"
#include "commands/SandstormHatch.h"

using namespace frc;

class OI {
 public: 

  Joystick* driverjoystick;

  AcquireGamePiece* acquireGamePiece;
  CrabDrive* crabDrive;
  EjectGamePiece* ejectGamePiece;
  NextTargetPosition* nextTargetPosition;
  PreviousTargetPosition* previousTargetPosition;
  SetEndGame* setEndGame;
  ToggleGameMode* toggleGameMode;
  ArmDownCommand* armDownCommand;
  ArmUpCommand* armUpCommand;
  HatchLineUp* hatchLineUp;

//======= OI Methods =======//
  OI();
  float GetJoystickX();
  float GetJoystickY();
  float GetJoystickZ();
  float GetRightJoystickY();
  float GetLeftTrigger();
  float GetRightTrigger();
  bool GetButtonLeft();
  bool GetButtonRight();
  bool GetButtonB();
  bool GetButtonX();
  bool GetButtonA();
  bool GetButtonY();
  bool GetButtonBack();
  bool GetButtonStart();
  bool GetRightBumper();
  bool GetLeftBumper();
};
