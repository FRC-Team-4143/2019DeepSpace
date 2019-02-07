#include "OI.h"
#include <frc/WPILib.h>
#include <iostream>

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
const float JOYSTICK_DEAD_ZONE = 0.1;

ElevatorCommand* elevatorCommand;
ToggleGameMode* toggleGameMode;
SetEndGame* setEndGame;
ExtendWheelsCommand* extendWheelsCommand;
RetractWheelsCommand* retractWheelsCommand;
AcquireGamePiece* acquireGamePiece;
EjectGamePiece* ejectGamePiece;
HatchServo* hacthServo;


OI::OI() {
  std::cout << "OI constructor" << std::endl;
  std::cout.flush();
  driverjoystick = new Joystick(0);
  elevatorCommand = new ElevatorCommand();
  toggleGameMode = new ToggleGameMode();
  setEndGame = new SetEndGame();
  extendWheelsCommand = new ExtendWheelsCommand();
  retractWheelsCommand = new RetractWheelsCommand();
  ejectGamePiece = new EjectGamePiece();
  acquireGamePiece = new AcquireGamePiece();
  hacthServo = new HatchServo();

  
  (new JoystickButton(driverjoystick, JOYSTICK_BUTTON_BACK))->WhenPressed(toggleGameMode);
  (new JoystickButton(driverjoystick, JOYSTICK_BUTTON_START))->WhenPressed(setEndGame);
  (new JoystickButton(driverjoystick, JOYSTICK_BUTTON_RB))->WhileHeld(hacthServo);
  //(new JoystickButton(driverjoystick, JOYSTICK_BUTTON_Y))->WhileHeld(extendWheelsCommand);
  //(new JoystickButton(driverjoystick, JOYSTICK_BUTTON_A))->WhileHeld(retractWheelsCommand);
  //(new JoystickButton(driverjoystick, JOYSTICK_BUTTON_B))->WhileHeld(ejectGamePiece);
  //(new JoystickButton(driverjoystick, JOYSTICK_BUTTON_X))->WhileHeld(acquireGamePiece);

}

float OI::GetLeftTrigger(){
  float value = driverjoystick->GetRawAxis(JOYSTICK_LTRIG_AXIS);
  return (fabs(value) > JOYSTICK_DEAD_ZONE) ? value :0;
}
float OI::GetRightTrigger(){
  float value = driverjoystick->GetRawAxis(JOYSTICK_RTRIG_AXIS);
  return (fabs(value) > JOYSTICK_DEAD_ZONE) ? value :0;
}
bool OI::GetButtonB(){
  auto value = driverjoystick->GetRawButton(JOYSTICK_BUTTON_B);
  return value;
}

bool OI::GetButtonX(){
  auto value = driverjoystick->GetRawButton(JOYSTICK_BUTTON_X);
  return value;
}

bool OI::GetButtonA(){
  auto value = driverjoystick->GetRawButton(JOYSTICK_BUTTON_A);
  return value;
}

bool OI::GetButtonY(){
  auto value = driverjoystick->GetRawButton(JOYSTICK_BUTTON_Y);
  return value;
}

bool OI::GetButtonAPressed(){
  auto value = driverjoystick->GetRawButtonPressed(JOYSTICK_BUTTON_A);
  return value;
}

bool OI::GetButtonYPressed(){
  auto value = driverjoystick->GetRawButtonPressed(JOYSTICK_BUTTON_Y);
  return value;
}

bool OI::GetButtonBack(){
  auto value = driverjoystick->GetRawButton(JOYSTICK_BUTTON_BACK);
  return value;
}

bool OI::GetButtonStart() {
  auto value = driverjoystick->GetRawButton(JOYSTICK_BUTTON_START);
  return value;
}

bool OI::GetRightBumper() {
  auto value = driverjoystick->GetRawButton(JOYSTICK_BUTTON_RB);
  return value;
}

bool OI::GetLeftBumper() {
  return driverjoystick->GetRawButton(JOYSTICK_BUTTON_LB);
}

float OI::GetLJoystickY(){
  auto value = driverjoystick->GetRawAxis(JOYSTICK_LY_AXIS);
  return (fabs(value) > JOYSTICK_DEAD_ZONE) ? value : 0;  
}