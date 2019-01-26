#pragma once

#include <frc/commands/Command.h>

class SetEndGame : public frc::Command {
 public:


  SetEndGame();
  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End() override;
  void Interrupted() override;
};
