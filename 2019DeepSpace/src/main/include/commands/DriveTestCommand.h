#pragma once

#include <frc/commands/Command.h>

class DriveTestCommand : public frc::Command {
 public:


  DriveTestCommand();
  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End() override;
  void Interrupted() override;
};
