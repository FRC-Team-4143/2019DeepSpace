#include "commands/ArmManualControl.h"
#include "Robot.h"

ArmManualControl::ArmManualControl() {
  // Use Requires() here to declare subsystem dependencies
  Requires(Robot::arm);
}


void ArmManualControl::Initialize() {

  SmartDashboard::PutString("Arm Mode","Manual");
}

void ArmManualControl::Execute() {
  if(Robot::oi->GetRightTrigger() > 0){
    Robot::armMotor->SetPercentPower(-(Robot::oi->GetRightTrigger()));
    
  }else if (Robot::oi->GetLeftTrigger() > 0){
    Robot::armMotor->SetPercentPower(Robot::oi->GetLeftTrigger());

  }else{
    Robot::armMotor->SetPercentPower(0);
  }
}

bool ArmManualControl::IsFinished() { return false; }

void ArmManualControl::End() {
  Robot::armMotor->SetPercentPower(0);
  
  SmartDashboard::PutString("Arm Mode","UnKnown");
}

void ArmManualControl::Interrupted() {
  End();
}