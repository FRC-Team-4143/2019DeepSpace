#include "commands/SetWheelOffsets.h"
#include "Robot.h"
#include <iostream>

SetWheelOffsets::SetWheelOffsets() {
  SetRunWhenDisabled(true);
}


void SetWheelOffsets::Initialize() {
  std::cout << "SetWheelOffsets Init" << std::endl;
  std::cout.flush();
  SetTimeout(1);
  Robot::driveTrain->SetWheelOffsets();
}

void SetWheelOffsets::Execute() {
}

bool SetWheelOffsets::IsFinished() { return IsTimedOut(); }

void SetWheelOffsets::End() {
  std::cout << "SetWheelOffsets Complete" << std::endl;
  std::cout.flush();
}

void SetWheelOffsets::Interrupted() {
  End();
}