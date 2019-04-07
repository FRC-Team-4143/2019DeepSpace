#include "commands/PickUpPrep.h"
#include "Modules/Height.h"

#include "Robot.h"

PickUpPrep::PickUpPrep() {
  // Use Requires() here to declare subsystem dependencies
}

void PickUpPrep::Initialize() {

}

void PickUpPrep::Execute() {
  Height::GetInstance()->PickUpPiece();  
}

bool PickUpPrep::IsFinished() {
  return true;
}

void PickUpPrep::End() {
  
}

void PickUpPrep::Interrupted() {
  End();
}
