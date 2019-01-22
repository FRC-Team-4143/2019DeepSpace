#include "commands/ElevatorMode.h"

#include "Robot.h"

ElevatorMode::ElevatorMode() {
  // Use Requires() here to declare subsystem dependencies
  Requires(Robot::elevator);
}


void ElevatorMode::Initialize() {
  Robot::elevator->ToggleMode();
}

void ElevatorMode::Execute() {
  
}

bool ElevatorMode::IsFinished() { return true; }

void ElevatorMode::End() {

}

void ElevatorMode::Interrupted() {
  End();
}