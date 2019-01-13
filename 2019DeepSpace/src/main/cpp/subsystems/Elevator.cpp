/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Elevator.h"
#include "commands/ElevatorCommand.h"
#include "Robot.h"

Elevator::Elevator() : frc::Subsystem("Elevator") {}

void Elevator::InitDefaultCommand() {
  SetDefaultCommand(new ElevatorCommand());
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
}

void Elevator::ElevatorUp(float speed){
  Robot::elevatorMotor->Set(speed);
}
void Elevator::ElevatorDown(float speed){
  Robot::elevatorMotor->Set(-speed);
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
