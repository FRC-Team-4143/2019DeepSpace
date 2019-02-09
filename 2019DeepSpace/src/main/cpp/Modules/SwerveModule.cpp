#include "modules/SwerveModule.h"
#include "subsystems/EncoderConstants.h"
#include <frc/Preferences.h>
#include <iostream>

SwerveModule::SwerveModule(MultiController* drive, PositionMultiController* steer, std::string configName) {
  _drive = drive;
  _steer = steer;
  _configName = configName;
}

void SwerveModule::SetGeometry(double x, double y) {
  _x = x;
  _y = y;
}

double SwerveModule::GetSteerPosition() {
  float currentPosition = _steer->GetEncoderPosition() / EncoderConstants::COUNTS_PER_TURN;
  int turns = trunc(currentPosition);
  float currentAngle = currentPosition - turns;
  return currentAngle *EncoderConstants::FULL_TURN;
}

void SwerveModule::SetWheelOffset() {
	std::cout << "SetWheelOffsets SwerveModule" << std::endl;
  std::cout.flush();
  _steerPosition = GetSteerPosition();
  auto prefs = frc::Preferences::GetInstance();
  prefs->PutDouble(_configName, _steerPosition);
	SetOffset(_steerPosition);
}

void SwerveModule::SetOffset(float off) {
	_offset = off;
}

void SwerveModule::LoadWheelOffset() {
}

void SwerveModule::TESTSetDriveSpeed(float speed) {
  _drive->SetPercentPower(speed/4);
}

void SwerveModule::SetDriveSpeed(float speed) {
  _drive->SetPercentPower(speed * _inverse);
}

void SwerveModule::SetSteer(float setpoint) {
  std::cout << "SetSteer()" << std::endl;
  std::cout.flush();

	setpoint = -setpoint;
	SetSteerSetpoint(setpoint + _offset);
}

void SwerveModule::SetSteerSetpoint(float setpoint) {
	std::cout << "SetSteerSetpoint()" << std::endl;
  std::cout.flush();

	float currentPosition = _steer->GetEncoderPosition() / EncoderConstants::COUNTS_PER_TURN;
	int turns = trunc(currentPosition);
	float currentAngle = currentPosition - turns;

	currentPosition *= EncoderConstants::FULL_TURN;
	turns *= EncoderConstants::FULL_TURN;
	currentAngle *= EncoderConstants::FULL_TURN;

	float angleOptions[6];
	angleOptions[0] = turns - EncoderConstants::FULL_TURN + setpoint;
	angleOptions[1] = turns - EncoderConstants::FULL_TURN + setpoint + EncoderConstants::HALF_TURN;
	angleOptions[2] = turns + setpoint;
	angleOptions[3] = turns + setpoint + EncoderConstants::HALF_TURN;
	angleOptions[4] = turns + EncoderConstants::FULL_TURN + setpoint;
	angleOptions[5] = turns + EncoderConstants::FULL_TURN + setpoint + EncoderConstants::HALF_TURN;

	float minMove = fabs(currentPosition - angleOptions[0]);
	int minI = 0;
	for (int i = 1; i < 6; i++){
		if (fabs(currentPosition - angleOptions[i]) < minMove){
			minMove = fabs(currentPosition - angleOptions[i]);
			minI = i;
		}
	}

	_steer->SetPosition(angleOptions[minI]/EncoderConstants::FULL_TURN * 4096, 0);

	if (minI % 2)
		_inverse = -1;
	else
		_inverse = 1;
}