#pragma once

#include <frc/commands/Command.h>

class BallPickup : public frc::Command {
 public:


  BallPickup();
  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End() override;
  void Interrupted() override;
};
