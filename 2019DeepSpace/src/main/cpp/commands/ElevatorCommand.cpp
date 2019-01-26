#include "commands/ElevatorCommand.h"

#include "Robot.h"

ElevatorCommand::ElevatorCommand() {
  // Use Requires() here to declare subsystem dependencies
  Requires(Robot::elevator);
}

float pos1=1000;
float pos2=2000;
float pos3=3000;

int posNum=0;

float motorSpeed=1;

float deadvalue;
double pos;

float decreaseDistance;

void ElevatorCommand::Initialize() {
  posNum = 0;

  pos1=1000;
  pos2=2000;
  pos3=3000;
  motorSpeed=1;

  deadvalue = 75;

  decreaseDistance = 200 + deadvalue;
  pos = 0;
}

void ElevatorCommand::Execute() {
  
  if(Robot::oi->GetButtonA())
  {
    if(posNum==3)
  {
    posNum = 0;
  }

  posNum = posNum + 1;

  SmartDashboard::PutNumber("Button Was Pressed, Position Number: ", posNum);

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

  SmartDashboard::PutNumber("Wanted Position: ", wantedPos);

  if(Robot::oi->GetRightTrigger() > 0){
    Robot::elevator->ElevatorUp(Robot::oi->GetRightTrigger());
  } else{
    Robot::elevator->ElevatorDown(Robot::oi->GetLeftTrigger());
  }

  
  if(Robot::elevatorMotor->GetEncoder().GetPosition()>0)
  {
    pos = Robot::elevatorMotor->GetEncoder().GetPosition();
  }
  
  float realSpeed = motorSpeed;
  if(pos < wantedPos-deadvalue)
  {
    if(pos>wantedPos-decreaseDistance)
    {
      realSpeed = motorSpeed / 4;
    }
    SmartDashboard::PutNumber("GO DOWN  ", 1);
    SmartDashboard::PutNumber("MOVE UP  ", 0);
    Robot::elevator->ElevatorUp(realSpeed);
  } else if(pos > wantedPos+deadvalue)
  {
    if(pos<wantedPos+decreaseDistance)
    {
      realSpeed = motorSpeed / 4;
    }
    SmartDashboard::PutNumber("MOVE UP  ", 1);
    SmartDashboard::PutNumber("GO DOWN  ", 0);
    Robot::elevator->ElevatorDown(realSpeed);
  }
}

bool ElevatorCommand::IsFinished() { return false; }

void ElevatorCommand::End() {
  Robot::elevator->ElevatorStop();
}

void ElevatorCommand::Interrupted() {
  End();
}