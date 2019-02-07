#include "commands/ElevatorCommand.h"
#include "Modules/Mode.h"

#include "Robot.h"

ElevatorCommand::ElevatorCommand() {
  // Use Requires() here to declare subsystem dependencies
  Requires(Robot::elevator);
}

void ElevatorCommand::Initialize() {
  posNum = 0;

  hatch_elevator_pos1=1000; //what pos does the elevator need to be to pick up a hatch
  hatch_elevator_pos2=2000; //what pos does the elevator need to put a hatch on bottem rocket
  hatch_elevator_pos3=3000; //what pos does the elevator need to put a hatch on middle rocket
  hatch_elevator_pos4=4000; //what pos does the elevator need to put a hatch on top of the rocket

  cargo_elevator_pos1 = 1000; //what pos does the elevator need to be to pick up a ball
  cargo_elevator_pos2 = 2000; //what pos does the elevator need to be to chuck the ball in the first level of the rocket
  cargo_elevator_pos3 = 3000; //what pos does the elevator need to be to chuck the ball in the second level of the rocket
  cargo_elevator_pos4 = 4000; //what pos does the elevator need to be to chuck the ball in the highest level of the rocket

  arm_pos1 = 100; //what pos does the arm need to be to pick up the ball
  arm_pos2 = 200; //what pos does the elevator need to be to chuck the ball in the first level of the rocket
  arm_pos3 = 300; //what pos does the elevator need to be to chuck the ball in the second level of the rocket
  arm_pos4 = 400; //what pos does the elevator need to be to chuck the ball in the highest level of the rocket

  hatch_arm_pos = 0; //what pos does the elevator need to be when in hatch mode.

  motorSpeed=1;

  deadvalue = 75;

  decreaseDistance = 200 + deadvalue;
  elevator_pos = 0;
  arm_pos = 0;
}

void ElevatorCommand::Execute() {
  if (Robot::elevatorMotor == nullptr) {
    return;
  }
  if (Robot::armMotor == nullptr) {
    return;
  }

  if (Robot::oi->GetButtonAPressed()) {
    if (posNum==4) {
      posNum = 0;
    }
    posNum = posNum + 1;
  }

  if (Robot::oi->GetButtonYPressed()) {
    if (posNum==1) {
      posNum = 5;
    }
    posNum = posNum - 1;
  }

  SmartDashboard::PutNumber("Position Number: ", posNum);

  if(Mode::IsEndGame()) {
    arm_wantedPos = hatch_arm_pos;
  }
  else {
    switch(posNum) {
    case 1: {
      if(Mode::IsCargoMode()) {
        elevator_wantedPos = cargo_elevator_pos1;
        arm_wantedPos = arm_pos1;
      }
      else if(Mode::IsHatchMode()) {
        elevator_wantedPos = hatch_elevator_pos1;
        arm_wantedPos = hatch_arm_pos;
      }
      break;
    }
    case 2: {
      if(Mode::IsCargoMode()) {
        elevator_wantedPos = cargo_elevator_pos2;
        arm_wantedPos = arm_pos2;
      }
      else if(Mode::IsHatchMode) {
        elevator_wantedPos = hatch_elevator_pos2;
        arm_wantedPos = hatch_arm_pos;
      }
      break;
    }
    case 3: {
      if(Mode::IsCargoMode()) {
        elevator_wantedPos = cargo_elevator_pos3;
        arm_wantedPos = arm_pos3;
      }
      else if(Mode::IsHatchMode) {
        elevator_wantedPos = hatch_elevator_pos3;
        arm_wantedPos = hatch_arm_pos;
      }
      break;
    }
    case 4: {
      if(Mode::IsCargoMode()) {
        elevator_wantedPos = cargo_elevator_pos4;
        arm_wantedPos = arm_pos4;
      }
      else if(Mode::IsHatchMode()) {
        elevator_wantedPos = hatch_elevator_pos4;
        arm_wantedPos = hatch_arm_pos;
      }
      break;
    }
  }

  SmartDashboard::PutNumber("Wanted Position: ", elevator_wantedPos);

  if (Robot::oi->GetRightTrigger() > 0) {
    Robot::elevator->ElevatorUp(Robot::oi->GetRightTrigger());
  }
  else {
    Robot::elevator->ElevatorDown(Robot::oi->GetLeftTrigger());
  }

  if (Robot::elevatorMotor->GetEncoder().GetPosition() > 0) {
    elevator_pos = Robot::elevatorMotor->GetEncoder().GetPosition();
  }
  if (Robot::armMotor->GetEncoder().GetPosition() > 0) {
    arm_pos = Robot::armMotor->GetEncoder().GetPosition();
  }

  float realSpeed = motorSpeed;
  if (elevator_pos < elevator_wantedPos-deadvalue) {
    if (elevator_pos>elevator_wantedPos-decreaseDistance) {
      realSpeed = motorSpeed / 4;
    }
    Robot::elevator->ElevatorUp(realSpeed);
  }
  else if (elevator_pos > elevator_wantedPos+deadvalue) {
    if (elevator_pos<elevator_wantedPos+decreaseDistance) {
      realSpeed = motorSpeed / 4;
    }
    Robot::elevator->ElevatorDown(realSpeed);
  }

  realSpeed = motorSpeed;
  if (arm_pos < arm_wantedPos-deadvalue) {
    if (arm_pos>arm_wantedPos-decreaseDistance) {
      realSpeed = motorSpeed / 4;
    }
    Robot::arm->ArmDown(realSpeed);
  }
  else if (arm_pos > arm_wantedPos+deadvalue) {
    if (arm_pos<arm_wantedPos+decreaseDistance) {
      realSpeed = motorSpeed / 4;
    }
    Robot::arm->ArmDown(realSpeed);
  }
}
}

bool ElevatorCommand::IsFinished() {
  return false;
}

void ElevatorCommand::End() {
  Robot::elevator->ElevatorStop();
}

void ElevatorCommand::Interrupted() {
  End();
}
