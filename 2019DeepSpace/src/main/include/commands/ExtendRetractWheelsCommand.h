#pragma once

#include <frc/commands/Command.h>

class ExtendRetractWheelsCommand : public frc::Command {
 public:

  ExtendRetractWheelsCommand();
  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End() override;
  void Interrupted() override;
};
