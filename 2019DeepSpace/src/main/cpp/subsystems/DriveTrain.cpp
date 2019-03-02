#include "subsystems/DriveTrain.h"
#include "Modules/Constants.h"
#include "Robot.h"
#include "commands/CrabDrive.h"
#include "commands/FieldCentric.h"
#include "Modules/Logger.h"
#include <iostream>

//const float DEAD_ZONE = 0.15;

DriveTrain::DriveTrain() : frc::Subsystem("DriveTrain") {
	frontLeftModule = new SwerveModule(Robot::driveTrainFrontLeftDrive, Robot::driveTrainFrontLeftSteer, Constants::FL_POS_NAME);
  frontRightModule = new SwerveModule(Robot::driveTrainFrontRightDrive, Robot::driveTrainFrontRightSteer, Constants::FR_POS_NAME);
  rearLeftModule = new SwerveModule(Robot::driveTrainRearLeftDrive, Robot::driveTrainRearLeftSteer, Constants::RL_POS_NAME);
  rearRightModule = new SwerveModule(Robot::driveTrainRearRightDrive, Robot::driveTrainRearRightSteer, Constants::RR_POS_NAME);

  SetWheelbase(24, 24);
}

// ================================================================

void DriveTrain::InitDefaultCommand() {
  SetDefaultCommand(new FieldCentric());
}

// ================================================================

void DriveTrain::SetWheelbase(double width, double length){
  
  X = width;
  Y = length;

  double halfWidth = width/2;
  double halfLength = length/2;

  frontLeftModule->SetGeometry(-halfWidth, halfLength);
  frontRightModule->SetGeometry(halfWidth, halfLength);
  rearLeftModule->SetGeometry(-halfWidth, -halfWidth);
  rearRightModule->SetGeometry(halfWidth, -halfLength);
}

// ================================================================

void DriveTrain::SetWheelOffsets(){

  frontLeftModule->SetWheelOffset();
  frontRightModule->SetWheelOffset();
  rearLeftModule->SetWheelOffset();
  rearRightModule->SetWheelOffset();
}

// ================================================================

void DriveTrain::LoadWheelOffsets(){
  frontLeftModule->LoadWheelOffset();
  frontRightModule->LoadWheelOffset();
  rearLeftModule->LoadWheelOffset();
  rearRightModule->LoadWheelOffset();
}

// ================================================================

void DriveTrain::Crab(float twist, float y, float x, bool operatorControl){

  if (operatorControl && x == 0.0 && y == 0.0 && twist == 0.0) {
		if (fabs(lasty) > 0 || fabs(lastx) > 0 || fabs(lasttwist) > 0) {
			y = std::min(std::max(lasty, -Constants::DEAD_ZONE), Constants::DEAD_ZONE);
			x = std::min(std::max(lastx, -Constants::DEAD_ZONE), Constants::DEAD_ZONE);
			twist = std::min(std::max(lasttwist, -Constants::DEAD_ZONE), Constants::DEAD_ZONE);
		} else {
			y = .05;
			// default wheel position
		}
	} else	{
		lastx = x;
		lasty = y;
		lasttwist = twist;
	}

	if (operatorControl) {
		// scale for operator control
		x *= 1;
		y *= 1;
		float avg = (abs(x) + abs(y)) / 2;
		float scale = 1 - avg / 2;
		twist *= scale; // TWISTSCALE;
	}
	
  frontLeftModule->SetSteerDrive(x, y, twist, operatorControl); 
  frontRightModule->SetSteerDrive(x, y, twist, operatorControl);
  rearLeftModule->SetSteerDrive(x, y, twist, operatorControl);
  rearRightModule->SetSteerDrive(x, y, twist, operatorControl);

}

// ================================================================

void DriveTrain::FieldCentricCrab(float twist, float y, float x, bool operatorControl){

	float FWD = y;
	float STR = x;

	auto robotangle = Robot::gyroSub->PIDGet() * pi / 180;

	FWD = y * cos(robotangle) + x * sin(robotangle);
	STR = -y * sin(robotangle) + x * cos(robotangle);

	Crab((twist*0.65), FWD, STR, operatorControl); // twist * 0.65
}

// ================================================================

void DriveTrain::GyroRotate(float desiredangle, double power){
	
	auto robotangle = Robot::gyroSub->PIDGet();

	float twist = desiredangle - robotangle;
	while (twist > 180.0) {
		twist -= 360.0;
	}
	while (twist < -180.0) {
		twist += 360.0;
	}

	twist = std::min(power, std::max(-power, twist * (0.2/10)));
	Crab(twist, 0, 0, false);
}
