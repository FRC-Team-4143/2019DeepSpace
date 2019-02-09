#include "subsystems/DriveTrain.h"
#include "Modules/Constants.h"
#include "Robot.h"
#include "Commands/DriveTestCommand.h"
#include "commands/CrabDrive.h"
#include "commands/FieldCentric.h"
#include <iostream>

const float DEAD_ZONE = 0.15;

float lastx = 0.0;
float lasty = 0.0;
float lasttwist = 0.0;

DriveTrain::DriveTrain() : frc::Subsystem("DriveTrain") {

  std::cout << "DriveTrain()" << std::endl;
  std::cout.flush();
  frontLeftModule = new SwerveModule(Robot::driveTrainFrontLeftDrive, Robot::driveTrainFrontLeftSteer, Constants::FL_POS_NAME);
  frontRightModule = new SwerveModule(Robot::driveTrainFrontRightDrive, Robot::driveTrainFrontRightSteer, Constants::FR_POS_NAME);
  rearLeftModule = new SwerveModule(Robot::driveTrainRearLeftDrive, Robot::driveTrainRearLeftSteer, Constants::RL_POS_NAME);
  rearRightModule = new SwerveModule(Robot::driveTrainRearRightDrive, Robot::driveTrainRearRightSteer, Constants::RR_POS_NAME);

  SetWheelbase(24, 24);
}

void DriveTrain::InitDefaultCommand() {
  SetDefaultCommand(new FieldCentric());
}

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

void DriveTrain::SetWheelOffsets(){

  std::cout << "SetWheelOffsets Method" << std::endl;
  std::cout.flush();
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

void DriveTrain::TESTDrive(){

  frontLeftModule->TESTSetDriveSpeed(Robot::oi->GetJoystickY());
  frontRightModule->TESTSetDriveSpeed(Robot::oi->GetJoystickY());
  rearLeftModule->TESTSetDriveSpeed(Robot::oi->GetJoystickY());
  rearRightModule->TESTSetDriveSpeed(Robot::oi->GetJoystickY());
}

void DriveTrain::Crab(float twist, float y, float x, bool operatorControl){

  std::cout << "Crab()" << std::endl;
  std::cout.flush();
   
  if (operatorControl && x == 0.0 && y == 0.0 && twist == 0.0) {
		if (fabs(lasty) > DEAD_ZONE || fabs(lastx) > DEAD_ZONE
				|| fabs(lasttwist) > DEAD_ZONE) {
			y = std::min(std::max(lasty, -DEAD_ZONE), DEAD_ZONE);
			x = std::min(std::max(lastx, -DEAD_ZONE), DEAD_ZONE);
			twist = std::min(std::max(lasttwist, -DEAD_ZONE), DEAD_ZONE);
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

  float FWD = y;
  float STR = x;

	auto radius = std::sqrt(pow(Y, 2) + pow(X, 2));

	auto AP = STR - twist * X / radius;
	auto BP = STR + twist * X / radius;
	auto CP = FWD - twist * Y / radius;
	auto DP = FWD + twist * Y / radius;

	float FLSetPoint = EncoderConstants::HALF_TURN;
	float FRSetPoint = EncoderConstants::HALF_TURN;
	float RLSetPoint = EncoderConstants::HALF_TURN;
	float RRSetPoint = EncoderConstants::HALF_TURN;

	if (DP != 0 || BP != 0) {
		FLSetPoint = (EncoderConstants::HALF_TURN
				+ EncoderConstants::HALF_TURN / pi * atan2(BP, DP));
	}
	if (BP != 0 || CP != 0) {
		FRSetPoint = (EncoderConstants::HALF_TURN
				+ EncoderConstants::HALF_TURN / pi * atan2(BP, CP));
	}
	if (AP != 0 || DP != 0) {
		RLSetPoint = (EncoderConstants::HALF_TURN
				+ EncoderConstants::HALF_TURN / pi * atan2(AP, DP));
	}
	if (AP != 0 || CP != 0) {
		RRSetPoint = (EncoderConstants::HALF_TURN
				+ EncoderConstants::HALF_TURN / pi * atan2(AP, CP));
	}

  std::cout << "Crab 1" << std::endl;
  std::cout.flush();
	
  frontLeftModule->SetSteer(FLSetPoint); 
  frontRightModule->SetSteer(FRSetPoint);
  rearLeftModule->SetSteer(RLSetPoint);
  rearRightModule->SetSteer(RRSetPoint);

  std::cout << "Crab 2" << std::endl;
  std::cout.flush();

	double FL; // FL, distance from Front Left Wheel to the center of rotation
	double FR; // FR, distance from Front Right Wheel to the center of rotation
	double RL; // RL, distance from Rear Left Wheel to the center of rotation
	double RR; // RR, distance from Rear Right Wheel to the center of rotation

	FL = sqrt(pow(BP, 2) + pow(DP, 2));
	FR = sqrt(pow(BP, 2) + pow(CP, 2));
	RL = sqrt(pow(AP, 2) + pow(DP, 2));
	RR = sqrt(pow(AP, 2) + pow(CP, 2));

	// Solve for fastest wheel speed
	double speedarray[] = { fabs(FL), fabs(FR), fabs(RL), fabs(RR) };

	int length = 4;
	double maxspeed = speedarray[0];
	for (int i = 1; i < length; i++) {
		if (speedarray[i] > maxspeed) {
			maxspeed = speedarray[i];
		}
	}

	double FRRatio; // Ratio of Speed of Front Right wheel
	double FLRatio; // Ratio of Speed of Front Left wheel
	double RRRatio; // Ratio of Speed of Rear Right wheel
	double RLRatio; // Ratio of Speed of Rear Left wheel

	// Set ratios based on maximum wheel speed
	if (maxspeed > 1 || maxspeed < -1) {
		FLRatio = FL / maxspeed;
		FRRatio = FR / maxspeed;
		RLRatio = RL / maxspeed;
		RRRatio = RR / maxspeed;
	} else {
		FLRatio = FL;
		FRRatio = FR;
		RLRatio = RL;
		RRRatio = RR;
	}

	if (operatorControl && fabs(x) <= DEAD_ZONE && fabs(y) <= DEAD_ZONE
			&& fabs(twist) <= DEAD_ZONE) {
		FLRatio = 0.0;
		FRRatio = 0.0;
		RLRatio = 0.0;
		RRRatio = 0.0;
	}

  std::cout << "Crab 3" << std::endl;
  std::cout.flush();

	// Set drive speeds
  frontLeftModule->SetDriveSpeed(FLRatio); 
  frontRightModule->SetDriveSpeed(-FRRatio);
  rearLeftModule->SetDriveSpeed(RLRatio);
  rearRightModule->SetDriveSpeed(-RRRatio);

  std::cout << "Crab end" << std::endl;
  std::cout.flush();

}

void DriveTrain::FieldCentricCrab(float twist, float y, float x, bool operatorControl){

	float FWD = y;
	float STR = x;

	auto robotangle = Robot::gyroSub->PIDGet() * pi / 180;

	FWD = y * cos(robotangle) + x * sin(robotangle);
	STR = -y * sin(robotangle) + x * cos(robotangle);

	Crab((twist*0.65), FWD, STR, operatorControl); // twist * 0.65
}