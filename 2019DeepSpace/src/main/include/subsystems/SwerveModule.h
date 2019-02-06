#pragma once
#include <ctre/Phoenix.h>
#include <rev/CANSparkMax.h>
#include <string>

class SwerveModule  {
 public:
  SwerveModule(rev::CANSparkMax* driveMotor, WPI_TalonSRX* steerMotor, std::string configName); // CHANGE DRIVE MOTOR BACK TO WPI_TalonSRX
  double GetSteerPosition();
  void SetGeometry(double x, double y);
  void SetWheelOffset();
  void LoadWheelOffset();
  void TESTSetDriveSpeed(float _speed)
;  
 private:

  double _x;
  double _y;
  std::string _configName;
  double _steerPosition;
  

  rev::CANSparkMax* _drive; // speed controller for the drive motor CHANGE BACK TO WPI_TalonSRX
  WPI_TalonSRX* _steer; // speed controller for the steer motor

  };
