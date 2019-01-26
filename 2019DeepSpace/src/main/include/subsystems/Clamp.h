#pragma once

#include <frc/commands/Subsystem.h>

class Clamp : public frc::Subsystem {
 public:
  Clamp();
  void InitDefaultCommand() override;

  void ClampIn(float _speed);
  void ClampOut(float _speed);
  void ClampStop();
  bool IsCargoMode();

 private:
    bool isCargoMode;
  };
