#include "commands/RetractWheelsCommand.h"
#include "Robot.h"

RetractWheelsCommand::RetractWheelsCommand() {
  // Use Requires() here to declare subsystem dependencies
  Requires(Robot::climber);
}


void RetractWheelsCommand::Initialize() {
}

void RetractWheelsCommand::Execute() {
  if(Robot::oi->GetLeftBumper() && !Robot::oi->GetRightBumper()){
    Robot::climber->RetractWheels('F', 0.25);
  }else if(Robot::oi->GetRightBumper() && !Robot::oi->GetLeftBumper()){
    Robot::climber->RetractWheels('R', 0.25);
  }else if(Robot::oi->GetRightBumper() && Robot::oi->GetLeftBumper()){
    Robot::climber->RetractWheels('B', 0.25);
  }
}

bool RetractWheelsCommand::IsFinished() { return true; }

void RetractWheelsCommand::End() {
  Robot::climber->HoldWheels();
}

void RetractWheelsCommand::Interrupted() {
  End();
}