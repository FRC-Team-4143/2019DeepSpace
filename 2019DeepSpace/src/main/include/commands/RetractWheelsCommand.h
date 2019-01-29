#pragma once

#include <frc/commands/Command.h>

class RetractWheelsCommand : public frc::Command {
 public:

  RetractWheelsCommand();
  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End() override;
  void Interrupted() override;
};
