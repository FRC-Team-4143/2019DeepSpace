/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/AutoTurn.h"

#include "Robot.h"

AutoTurn::AutoTurn() {
  // Use Requires() here to declare subsystem dependencies
  Requires(Robot::drivetrain);
}

// Called just before this Command runs the first time
void AutoTurn::Initialize() {
  SetTimeout(1.3);
}

// Called repeatedly when this Command is scheduled to run
void AutoTurn::Execute() {
  Robot::drivetrain->RightControl(.20);
  Robot::drivetrain->LeftControl(-.20);
}

// Make this return true when this Command no longer needs to run execute()
bool AutoTurn::IsFinished() { return IsTimedOut(); }

// Called once after isFinished returns true
void AutoTurn::End() {
  Robot::drivetrain->RightControl(0);
  Robot::drivetrain->LeftControl(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoTurn::Interrupted() {
  End();
}
