#include "subsystems/Arm.h"
#include "commands/ArmCommand.h"
#include "Robot.h"

Arm::Arm() : frc::Subsystem("Arm") {
}

void Arm::InitDefaultCommand() {
  SetDefaultCommand(new ArmCommand());
}

//======= Method to Rotate Arm Up =======//
void Arm::ArmUp(float _speed) {
  if (Robot::armMotor != nullptr){
    Robot::armMotor->SetPercentPower(_speed);
  }
}

//======= Method to Rotate Arm Down =======//
void Arm::ArmDown(float _speed) {
  if (Robot::armMotor != nullptr) {
    Robot::armMotor->SetPercentPower(-_speed);
  }
  
}

//======= Method to Stop Arm Movement =======//
void Arm::ArmStop() {
  if (Robot::armMotor != nullptr) {
    Robot::armMotor->SetPercentPower(0);
  }
}

void Arm::SetPosition(double pos) {
  if (Robot::armMotor != nullptr) {
    Robot::armMotor->SetPosition(pos);
  }
}