#pragma once

#include <frc/commands/Command.h>

class ElevatorCommand : public frc::Command {
 public:

float elevator_wantedPos;

float arm_wantedPos;

  float hatch_elevator_pos1;
  float hatch_elevator_pos2;
  float hatch_elevator_pos3;
  float hatch_elevator_pos4;

  float cargo_elevator_pos1;
  float cargo_elevator_pos2;
  float cargo_elevator_pos3;
  float cargo_elevator_pos4;

  float arm_pos1;
  float arm_pos2;
  float arm_pos3;
  float arm_pos4;

float hatch_arm_pos;

int posNum;

float motorSpeed;

float deadvalue;

float decreaseDistance;

double elevator_pos;
double arm_pos;

  ElevatorCommand();
  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End() override;
  void Interrupted() override;
};
