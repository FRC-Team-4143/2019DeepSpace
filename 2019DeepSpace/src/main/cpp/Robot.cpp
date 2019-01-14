#include "Robot.h"
#include <frc/commands/Scheduler.h>
#include <frc/smartdashboard/SmartDashboard.h>

#include <subsystems/Elevator.h>

#define ELEVATOR 3

//======= System Definition =======//

OI* Robot::oi = nullptr;
Elevator* Robot::elevator = nullptr;

//======= Motor Definition =======//

rev::CANSparkMax* Robot::decoyMotor;
rev::CANSparkMax* Robot::elevatorMotor;

//================================//

void Robot::RobotInit() {
 //======= Motor Initialization =======//
   elevatorMotor = new rev::CANSparkMax(ELEVATOR,rev::CANSparkMaxLowLevel::MotorType::kBrushless);

 //======= System Initialization =======//
   oi = new OI();
   elevator = new Elevator();
}

void Robot::RobotPeriodic() {}

void Robot::DisabledInit() {}

void Robot::DisabledPeriodic() { frc::Scheduler::GetInstance()->Run(); }

void Robot::AutonomousInit() {}

void Robot::AutonomousPeriodic() { frc::Scheduler::GetInstance()->Run(); }

void Robot::TeleopInit() {}

void Robot::TeleopPeriodic() { frc::Scheduler::GetInstance()->Run(); }

void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
