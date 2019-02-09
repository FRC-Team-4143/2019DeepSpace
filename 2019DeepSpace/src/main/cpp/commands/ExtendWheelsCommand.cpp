#include "commands/ExtendWheelsCommand.h"
#include "Robot.h"
#include "modules/Mode.h"
#include <iostream>

ExtendWheelsCommand::ExtendWheelsCommand() {
  // Use Requires() here to declare subsystem dependencies
  Requires(Robot::climber);
}


void ExtendWheelsCommand::Initialize() {
  
}

void ExtendWheelsCommand::Execute() {
  if(Mode::IsEndGame()){
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
}

bool ExtendWheelsCommand::IsFinished() { return false; }

void ExtendWheelsCommand::End() {
  if(Mode::IsEndGame()){
    Robot::climber->HoldWheels();
  }
}

void ExtendWheelsCommand::Interrupted() {
  End();
}