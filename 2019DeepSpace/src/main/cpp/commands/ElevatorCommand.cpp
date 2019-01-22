#include "commands/ElevatorCommand.h"

#include "Robot.h"

float level1 = 1000;
float level2 = 2000;
float level3 = 3000;

ElevatorCommand::ElevatorCommand() {
  // Use Requires() here to declare subsystem dependencies
  Requires(Robot::elevator);
}

void ElevatorCommand::Initialize() {
}

void ElevatorCommand::Execute() {
  /*
  if(Robot::oi->GetRightTrigger() > 0){
    Robot::elevator->ElevatorUp(Robot::oi->GetRightTrigger());
  } else{
    Robot::elevator->ElevatorDown(Robot::oi->GetLeftTrigger());
  }
*/
}

bool ElevatorCommand::IsFinished() { return false }

void ElevatorCommand::End() {
  Robot::elevator->ElevatorStop();
}

void ElevatorCommand::Interrupted() {
  End();
}