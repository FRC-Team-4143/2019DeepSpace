#pragma once

#include <frc/commands/Command.h>

class BallRelease : public frc::Command {
 public:


  BallRelease();
  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End() override;
  void Interrupted() override;
};
