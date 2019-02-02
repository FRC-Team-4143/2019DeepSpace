#pragma once

#include <frc/commands/Command.h>

class ClampRelease : public frc::Command {
 public:


  ClampRelease();
  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End() override;
  void Interrupted() override;
};
