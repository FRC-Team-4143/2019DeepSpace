#include "subsystems/Arm.h"
#include "commands/ArmCommand.h"
#include <iostream> 
#include "Robot.h"

#define PDPPORT 1
#define CURRNETLIMIT 0.1
#define TESTBOT (1/2)

Arm::Arm() : frc::Subsystem("Arm") {
}

void Arm::InitDefaultCommand() {
  SetDefaultCommand(new ArmCommand());
}

//======= Method to Rotate Arm Up =======//
void Arm::ArmUp(float _speed) {
  if (Robot::armMotor != nullptr){
    //if (Robot::pdp->GetCurrent(PDPPORT) > CURRNETLIMIT){
      Robot::armMotor->SetPercentPower(-_speed);
    //}
  }
}

//======= Method to Rotate Arm Down =======//
void Arm::ArmDown(float _speed) {
  if (Robot::armMotor != nullptr) {
    //if (Robot::pdp->GetCurrent(PDPPORT) > CURRNETLIMIT){
      Robot::armMotor->SetPercentPower(_speed);
    //}
  }
}

//======= Method to Stop Arm Movement =======//
void Arm::ArmStop() {
  if (Robot::armMotor != nullptr) {
    Robot::armMotor->SetPercentPower(0);
  }
}

//======= Method to Hold Arm Up =======//
void Arm::ArmHold(){
  if(Robot::armMotor != nullptr){
    Robot::armMotor->SetPercentPower(-0.025);
  }
}

void Arm::SetPosition(double pos) {
  if (Robot::armMotor != nullptr) {
    if(pos == (62 * TESTBOT) && Robot::armMotor->GetEncoderPosition() > (62 * TESTBOT)){
      Robot::armMotor->SetPercentPower(0);
    }else{
      Robot::armMotor->SetPosition(pos);
    }
  }
}