#pragma once

#include <frc/commands/Command.h>

class ArmUpCommand : public frc::Command {
 public:


  ArmUpCommand();
  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End() override;
  void Interrupted() override;
};
