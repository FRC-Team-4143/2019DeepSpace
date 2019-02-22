#include "commands/PreviousTargetPosition.h"
#include "Modules/Height.h"
#include "Robot.h"

PreviousTargetPosition::PreviousTargetPosition() {
  // Use Requires() here to declare subsystem dependencies
  //Requires(Robot::elevator);
}

void PreviousTargetPosition::Initialize() {

}

void PreviousTargetPosition::Execute() {
  Height::GetInstance()->PreviousPosition();  
}

bool PreviousTargetPosition::IsFinished() {
  return true;
}

void PreviousTargetPosition::End() {
  
}

void PreviousTargetPosition::Interrupted() {
  End();
}
