#pragma once

#include <frc/commands/Subsystem.h>
#include "modules/SwerveModule.h"
#include "EncoderConstants.h"



class DriveTrain : public frc::Subsystem {
 public:

  DriveTrain();
  void InitDefaultCommand() override;
  void SetWheelbase(double width, double length);
  void SetWheelOffsets();
  void LoadWheelOffsets();
  void Crab(float twist, float y, float x, bool operatorControl);
  void FieldCentricCrab(float twist, float y, float x, bool operatorControl);
  double GyroRotate();


 private:

  static constexpr double pi = 3.141592653589793238462643383;

  double X;
  double Y; 
  
	float lastx;
	float lasty;
	float lasttwist;

    SwerveModule* frontLeftModule;
    SwerveModule* frontRightModule;
    SwerveModule* rearLeftModule;
    SwerveModule* rearRightModule;
  };
