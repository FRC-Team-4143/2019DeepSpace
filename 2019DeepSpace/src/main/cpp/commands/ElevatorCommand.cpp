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

  elevator_pos1=1000;
  elevator_pos2=2000;
  elevator_pos3=3000;
  elevator_pos4=4000;

  arm_pos1 = 100;
  arm_pos2 = 200;
  arm_pos3 = 300;
  arm_pos4 = 400;

  motorSpeed=1;

  deadvalue = 75;

  decreaseDistance = 200 + deadvalue;
  elevator_pos = 0;
  arm_pos = 0;
}

void ElevatorCommand::Execute() {
  
  if(Robot::oi->GetButtonA())
  {
  if(posNum==4)
  {
    posNum = 0;
  }

  posNum = posNum + 1;

  SmartDashboard::PutNumber("Button Was Pressed, Position Number: ", posNum);

  switch(posNum)
  {
    case 1:
    {
      elevator_wantedPos = elevator_pos1;
      arm_wantedPos = arm_pos1;
      break;
    }
    case 2:
    {
      elevator_wantedPos = elevator_pos2;
      arm_wantedPos = arm_pos2;
      break;
    }
    case 3:
    {
      elevator_wantedPos = elevator_pos3;
      arm_wantedPos = arm_pos3;
      break;
    }
    case 4:
    {
      elevator_wantedPos = elevator_pos4;
      arm_wantedPos = arm_pos4;
      break;
    }
  }
  }

  SmartDashboard::PutNumber("Wanted Position: ", elevator_wantedPos);

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
  if(elevator_pos < elevator_wantedPos-deadvalue)
  {
    if(elevator_pos>elevator_wantedPos-decreaseDistance)
    {
      realSpeed = motorSpeed / 4;
    }
    Robot::elevator->ElevatorUp(realSpeed);
  } else if(elevator_pos > elevator_wantedPos+deadvalue)
  {
    if(elevator_pos<elevator_wantedPos+decreaseDistance)
    {
      realSpeed = motorSpeed / 4;
    }
    Robot::elevator->ElevatorDown(realSpeed);
  }

  realSpeed = motorSpeed;
  if(arm_pos < arm_wantedPos-deadvalue)
  {
    if(arm_pos>arm_wantedPos-decreaseDistance)
    {
      realSpeed = motorSpeed / 4;
    }
    Robot::arm->ArmDown(realSpeed);
  } else if(arm_pos > arm_wantedPos+deadvalue)
  {
    if(arm_pos<arm_wantedPos+decreaseDistance)
    {
      realSpeed = motorSpeed / 4;
    }
    Robot::arm->ArmDown(realSpeed);
  }
}

bool ElevatorCommand::IsFinished() { return false; }

void ElevatorCommand::End() {
  Robot::elevator->ElevatorStop();
}

void ElevatorCommand::Interrupted() {
  End();
}