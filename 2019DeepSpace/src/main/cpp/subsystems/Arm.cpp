#include "subsystems/Arm.h"
#include "Robot.h"
#include "commands/ElevatorCommand.h"

Arm::Arm() : frc::Subsystem("Arm") {
}


void Arm::InitDefaultCommand() {
  //SetDefaultCommand(new ArmCommand());
}

//======= Method to Rotate Arm Up =======//
void Arm::ArmUp(float _speed){
  if (Robot::armMotor != nullptr){
    Robot::armMotor->Set(_speed);
  }
}

//======= Method to Rotate Arm Down =======//
void Arm::ArmDown(float _speed){
  if (Robot::armMotor != nullptr){
    Robot::armMotor->Set(-_speed);
  }
  
}

//======= Metod to Stop Arm Movement =======//
void Arm::ArmStop(){
  if (Robot::armMotor != nullptr){
    Robot::armMotor->Set(0);
  }
}

