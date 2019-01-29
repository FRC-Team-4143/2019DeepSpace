#include "subsystems/Roller.h"
#include "Robot.h"

Roller::Roller() : frc::Subsystem("Roller") {
  isCargoMode = false;
}


void Roller::InitDefaultCommand() {
  //SetDefaultCommand(new Command());
}

//======= Method to Control Roller Intake =======//
void Roller::RollerIn(float _speed){
  if (Robot::rollerMotor != nullptr){
    Robot::rollerMotor->Set(_speed);
  }
}

//======= Method to Control Roller Outward =======//
void Roller::RollerOut(float _speed){
  if (Robot::rollerMotor != nullptr){
    Robot::rollerMotor->Set(-_speed);
  }
  
}

//======= Metod to Stop Roller Movement =======//
void Roller::RollerStop(){
  if (Robot::rollerMotor != nullptr){
    Robot::rollerMotor->Set(0);
  }
}

//RobotMap::i2c->Write(5,0);
