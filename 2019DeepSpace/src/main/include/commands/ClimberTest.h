#pragma once

#include <frc/commands/Command.h>

class ClimberTest : public frc::Command {
 public:


  ClimberTest();
  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End() override;
  void Interrupted() override;
};
