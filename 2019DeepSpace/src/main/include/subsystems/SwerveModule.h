#pragma once
#include <ctre/Phoneix.h>

class SwerveModule  {
 public:
  SwerveModule(WPI_TalonSRX* drive, WPI_Talon* steer);
  
 private:
    
    double Offset; // wheel position
    double Inv; // direction of the drive motor

    WPI_TalonSRX* _drive; // speed controller for the drive motor
    WPI_TalonSRX* _steer; // speed controller for the steer motor

  };
