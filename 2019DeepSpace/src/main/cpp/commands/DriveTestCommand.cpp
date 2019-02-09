#include "commands/DriveTestCommand.h"
#include "Robot.h"

DriveTestCommand::DriveTestCommand() {
  // Use Requires() here to declare subsystem dependencies
  Requires(Robot::driveTrain);
}


void DriveTestCommand::Initialize() {
}

void DriveTestCommand::Execute() {
  Robot::driveTrain->TESTDrive();
}

bool DriveTestCommand::IsFinished() { return false; }

void DriveTestCommand::End() {

}

void DriveTestCommand::Interrupted() {
  End();
}