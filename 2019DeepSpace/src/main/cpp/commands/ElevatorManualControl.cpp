#include "commands/ElevatorManualControl.h"
#include "Robot.h"

ElevatorManualControl::ElevatorManualControl() {
  // Use Requires() here to declare subsystem dependencies
  Requires(Robot::elevator);
}


void ElevatorManualControl::Initialize() {

  SmartDashboard::PutString("Elevator Mode","Manual");
}

void ElevatorManualControl::Execute() {
  if(Robot::oi->GetRightTrigger() > 0){
    Robot::testElevator->SetPercentPower(-(Robot::oi->GetRightTrigger()));
    //Robot::elevator->ElevatorUp(Robot::oi->GetRightTrigger());
  }else if (Robot::oi->GetLeftTrigger() > 0){
    Robot::testElevator->SetPercentPower(Robot::oi->GetLeftTrigger());
    //Robot::elevator->ElevatorDown(Robot::oi->GetLeftTrigger());
  }else{
    Robot::testElevator->SetPercentPower(0);
    //Robot::elevator->ElevatorStop();
  }
}

bool ElevatorManualControl::IsFinished() { return false; }

void ElevatorManualControl::End() {
  Robot::testElevator->SetPercentPower(0);
  //Robot::elevator->ElevatorStop();
  SmartDashboard::PutString("Elevator Mode","Unknown");
}

void ElevatorManualControl::Interrupted() {
  End();
}