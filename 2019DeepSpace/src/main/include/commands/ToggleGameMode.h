#pragma once

#include <frc/commands/Command.h>

class ToggleGameMode : public frc::Command {
 public:


  ToggleGameMode();
  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End() override;
  void Interrupted() override;
};
