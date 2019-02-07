#include "commands/HatchServo.h"
#include "Robot.h"

HatchServo::HatchServo() {
  // Use Requires() here to declare subsystem dependencies
  //Requires(Robot::climber);
}


void HatchServo::Initialize() {
}

void HatchServo::Execute() {
  Robot::hatchServo->SetAngle(60);
}

bool HatchServo::IsFinished() { return false; }

void HatchServo::End() {
  Robot::hatchServo->SetAngle(0);
}

void HatchServo::Interrupted() {
  End();
}