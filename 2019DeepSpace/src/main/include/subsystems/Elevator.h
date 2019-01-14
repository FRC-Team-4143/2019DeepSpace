#pragma once

#include <frc/commands/Subsystem.h>

class Elevator : public frc::Subsystem {
 public:
  Elevator();
  void InitDefaultCommand() override;

  void ElevatorUp(float speed);
  void ElevatorDown(float speed);
  void ElevatorStop();

 private:
  };
