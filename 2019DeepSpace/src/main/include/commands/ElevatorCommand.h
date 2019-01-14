#pragma once

#include <frc/commands/Command.h>

class ElevatorCommand : public frc::Command {
 public:
  ElevatorCommand();
  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End() override;
  void Interrupted() override;
};
