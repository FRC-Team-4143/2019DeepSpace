#include "commands/ExtendRetractWheelsCommand.h"
#include "Robot.h"
#include "modules/Mode.h"
#include <iostream>

ExtendRetractWheelsCommand::ExtendRetractWheelsCommand() {
  // Use Requires() here to declare subsystem dependencies
  Requires(Robot::climber);
}


void ExtendRetractWheelsCommand::Initialize() {
  
}

void ExtendRetractWheelsCommand::Execute() {
  if(Mode::IsEndGame()){
    auto left = Robot::oi->GetLeftBumper();
    auto right = Robot::oi->GetRightBumper();

    if(Robot::oi->GetButtonY()){ // Extend Wheels
      if(left && !right){
        Robot::climber->ExtendWheels('F', 0.25);
      }else if(right && !left){
        Robot::climber->ExtendWheels('R', 0.25);
      }else if(left && right){
        Robot::climber->ExtendWheels('B', 0.25);
      }else {
        Robot::climber->HoldWheels();
      }

    }else if(Robot::oi->GetButtonA()){ //Retract Wheels
      if(left && !right){
        Robot::climber->ExtendWheels('F', 0.25);
      }else if(right && !left){
        Robot::climber->ExtendWheels('R', 0.25);
      }else if(left && right){
        Robot::climber->ExtendWheels('B', 0.25);
      }else {
        Robot::climber->HoldWheels();
      }
    }else{
      Robot::climber->HoldWheels();
    }
  }
}

bool ExtendRetractWheelsCommand::IsFinished() { return false; }

void ExtendRetractWheelsCommand::End() {
  if(Mode::IsEndGame()){
    Robot::climber->HoldWheels();
  }
}

void ExtendRetractWheelsCommand::Interrupted() {
  End();
}