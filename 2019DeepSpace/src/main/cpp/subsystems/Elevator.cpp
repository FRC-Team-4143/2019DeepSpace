#include "subsystems/Elevator.h"
#include "commands/ElevatorCommand.h"
#include "Robot.h"

Elevator::Elevator() : frc::Subsystem("Elevator") {}

void Elevator::InitDefaultCommand() {
  SetDefaultCommand(new ElevatorCommand());
}

//======= Method to Control Elevator Lift =======//
void Elevator::ElevatorUp(float speed){
  if (elevatorMotor != nullptr){
    Robot::elevatorMotor->Set(speed);
  }
}

//======= Method to Control Elevator Lower =======//
void Elevator::ElevatorDown(float speed){
  if (elevatorMotor != nullptr){
    Robot::elevatorMotor->Set(-speed);
  }
}

//======= Metod to Stop Elevator Movement =======//
void Elevator::ElevatorStop(){
  if (elevatorMotor != nullptr)
    Robot::elevatorMotor->Set(0);
  }
}
