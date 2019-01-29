#include "OI.h"
#include <frc/WPILib.h>

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

OI::OI() {
  driverjoystick = new Joystick(0);
  elevatorCommand = new ElevatorCommand();
  toggleGameMode = new ToggleGameMode();
  setEndGame = new SetEndGame();
  
  (new JoystickButton(driverjoystick, JOYSTICK_BUTTON_BACK))->WhileHeld(toggleGameMode);
  (new JoystickButton(driverjoystick, JOYSTICK_BUTTON_START))->WhileHeld(setEndGame);

}

float OI::GetLeftTrigger(){
  float value = driverjoystick->GetRawAxis(JOYSTICK_LTRIG_AXIS);
  return (fabs(value) > JOYSTICK_DEAD_ZONE) ? value :0;
}
float OI::GetRightTrigger(){
  float value = driverjoystick->GetRawAxis(JOYSTICK_RTRIG_AXIS);
  return (fabs(value) > JOYSTICK_DEAD_ZONE) ? value :0;
}

bool OI::GetButtonA(){
  auto value = driverjoystick->GetRawButtonPressed(JOYSTICK_BUTTON_A);
  return value;
}

bool OI::GetButtonBack()
{
  auto value = driverjoystick->GetRawButtonPressed(JOYSTICK_BUTTON_BACK);
  return value;
}

bool OI::GetButtonStart()
{
  auto value = driverjoystick->GetRawButtonPressed(JOYSTICK_BUTTON_START);
  return value;
}