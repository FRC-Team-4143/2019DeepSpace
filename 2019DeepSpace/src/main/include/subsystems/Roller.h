#pragma once

#include <frc/commands/Subsystem.h>

class Roller : public frc::Subsystem {
 public:
  Roller();
  void InitDefaultCommand() override;

  void RollerIn(float _speed);
  void RollerOut(float _speed);
  void RollerStop();
  void RollerHold();

 private:
    
  };
