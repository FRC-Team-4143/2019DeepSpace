#include "commands/ArmUpCommand.h"
#include "Modules/Height.h"
#include "Robot.h"

ArmUpCommand::ArmUpCommand() {
  // Use Requires() here to declare subsystem dependencies
  Requires(Robot::arm);
}

void ArmUpCommand::Initialize() {

}

void ArmUpCommand::Execute() {
  Robot::arm->ArmUp(0.25);
}

bool ArmUpCommand::IsFinished() {
  return false;
}

void ArmUpCommand::End() {
  Robot::arm->ArmStop();
}

void ArmUpCommand::Interrupted() {
  End();
}
