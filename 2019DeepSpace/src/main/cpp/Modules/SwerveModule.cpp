#include "modules/SwerveModule.h"
#include "subsystems/EncoderConstants.h"
#include "modules/Constants.h"
#include <frc/Preferences.h>
#include <iostream>

SwerveModule::SwerveModule(MultiController* drive, PositionMultiController* steer, std::string configName) {
  _drive = drive;
  _steer = steer;
  _configName = configName;
}

// ================================================================

void SwerveModule::SetGeometry(double x, double y) {
  _x = x;
  _y = y;
}

// ================================================================

double SwerveModule::GetSteerPosition() {

  float currentPosition = _steer->GetEncoderPosition() / EncoderConstants::COUNTS_PER_TURN;
  int turns = trunc(currentPosition);
  float currentAngle = currentPosition - turns;
  return currentAngle *EncoderConstants::FULL_TURN;
}

// ================================================================

void SwerveModule::SetWheelOffset() {

  _steerPosition = GetSteerPosition();
  auto prefs = frc::Preferences::GetInstance();
  prefs->PutDouble(_configName, _steerPosition);
	SetOffset(_steerPosition);
}

// ================================================================

void SwerveModule::SetOffset(float off) {
	_offset = off;
}

// ================================================================

void SwerveModule::LoadWheelOffset() {
}

// ================================================================

void SwerveModule::SetDriveSpeed(float speed) {
  _drive->SetPercentPower(speed * _inverse);
}

// ================================================================

void SwerveModule::SetSteer(double x, double y, double twist, bool operatorControl) {

 static constexpr double pi = 3.141592653589793238462643383;

	auto radius = std::sqrt(pow(_y, 2) + pow(_x, 2));

	auto BP = x + twist * _x / radius;
	auto CP = y - twist * _y / radius;

	float setpoint = EncoderConstants::HALF_TURN;

	if (BP != 0 || CP != 0) {
		setpoint = (EncoderConstants::HALF_TURN + EncoderConstants::HALF_TURN / pi * atan2(BP, CP));
	}

	setpoint = -setpoint;
	SetSteerSetpoint(setpoint + _offset);

	radius = sqrt(pow(BP, 2) + pow(CP, 2));

	if (operatorControl && fabs(x) <= Constants::DEAD_ZONE && fabs(y) <= Constants::DEAD_ZONE && fabs(twist) <= Constants::DEAD_ZONE) {
			radius = 0;
	}

	if (_x > 0){
		radius = -radius;
	}
	SetDriveSpeed(radius);

}

// ================================================================

void SwerveModule::SetSteerSetpoint(float setpoint) {

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

	_steer->SetPosition(angleOptions[minI]/EncoderConstants::FULL_TURN);

	if (minI % 2)
		_inverse = -1;
	else
		_inverse = 1;
}