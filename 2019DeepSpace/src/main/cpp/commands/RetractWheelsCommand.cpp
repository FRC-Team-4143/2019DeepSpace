#include "commands/RetractWheelsCommand.h"
#include "Robot.h"

RetractWheelsCommand::RetractWheelsCommand() {
  // Use Requires() here to declare subsystem dependencies
  Requires(Robot::climber);
}


void RetractWheelsCommand::Initialize() {
}

void RetractWheelsCommand::Execute() {
  if(Robot::oi->GetLeftBumper() == true && Robot::oi->GetRightBumper() != true){
    Robot::climber->RetractWheels('F', 0.5);
  }else if(Robot::oi->GetRightBumper() == true && Robot::oi->GetLeftBumper() != true){
    Robot::climber->RetractWheels('R', 0.5);
  }else if(Robot::oi->GetRightBumper() == true && Robot::oi->GetLeftBumper() == true){
    Robot::climber->RetractWheels('B', 0.5);
  }
}

bool RetractWheelsCommand::IsFinished() { return true; }

void RetractWheelsCommand::End() {
  Robot::climber->HoldWheels();
}

void RetractWheelsCommand::Interrupted() {
  End();
}