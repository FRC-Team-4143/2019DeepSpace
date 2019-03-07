#include "subsystems/Roller.h"
#include "commands/RollerHold.h"
#include "Robot.h"

Roller::Roller() : frc::Subsystem("Roller") {

}


void Roller::InitDefaultCommand() {
  //SetDefaultCommand(new RollerHold());
}

//======= Method to Control Roller Intake =======//
void Roller::RollerIn(float _speed){
  if (Robot::rollerMotor != nullptr){
    Robot::rollerMotor->SetPercentPower(_speed);
  }
}

//======= Method to Control Roller Outward =======//
void Roller::RollerOut(float _speed){
  if (Robot::rollerMotor != nullptr){
    Robot::rollerMotor->SetPercentPower(-_speed);
  }
  
}

//======= Metod to Stop Roller Movement =======//
void Roller::RollerStop(){
  if (Robot::rollerMotor != nullptr){
    Robot::rollerMotor->SetPercentPower(0);
  }
}

//======= Method to Hold Rollers In =======//
void Roller::RollerHold(){
  if(Robot::rollerMotor != nullptr){
    Robot::rollerMotor->SetPercentPower(0.1);
  }
}