#pragma once

#include <frc/commands/Command.h>

class PreviousTargetPosition : public frc::Command {
 public:


  PreviousTargetPosition();
  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End() override;
  void Interrupted() override;
};
