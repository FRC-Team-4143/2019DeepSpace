/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/DriveTrain.h"
#include "commands/Drive.h"

#include "Robot.h"

DriveTrain::DriveTrain () : frc::Subsystem("DriveTrain") {}


void DriveTrain::InitDefaultCommand() {
  // Set the default command for a subsystem here.
  SetDefaultCommand(new Drive());
}

void DriveTrain::RightControl(float speed){
  Robot::motorRight->Set(ControlMode::PercentOutput,-speed);
}
void DriveTrain::LeftControl(float speed){
  Robot::motorLeft->Set(ControlMode::PercentOutput,speed);
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
