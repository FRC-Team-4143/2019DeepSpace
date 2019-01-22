#pragma once

#include <frc/commands/Subsystem.h>

class Elevator : public frc::Subsystem {
 public:
  Elevator();
  void InitDefaultCommand() override;

  void ElevatorUp(float _speed);
  void ElevatorDown(float _speed);
  void ElevatorStop();
  void ToggleMode();
  bool IsCargoMode();

 private:
    bool isCargoMode;
  };
