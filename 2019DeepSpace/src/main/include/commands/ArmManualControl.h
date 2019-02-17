#pragma once

#include <frc/commands/Command.h>

class ArmManualControl : public frc::Command {
 public:


  ArmManualControl();
  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End() override;
  void Interrupted() override;
};
