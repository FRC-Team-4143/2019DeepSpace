#include "subsystems/SwerveModule.h"

SwerveModule::SwerveModule(WPI_TalonSRX* drive, WPI_TalonSRX* steer) {
  _drive = drive;
  _steer = steer;
}


