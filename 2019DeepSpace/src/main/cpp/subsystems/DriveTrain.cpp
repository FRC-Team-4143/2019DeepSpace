#include "subsystems/DriveTrain.h"
#include "Robot.h"

DriveTrain::DriveTrain() : frc::Subsystem("DriveTrain") {

  frontLeftModule = new SwerveModule(Robot::driveTrainFrontLeftDrive, Robot::driveTrainFrontLeftSteer);
  frontRightModule = new SwerveModule(Robot::driveTrainFrontRightDrive, Robot::driveTrainFrontRightSteer);
  rearLeftModule = new SwerveModule(Robot::driveTrainRearLeftDrive, Robot::driveTrainRearLeftSteer);
  rearRightModule = new SwerveModule(Robot::driveTrainRearRightDrive, Robot::driveTrainRearRightSteer);

}

void DriveTrain::InitDefaultCommand() {
  //SetDefaultCommand());
}
