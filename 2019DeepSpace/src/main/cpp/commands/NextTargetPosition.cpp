#include "commands/NextTargetPosition.h"
#include "Modules/Height.h"

#include "Robot.h"

NextTargetPosition::NextTargetPosition() {
  // Use Requires() here to declare subsystem dependencies
  //Requires(Robot::elevator);
}

void NextTargetPosition::Initialize() {

}

void NextTargetPosition::Execute() {
  Height::GetInstance()->NextPosition();  
}

bool NextTargetPosition::IsFinished() {
  return true;
}

void NextTargetPosition::End() {
  
}

void NextTargetPosition::Interrupted() {
  End();
}
