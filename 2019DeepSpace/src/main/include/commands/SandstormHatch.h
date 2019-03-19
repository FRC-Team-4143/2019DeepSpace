#pragma once

#include <frc/commands/Command.h>

class SandstormHatch : public frc::Command {
 public:


  SandstormHatch();
  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End() override;
  void Interrupted() override;
};
