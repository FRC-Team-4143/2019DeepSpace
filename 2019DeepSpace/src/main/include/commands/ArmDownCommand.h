#pragma once

#include <frc/commands/Command.h>

class ArmDownCommand : public frc::Command {
 public:


  ArmDownCommand();
  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End() override;
  void Interrupted() override;
};
