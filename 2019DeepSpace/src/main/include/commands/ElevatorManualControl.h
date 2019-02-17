#pragma once

#include <frc/commands/Command.h>

class ElevatorManualControl : public frc::Command {
 public:


  ElevatorManualControl();
  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End() override;
  void Interrupted() override;
};
