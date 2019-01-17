#pragma once
#include <ctre/Phoenix.h>
#include <string>

class SwerveModule  {
 public:
  SwerveModule(WPI_TalonSRX* driveMotor, WPI_TalonSRX* steerMotor, std::string configName);
  double GetSteerPosition();
  void SetGeometry(double x, double y);
  void SetWheelOffset();
  void LoadWheelOffset();
  
 private:

  double _x;
  double _y;
  std::string _configName;
  double _steerPosition;
  

  WPI_TalonSRX* _drive; // speed controller for the drive motor
  WPI_TalonSRX* _steer; // speed controller for the steer motor

  };
