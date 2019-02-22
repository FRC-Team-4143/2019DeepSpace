#include "commands/ElevatorCommand.h"
#include "Modules/Height.h"
#include "Robot.h"

ElevatorCommand::ElevatorCommand() {
  // Use Requires() here to declare subsystem dependencies
  Requires(Robot::elevator);
}

void ElevatorCommand::Initialize() {

  SmartDashboard::PutString("Elevator Mode","Encoder");
}

void ElevatorCommand::Execute() {
  Robot::elevator->SetHeight(Height::GetInstance()->GetElevatorTarget());
}

bool ElevatorCommand::IsFinished() {
  return false;
}

void ElevatorCommand::End() {
  Robot::elevator->ElevatorStop();
  SmartDashboard::PutString("Elevator Mode","Unknown");
}

void ElevatorCommand::Interrupted() {
  End();
}
