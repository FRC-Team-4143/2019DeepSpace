#include "commands/ExtendWheelsCommand.h"
#include "Robot.h"
#include <iostream>

ExtendWheelsCommand::ExtendWheelsCommand() {
  // Use Requires() here to declare subsystem dependencies
  Requires(Robot::climber);
}


void ExtendWheelsCommand::Initialize() {
  std::cout << "ExtendWheels Command" << std::endl;
  std::cout.flush();
  
}

void ExtendWheelsCommand::Execute() {
  auto left = Robot::oi->GetLeftBumper();
  auto right = Robot::oi->GetRightBumper();
  if(left && !right){
    Robot::climber->ExtendWheels('F', 0.25);
  }else if(right && !left){
    Robot::climber->ExtendWheels('R', 0.25);
  }else if(left && right){
    Robot::climber->ExtendWheels('B', 0.25);
  }else {
    Robot::climber->HoldWheels();
  }
}

bool ExtendWheelsCommand::IsFinished() { return false; }

void ExtendWheelsCommand::End() {
  std::cout << "end" << std::endl;
  std::cout.flush();
  Robot::climber->HoldWheels();
}

void ExtendWheelsCommand::Interrupted() {
  End();
}