#include "commands/ArmDownCommand.h"
#include "Modules/Height.h"
#include "Robot.h"

ArmDownCommand::ArmDownCommand() {
  // Use Requires() here to declare subsystem dependencies
  Requires(Robot::arm);
}

void ArmDownCommand::Initialize() {

}

void ArmDownCommand::Execute() {
  Robot::arm->ArmDown(0.55);
}

bool ArmDownCommand::IsFinished() {
  return false;
}

void ArmDownCommand::End() {
    Robot::arm->ArmStop();
}

void ArmDownCommand::Interrupted() {
  End();
}
