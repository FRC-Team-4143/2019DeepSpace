#include "subsystems/DriveTrain.h"
#include "Modules/Constants.h"
#include "Robot.h"
#include "Commands/DriveTestCommand.h"

#define USINGTALON 0

DriveTrain::DriveTrain() : frc::Subsystem("DriveTrain") {

  frontLeftModule = new SwerveModule(Robot::driveTrainFrontLeftDrive, Robot::driveTrainFrontLeftSteer, Constants::FL_POS_NAME);
  frontRightModule = new SwerveModule(Robot::driveTrainFrontRightDrive, Robot::driveTrainFrontRightSteer, Constants::FR_POS_NAME);
  rearLeftModule = new SwerveModule(Robot::driveTrainRearLeftDrive, Robot::driveTrainRearLeftSteer, Constants::RL_POS_NAME);
  rearRightModule = new SwerveModule(Robot::driveTrainRearRightDrive, Robot::driveTrainRearRightSteer, Constants::RR_POS_NAME);

}

void DriveTrain::InitDefaultCommand() {
  SetDefaultCommand(new DriveTestCommand());
}
#if USINGTALON
void DriveTrain::SetWheelbase(double width, double length){
  
  double halfWidth = width/2;
  double halfLength = length/2;

  frontLeftModule->SetGeometry(-halfWidth, halfLength);
  frontRightModule->SetGeometry(halfWidth, halfLength);
  rearLeftModule->SetGeometry(-halfWidth, -halfWidth);
  rearRightModule->SetGeometry(halfWidth, -halfLength);
}

void DriveTrain::SetWheelOffsets(){
  frontLeftModule->SetWheelOffset();
  frontRightModule->SetWheelOffset();
  rearLeftModule->SetWheelOffset();
  rearRightModule->SetWheelOffset();
}

void DriveTrain::LoadWheelOffsets(){
  frontLeftModule->LoadWheelOffset();
  frontRightModule->LoadWheelOffset();
  rearLeftModule->LoadWheelOffset();
  rearRightModule->LoadWheelOffset();
}
#endif
void DriveTrain::TESTDrive(){
  frontLeftModule->TESTSetDriveSpeed(Robot::oi->GetLJoystickY());
  frontRightModule->TESTSetDriveSpeed(Robot::oi->GetLJoystickY());
  rearLeftModule->TESTSetDriveSpeed(Robot::oi->GetLJoystickY());
  rearRightModule->TESTSetDriveSpeed(Robot::oi->GetLJoystickY());
}