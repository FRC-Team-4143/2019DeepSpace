#include "OI.h"
#include <frc/WPILib.h>
#include <iostream>
#include "modules/Constants.H"

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

ElevatorCommand* elevatorCommand;
ToggleGameMode* toggleGameMode;
SetEndGame* setEndGame;
ExtendWheelsCommand* extendWheelsCommand;
RetractWheelsCommand* retractWheelsCommand;
AcquireGamePiece* acquireGamePiece;
EjectGamePiece* ejectGamePiece;
HatchServo* hatchServo;
ZeroYaw* zeroYaw;
CrabDrive* crabDrive;

OI::OI() {

  driverjoystick = new Joystick(0);
  elevatorCommand = new ElevatorCommand();
  toggleGameMode = new ToggleGameMode();
  setEndGame = new SetEndGame();
  extendWheelsCommand = new ExtendWheelsCommand();
  retractWheelsCommand = new RetractWheelsCommand();
  ejectGamePiece = new EjectGamePiece();
  acquireGamePiece = new AcquireGamePiece();
  hatchServo = new HatchServo();
  crabDrive = new CrabDrive();

  SmartDashboard::PutData("SetWheel Offsets", new SetWheelOffsets());
  SmartDashboard::PutData("Zero Yaw", new ZeroYaw());
  
  (new JoystickButton(driverjoystick, JOYSTICK_BUTTON_BACK))->WhenPressed(toggleGameMode);
  (new JoystickButton(driverjoystick, JOYSTICK_BUTTON_START))->WhenPressed(setEndGame);
  (new JoystickButton(driverjoystick, JOYSTICK_BUTTON_RB))->WhileHeld(hatchServo);
  (new JoystickButton(driverjoystick, JOYSTICK_BUTTON_Y))->WhileHeld(extendWheelsCommand);
  (new JoystickButton(driverjoystick, JOYSTICK_BUTTON_A))->WhileHeld(retractWheelsCommand);
  (new JoystickButton(driverjoystick, JOYSTICK_BUTTON_B))->WhileHeld(ejectGamePiece);
  (new JoystickButton(driverjoystick, JOYSTICK_BUTTON_X))->WhileHeld(acquireGamePiece);
  (new JoystickButton(driverjoystick,JOYSTICK_BUTTON_RIGHT))->ToggleWhenPressed(crabDrive);

}

// ==========================================================================

float OI::GetJoystickX() {
	auto value = driverjoystick->GetRawAxis(JOYSTICK_LX_AXIS);
	return (fabs(value) <= Constants::DEAD_ZONE) ? 0 : value;
}

// ==========================================================================

float OI::GetJoystickY() {
	auto value = driverjoystick->GetRawAxis(JOYSTICK_LY_AXIS);
	return (fabs(value) <= Constants::DEAD_ZONE) ? 0 : value;
}

// ==========================================================================

float OI::GetJoystickZ() {
	auto value = driverjoystick->GetRawAxis(JOYSTICK_RX_AXIS);
	return (fabs(value) <= Constants::DEAD_ZONE) ? 0 : value;
}

// ==========================================================================

float OI::GetLeftTrigger(){
  float value = driverjoystick->GetRawAxis(JOYSTICK_LTRIG_AXIS);
  return (fabs(value) > Constants::DEAD_ZONE) ? value :0;
}

// ==========================================================================

float OI::GetRightTrigger(){
  float value = driverjoystick->GetRawAxis(JOYSTICK_RTRIG_AXIS);
  return (fabs(value) > Constants::DEAD_ZONE) ? value :0;
}

// ==========================================================================

bool OI::GetButtonB(){
  auto value = driverjoystick->GetRawButton(JOYSTICK_BUTTON_B);
  return value;
}

// ==========================================================================

bool OI::GetButtonX(){
  auto value = driverjoystick->GetRawButton(JOYSTICK_BUTTON_X);
  return value;
}

// ==========================================================================

bool OI::GetButtonA(){
  auto value = driverjoystick->GetRawButton(JOYSTICK_BUTTON_A);
  return value;
}

// ==========================================================================

bool OI::GetButtonY(){
  auto value = driverjoystick->GetRawButton(JOYSTICK_BUTTON_Y);
  return value;
}

// ==========================================================================

bool OI::GetButtonAPressed(){
  auto value = driverjoystick->GetRawButtonPressed(JOYSTICK_BUTTON_A);
  return value;
}

// ==========================================================================

bool OI::GetButtonYPressed(){
  auto value = driverjoystick->GetRawButtonPressed(JOYSTICK_BUTTON_Y);
  return value;
}

// ==========================================================================

bool OI::GetButtonBack(){
  auto value = driverjoystick->GetRawButton(JOYSTICK_BUTTON_BACK);
  return value;
}

// ==========================================================================

bool OI::GetButtonStart() {
  auto value = driverjoystick->GetRawButton(JOYSTICK_BUTTON_START);
  return value;
}

// ==========================================================================

bool OI::GetRightBumper() {
  auto value = driverjoystick->GetRawButton(JOYSTICK_BUTTON_RB);
  return value;
}

// ==========================================================================

bool OI::GetLeftBumper() {
  return driverjoystick->GetRawButton(JOYSTICK_BUTTON_LB);
}

// ==========================================================================
