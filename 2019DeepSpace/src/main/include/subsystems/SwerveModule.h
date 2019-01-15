#pragma once
#include <ctre/Phoenix.h>

class SwerveModule  {
 public:
  SwerveModule(WPI_TalonSRX* drive, WPI_TalonSRX* steer);
  
 private:

    WPI_TalonSRX* _drive; // speed controller for the drive motor
    WPI_TalonSRX* _steer; // speed controller for the steer motor

  };
