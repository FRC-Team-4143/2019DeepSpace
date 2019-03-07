#include "commands/ArmHoldCommand.h"
#include "Robot.h"

ArmHoldCommand::ArmHoldCommand() {
  // Use Requires() here to declare subsystem dependencies
  Requires(Robot::arm);
}

void ArmHoldCommand::Initialize() {

}

void ArmHoldCommand::Execute() {
  if(Robot::armMotor->GetEncoderPosition() > 15){
    Robot::arm->ArmHold();
  }
}

bool ArmHoldCommand::IsFinished() {
  return false;
}

void ArmHoldCommand::End() {
    Robot::arm->ArmStop();
}

void ArmHoldCommand::Interrupted() {
  End();
}
