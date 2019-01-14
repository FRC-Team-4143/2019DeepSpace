#include "subsystems/Elevator.h"
#include "commands/ElevatorCommand.h"
#include "Robot.h"

Elevator::Elevator() : frc::Subsystem("Elevator") {}

void Elevator::InitDefaultCommand() {
  SetDefaultCommand(new ElevatorCommand());
}

//======= Method to Control Elevator Lift =======//
void Elevator::ElevatorUp(float speed){
  #if elevatorMotor == nullptr
    Robot::decoyMotor->Set(0);
  #else
    Robot::elevatorMotor->Set(speed);
  #endif

}

//======= Method to Control Elevator Lower =======//
void Elevator::ElevatorDown(float speed){
  #if elevatorMotor == nullptr
    Robot::decoyMotor->Set(0);
  #else
    Robot::elevatorMotor->Set(-speed);
  #endif
}

//======= Metod to Stop Elevator Movement =======//
void Elevator::ElevatorStop(){
  #if elevatorMotor == nullptr
    Robot::decoyMotor->Set(0);
  #else
    Robot::elevatorMotor->Set(0);
  #endif
}
