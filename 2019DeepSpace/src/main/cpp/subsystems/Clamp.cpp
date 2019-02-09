#include "subsystems/Clamp.h"
#include "Robot.h"

Clamp::Clamp() : frc::Subsystem("Clamp") {
 
}

void Clamp::InitDefaultCommand() {
  //SetDefaultCommand(new ClampCommand());
}

//======= Method to Control Clamp Release =======//
void Clamp::ClampIn(float _speed){
  if (Robot::clampMotor != nullptr){
    Robot::clampMotor->SetPercentPower(_speed);
  }
}

//======= Method to Control Clamp Pick Up =======//
void Clamp::ClampOut(float _speed){
  if (Robot::clampMotor != nullptr){
    Robot::clampMotor->SetPercentPower(-_speed);
  }
  
}

//======= Metod to Stop Clamp Movement =======//
void Clamp::ClampStop(){
  if (Robot::clampMotor != nullptr){
    Robot::clampMotor->SetPercentPower(0);
  }
}


