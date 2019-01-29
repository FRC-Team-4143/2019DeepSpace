#include "commands/ClampGrab.h"
#include "Robot.h"
#include "Modules/Mode.h"

ClampGrab::ClampGrab() {
  // Use Requires() here to declare subsystem dependencies
  Requires(Robot::clamp);
}


void ClampGrab::Initialize() {
  if (Mode::IsHatchMode()==true){
    Robot::clamp->ClampOut(1);
  }
}

void ClampGrab::Execute() {
  if (Mode::IsHatchMode()==true){
    Robot::clamp->ClampOut(.25);
  }
}

bool ClampGrab::IsFinished() { return true; }

void ClampGrab::End() {
Robot::clamp->ClampStop();
}

void ClampGrab::Interrupted() {
  End();
}