#pragma once
#include "controllers/PositionMultiController.h"
#include <string>

class SwerveModule  {
 public:
  SwerveModule(MultiController* driveMotor, PositionMultiController* steerMotor, std::string configName); 
  double GetSteerPosition();
  void SetGeometry(double x, double y);
  void SetWheelOffset();
  void SetOffset(float off);
  void LoadWheelOffset();
  void TESTSetDriveSpeed(float speed);
  void SetDriveSpeed(float speed);
  void SetSteer(float setpoint);
  void SetSteerSetpoint(float setpoint);

 private:

  double _offset;
  double _x;
  double _y;
  std::string _configName;
  double _steerPosition;
  int _inverse = 1;
  

  MultiController* _drive; // speed controller for the drive motor
  PositionMultiController* _steer; // speed controller for the steer motor

  };
