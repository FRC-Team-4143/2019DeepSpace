#pragma once

#include <frc/commands/Command.h>

class HatchServo : public frc::Command {
 public:


  HatchServo();
  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End() override;
  void Interrupted() override;
};
