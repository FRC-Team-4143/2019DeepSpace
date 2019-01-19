#pragma once

#include <frc/commands/Command.h>

class ElevatorCommand : public frc::Command {
 public:

float wantedPos;

float pos1;
float pos2;
float pos3;

int posNum;

float motorSpeed;

  ElevatorCommand();
  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End() override;
  void Interrupted() override;
};
