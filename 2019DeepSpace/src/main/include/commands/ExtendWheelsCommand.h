#pragma once

#include <frc/commands/Command.h>

class ExtendWheelsCommand : public frc::Command {
 public:

  ExtendWheelsCommand();
  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End() override;
  void Interrupted() override;
};
