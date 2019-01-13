/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/ElevatorCommand.h"

#include "Robot.h"

ElevatorCommand::ElevatorCommand() {
  // Use Requires() here to declare subsystem dependencies
  Requires(Robot::elevator);
}

// Called just before this Command runs the first time
void ElevatorCommand::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void ElevatorCommand::Execute() {
  if(Robot::oi.RightTrigger() > 0){
    Robot::elevator->ElevatorUp(Robot::oi.RightTrigger());
  } else{
    Robot::elevator->ElevatorDown(Robot::oi.LeftTrigger());
  }
  
}

// Make this return true when this Command no longer needs to run execute()
bool ElevatorCommand::IsFinished() { return false; }

void ElevatorCommand::End() {
  Robot::elevator->ElevatorUp(0);
  Robot::elevator->ElevatorDown(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ElevatorCommand::Interrupted() {
  End();
}