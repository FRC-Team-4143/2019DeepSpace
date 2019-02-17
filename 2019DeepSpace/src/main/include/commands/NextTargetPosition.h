#pragma once

#include <frc/commands/Command.h>

class NextTargetPosition : public frc::Command {
 public:


  NextTargetPosition();
  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End() override;
  void Interrupted() override;
};
