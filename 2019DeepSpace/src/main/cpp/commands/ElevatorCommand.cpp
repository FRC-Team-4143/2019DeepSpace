#include "commands/ElevatorCommand.h"

#include "Robot.h"

ElevatorCommand::ElevatorCommand() {
  // Use Requires() here to declare subsystem dependencies
  Requires(Robot::elevator);
}

void ElevatorCommand::Initialize() {}

void ElevatorCommand::Execute() {
  if(Robot::oi.RightTrigger() > 0){
    Robot::elevator->ElevatorUp(Robot::oi.RightTrigger());
  } else{
    Robot::elevator->ElevatorDown(Robot::oi.LeftTrigger());
  }
  
}

bool ElevatorCommand::IsFinished() { return false; }

void ElevatorCommand::End() {
  Robot::elevator->ElevatorUp(0);
  Robot::elevator->ElevatorDown(0);
}

void ElevatorCommand::Interrupted() {
  End();
}