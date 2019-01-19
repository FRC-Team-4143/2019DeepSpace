#pragma once

#include <frc/commands/Command.h>

class ElevatorCommand : public frc::Command {
 public:

float wantedPos;

float motorSpeed;

  ElevatorCommand();
  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End() override;
  void Interrupted() override;
};
