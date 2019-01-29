#include "commands/BallPickup.h"
#include "Robot.h"
#include "Modules/Mode.h"

BallPickup::BallPickup() {
  // Use Requires() here to declare subsystem dependencies
  Requires(Robot::roller);
}


void BallPickup::Initialize() {

  
}

void BallPickup::Execute() {
  if (Mode::IsCargoMode()==true){
    Robot::roller->RollerIn(1);

  }
}

bool BallPickup::IsFinished() { return true; }

void BallPickup::End() {
Robot::roller->RollerStop();
}

void BallPickup::Interrupted() {
  End();
}