#pragma once

#include <frc/commands/Subsystem.h>

class Arm : public frc::Subsystem {
 public:
  Arm();
  void InitDefaultCommand() override;

  void ArmUp(float _speed);
  void ArmDown(float _speed);
  void ArmStop();
  void ToggleMode();
  bool IsCargoMode();

 private:
    bool isCargoMode;
  };
