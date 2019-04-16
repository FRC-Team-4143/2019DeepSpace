#pragma once
#include "controllers/PositionMultiController.h"
#include <string>

class SwerveModule {
public:

	SwerveModule(MultiController* driveMotor, PositionMultiController* steerMotor, std::string configName); 
	double GetSteerPosition();
	void SetGeometry(double x, double y, double maxradius);
	void SetWheelOffset();
	void SetOffset(float off);
	void LoadWheelOffset();
	void SetDriveSpeed(float speed);
	double SetSteerDrive(double x, double y, double twist, bool operatorControl);
	void SetSteerSetpoint(float setpoint);

private:

	double _offset;
	double _x;
	double _y;
	double _radius;
	std::string _configName;
	double _steerPosition;
	int _inverse = 1;
	MultiController* _drive; // speed controller for the drive motor
	PositionMultiController* _steer; // speed controller for the steer motor
};
