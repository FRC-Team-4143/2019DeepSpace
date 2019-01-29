#include "commands/ClampRelease.h"
#include "Robot.h"
#include "Modules/Mode.h"

ClampRelease::ClampRelease() {
  // Use Requires() here to declare subsystem dependencies
  Requires(Robot::clamp);
}


void ClampRelease::Initialize() {

  
}

void ClampRelease::Execute() {
  if (Mode::IsHatchMode()==true){
    Robot::clamp->ClampIn(.5);
  }
}

bool ClampRelease::IsFinished() { return true; }

void ClampRelease::End() {
Robot::clamp->ClampStop();
}

void ClampRelease::Interrupted() {
  End();
}