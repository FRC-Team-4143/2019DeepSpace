#include "subsystems/Elevator.h"
#include "commands/ElevatorCommand.h"
#include "Robot.h"

Elevator::Elevator() : frc::Subsystem("Elevator") {
}

void Elevator::InitDefaultCommand() {
  SetDefaultCommand(new ElevatorCommand());
}

//======= Method to Control Elevator Lift =======//
void Elevator::ElevatorUp(float _speed){
  if (Robot::elevatorMotor != nullptr){
    Robot::elevatorMotor->SetPercentPower(_speed);
  }
}

//======= Method to Control Elevator Lower =======//
void Elevator::ElevatorDown(float _speed){
  if (Robot::elevatorMotor != nullptr){
    Robot::elevatorMotor->SetPercentPower(-_speed);
  }
}

//======= Metod to Stop Elevator Movement =======//
void Elevator::ElevatorStop(){
  if (Robot::elevatorMotor != nullptr){
    Robot::elevatorMotor->SetPercentPower(0);
  }
}

void Elevator::SetHeight(double pos){
  if (Robot::elevatorMotor != nullptr){
    Robot::elevatorMotor->SetPosition(pos);
  }
}