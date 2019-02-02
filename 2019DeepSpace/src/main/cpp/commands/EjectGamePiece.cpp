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
    Robot::roller->RollerOut(1);
  }
  else if(Mode::IsHatchMode()){
    Robot::clamp->ClampIn(.5);
  }
}

bool EjectGamePiece::IsFinished() { return true; }

void EjectGamePiece::End() {
  Robot::roller->RollerStop();
  Robot::clamp->ClampStop();
}

void EjectGamePiece::Interrupted() {
  End();
}