#pragma once

#include <frc/commands/Command.h>

class AcquireGamePiece : public frc::Command {
 public:


  AcquireGamePiece();
  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End() override;
  void Interrupted() override;
};
