#pragma once

#include <frc/commands/Command.h>

class EjectGamePiece : public frc::Command {
 public:


  EjectGamePiece();
  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End() override;
  void Interrupted() override;
};
