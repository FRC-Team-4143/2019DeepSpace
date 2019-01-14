#include "commands/ElevatorCommand.h"

#include "Robot.h"

ElevatorCommand::ElevatorCommand() {
  // Use Requires() here to declare subsystem dependencies
  Requires(Robot::elevator);
}

void ElevatorCommand::Initialize() {}

void ElevatorCommand::Execute() {
  if(Robot::oi->GetRightTrigger() > 0){
    Robot::elevator->ElevatorUp(Robot::oi->GetRightTrigger());
  } else{
    Robot::elevator->ElevatorDown(Robot::oi->GetLeftTrigger());
  }
  
}

bool ElevatorCommand::IsFinished() { return false; }

void ElevatorCommand::End() {
  Robot::elevator->ElevatorStop();
}

void ElevatorCommand::Interrupted() {
  End();
}