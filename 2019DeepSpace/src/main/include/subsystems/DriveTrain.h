#pragma once

#include <frc/commands/Subsystem.h>
#include "subsystems/SwerveModule.h"



class DriveTrain : public frc::Subsystem {
 public:

  DriveTrain();
  void InitDefaultCommand() override;

 private:
    SwerveModule* frontLeftModule;
    SwerveModule* frontRightModule;
    SwerveModule* rearLeftModule;
    SwerveModule* rearRightModule;
  };
