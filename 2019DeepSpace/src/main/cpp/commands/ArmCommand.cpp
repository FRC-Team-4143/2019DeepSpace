#include "commands/ArmCommand.h"
#include "Modules/Height.h"
#include "Robot.h"

ArmCommand::ArmCommand() {
  // Use Requires() here to declare subsystem dependencies
  Requires(Robot::arm);
}

void ArmCommand::Initialize() {

  SmartDashboard::PutString("Elevator Arm","Encoder");
}

void ArmCommand::Execute() {
  Robot::arm->SetPosition(Height::GetInstance().GetArmTarget());
}

bool ArmCommand::IsFinished() {
  return false;
}

void ArmCommand::End() {
  Robot::elevator->ElevatorStop();
  SmartDashboard::PutString("Elevator Arm","Unknown");
}

void ArmCommand::Interrupted() {
  End();
}
