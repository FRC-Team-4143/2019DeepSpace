#include "commands/ElevatorCommand.h"

#include "Robot.h"

ElevatorCommand::ElevatorCommand() {
  // Use Requires() here to declare subsystem dependencies
  Requires(Robot::elevator);
}
float wantedPos;

float pos1=1;
float pos2=2;
float pos3=3;

int posNum=0;

float motorSpeed=1;

void ElevatorCommand::Initialize() {
  if(posNum==3)
  {
    posNum = 0;
  }

  posNum = posNum + 1;

  switch(posNum)
  {
    case 1:
    {
      wantedPos = pos1;
      break;
    }
    case 2:
    {
      wantedPos = pos2;
      break;
    }
    case 3:
    {
      wantedPos = pos3;
      break;
    }
  }
}

void ElevatorCommand::Execute() {
  if(Robot::oi->GetRightTrigger() > 0){
    Robot::elevator->ElevatorUp(Robot::oi->GetRightTrigger());
  } else{
    Robot::elevator->ElevatorDown(Robot::oi->GetLeftTrigger());
  }
  
  double pos = Robot::elevatorMotor->GetEncoder().GetPosition();
  
  if(pos < wantedPos)
  {
    Robot::elevator->ElevatorUp(motorSpeed);
  } else if(pos > wantedPos)
  {
    Robot::elevator->ElevatorDown(motorSpeed);
  }
}

bool ElevatorCommand::IsFinished() { return false; }

void ElevatorCommand::End() {
  Robot::elevator->ElevatorStop();
}

void ElevatorCommand::Interrupted() {
  End();
}