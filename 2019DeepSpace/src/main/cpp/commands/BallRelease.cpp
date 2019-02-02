#include "commands/BallRelease.h"
#include "Robot.h"
#include "Modules/Mode.h"

BallRelease::BallRelease() {
  // Use Requires() here to declare subsystem dependencies
  Requires(Robot::roller);
}


void BallRelease::Initialize() {

  
}

void BallRelease::Execute() {
  if (Mode::IsCargoMode()==true){
    Robot::roller->RollerOut(1);

  }
}

bool BallRelease::IsFinished() { return true; }

void BallRelease::End() {
Robot::roller->RollerStop();
}

void BallRelease::Interrupted() {
  End();
}