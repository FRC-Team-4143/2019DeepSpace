#include "commands/ToggleGameMode.h"
#include "Modules/Mode.h"

ToggleGameMode::ToggleGameMode() {
  // Use Requires() here to declare subsystem dependencies
}

void ToggleGameMode::Initialize() {
  Mode::ToggleInGameMode();
}

void ToggleGameMode::Execute() {
}

bool ToggleGameMode::IsFinished() { return true; }

void ToggleGameMode::End() {
}

void ToggleGameMode::Interrupted() {
  End();
}