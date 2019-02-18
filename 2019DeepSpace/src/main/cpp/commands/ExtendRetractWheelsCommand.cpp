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
    if(Mode::IsEndGame()) {
      auto left = Robot::oi->GetLeftTrigger();
      auto right = Robot::oi->GetRightTrigger();

    if(Robot::oi->GetButtonY()){ // Extend Wheels
      Robot::climber->ExtendWheels(left, right);

    }else if(Robot::oi->GetButtonA()){ //Retract Wheels
      Robot::climber->RetractWheels(left, right);

    }else{
      Robot::climber->HoldWheels();
    }
  }
}

bool ExtendRetractWheelsCommand::IsFinished() {
  return false;
}

void ExtendRetractWheelsCommand::End() {
  if (Mode::IsEndGame()) {
    Robot::climber->HoldWheels();
  }
}

void ExtendRetractWheelsCommand::Interrupted() {
  End();
}