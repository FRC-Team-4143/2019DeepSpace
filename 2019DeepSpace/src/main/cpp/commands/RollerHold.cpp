#include "commands/RollerHold.h"
#include "modules/Mode.h"
#include "Robot.h"

RollerHold::RollerHold() {
  // Use Requires() here to declare subsystem dependencies
  Requires(Robot::roller);
}

void RollerHold::Initialize() {

}

void RollerHold::Execute() {
  if(Mode::IsCargoMode()){
    Robot::roller->RollerHold();
  }else{
    Robot::roller->RollerStop();
  }
}

bool RollerHold::IsFinished() {
  return false;
}

void RollerHold::End() {
    Robot::roller->RollerStop();
}

void RollerHold::Interrupted() {
  End();
}
