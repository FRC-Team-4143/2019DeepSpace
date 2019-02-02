#include "commands/AcquireGamePiece.h"
#include "Robot.h"
#include "Modules/Mode.h"

AcquireGamePiece::AcquireGamePiece() {
  // Use Requires() here to declare subsystem dependencies
  Requires(Robot::roller);
  Requires(Robot::clamp);
}


void AcquireGamePiece::Initialize() {

  
}

void AcquireGamePiece::Execute() {
  if (Mode::IsCargoMode()){
    Robot::roller->RollerIn(1);

  }
  else if(Mode::IsHatchMode()){
    Robot::clamp->ClampOut(.25);
  }
}

bool AcquireGamePiece::IsFinished() { return true; }

void AcquireGamePiece::End() {
  Robot::roller->RollerStop();
  Robot::clamp->ClampStop();
}

void AcquireGamePiece::Interrupted() {
  End();
}