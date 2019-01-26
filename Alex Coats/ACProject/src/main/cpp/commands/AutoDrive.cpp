/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/AutoDrive.h"

#include "Robot.h"

AutoDrive::AutoDrive() {
  // Use Requires() here to declare subsystem dependencies
  Requires(Robot::drivetrain);
}

// Called just before this Command runs the first time
void AutoDrive::Initialize() {
  SetTimeout(1);
}

// Called repeatedly when this Command is scheduled to run
void AutoDrive::Execute() {
  Robot::drivetrain->RightControl(.20);
  Robot::drivetrain->LeftControl(.20);
}

// Make this return true when this Command no longer needs to run execute()
bool AutoDrive::IsFinished() { return IsTimedOut(); }

// Called once after isFinished returns true
void AutoDrive::End() {
  Robot::drivetrain->RightControl(0);
  Robot::drivetrain->LeftControl(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoDrive::Interrupted() {
  End();
}
