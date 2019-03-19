#include "commands/EjectGamePiece.h"
#include "Robot.h"
#include "Modules/Mode.h"

EjectGamePiece::EjectGamePiece() {
  // Use Requires() here to declare subsystem dependencies
  Requires(Robot::roller);
}


void EjectGamePiece::Initialize() {

  
}

void EjectGamePiece::Execute() {
  if (Mode::IsCargoMode()){
    if(Robot::oi->GetButtonA()){
      Robot::roller->RollerOut(0.35);
    }
    else{
      Robot::roller->RollerOut(0.60);
    }
    Robot::clamp->ClampStop();
  }
  else if(Mode::IsHatchMode()){
    Robot::clamp->ClampIn(0.2);
  }
}

bool EjectGamePiece::IsFinished() { return false; }

void EjectGamePiece::End() {
  Robot::roller->RollerStop();
  Robot::clamp->ClampStop();
}

void EjectGamePiece::Interrupted() {
  End();
}