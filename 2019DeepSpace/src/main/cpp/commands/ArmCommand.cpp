#include "commands/ArmCommand.h"
#include "Modules/Height.h"
#include "Robot.h"

ArmCommand::ArmCommand() {
  // Use Requires() here to declare subsystem dependencies
  Requires(Robot::arm);
}

void ArmCommand::Initialize() {

  SmartDashboard::PutString("Arm Mode","Encoder");
}

void ArmCommand::Execute() {
  Robot::arm->SetPosition(Height::GetInstance()->GetArmTarget());
}

bool ArmCommand::IsFinished() {
  return false;
}

void ArmCommand::End() {
  Robot::arm->ArmStop();
  SmartDashboard::PutString("Arm Mode","Unknown");
}

void ArmCommand::Interrupted() {
  End();
}
