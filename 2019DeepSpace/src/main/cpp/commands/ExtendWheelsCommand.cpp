#include "commands/ExtendWheelsCommand.h"
#include "Robot.h"

ExtendWheelsCommand::ExtendWheelsCommand() {
  // Use Requires() here to declare subsystem dependencies
  Requires(Robot::climber);
}


void ExtendWheelsCommand::Initialize() {
}

void ExtendWheelsCommand::Execute() {
  if(Robot::oi->GetLeftBumper() == true && Robot::oi->GetRightBumper() != true){
    Robot::climber->ExtendWheels('F', 0.5);
  }else if(Robot::oi->GetRightBumper() == true && Robot::oi->GetLeftBumper() != true){
    Robot::climber->ExtendWheels('R', 0.5);
  }else if(Robot::oi->GetRightBumper() == true && Robot::oi->GetLeftBumper() == true){
    Robot::climber->ExtendWheels('B', 0.5);
  }
}

bool ExtendWheelsCommand::IsFinished() { return true; }

void ExtendWheelsCommand::End() {
  Robot::climber->HoldWheels();
}

void ExtendWheelsCommand::Interrupted() {
  End();
}