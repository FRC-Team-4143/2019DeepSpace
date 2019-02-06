#include "commands/ToggleGameMode.h"
#include "Modules/Mode.h"
#include "OI.h"
#include "Robot.h"

ToggleGameMode::ToggleGameMode() {
  // Use Requires() here to declare subsystem dependencies
  Requires(Robot::elevator);
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