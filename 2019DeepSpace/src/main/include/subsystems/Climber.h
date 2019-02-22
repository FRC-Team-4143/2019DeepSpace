#pragma once

#include <frc/commands/Subsystem.h>
#include <string.h>

class Climber : public frc::Subsystem {
 public:
  Climber();
  void InitDefaultCommand() override;
  void RetractWheels(float _rearSpeed, float _frontSpeed);
  void ExtendWheels(float _rearSpeed, float _frontSpeed);
  void HoldWheels();
  
 private:

  };
