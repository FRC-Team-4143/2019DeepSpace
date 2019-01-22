#pragma once

#include <frc/commands/Command.h>

class ElevatorMode : public frc::Command {
 public:


  ElevatorMode();
  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End() override;
  void Interrupted() override;
};
