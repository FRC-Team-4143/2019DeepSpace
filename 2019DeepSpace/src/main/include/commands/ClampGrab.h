#pragma once

#include <frc/commands/Command.h>

class ClampGrab : public frc::Command {
 public:


  ClampGrab();
  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End() override;
  void Interrupted() override;
};
