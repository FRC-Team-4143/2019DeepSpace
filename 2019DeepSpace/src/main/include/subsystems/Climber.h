#pragma once

#include <frc/commands/Subsystem.h>
#include <string.h>

class Climber : public frc::Subsystem {
 public:
  Climber();
  void InitDefaultCommand() override;
  void RetractWheels(char _side, float _speed);
  void ExtendWheels(char _side, float _speed);
  void HoldWheels();
  void Default();

 private:

  };
