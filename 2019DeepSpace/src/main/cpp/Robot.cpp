#include "Robot.h"
#include <frc/commands/Scheduler.h>
#include <frc/smartdashboard/SmartDashboard.h>

#include <subsystems/Elevator.h>
#include <subsystems/Roller.h>
#include <subsystems/Clamp.h>

#define ELEVATOR 11
#define ROLLER 13
#define CLAMP 12

#define FLD 1
#define FLS 5

#define FRD 2
#define FRS 6

#define RLD 3
#define RLS 7

#define RRD 4
#define RRS 8

//======= System Definition =======//
OI* Robot::oi = nullptr;
Elevator* Robot::elevator = nullptr;
OI* Robot::roller = nullptr;
OI* Robot::clamp = nullptr;

//======= Motor Definition =======//
WPI_TalonSRX* Robot::driveTrainFrontLeftDrive;
WPI_TalonSRX* Robot::driveTrainFrontLeftSteer;

WPI_TalonSRX* Robot::driveTrainFrontRightDrive;
WPI_TalonSRX* Robot::driveTrainFrontRightSteer;

WPI_TalonSRX* Robot::driveTrainRearLeftDrive;
WPI_TalonSRX* Robot::driveTrainRearLeftSteer;

WPI_TalonSRX* Robot::driveTrainRearRightDrive;
WPI_TalonSRX* Robot::driveTrainRearRightSteer;

rev::CANSparkMax* Robot::elevatorMotor;
WPI_TalonSRX* Robot::rollerMotor;
WPI_TalonSRX* Robot::clampMotor;

Servo* Robot::servo1;

void Robot::DeviceInitialization(){
//======= Front Left Drive =======//
   driveTrainFrontLeftDrive = new WPI_TalonSRX(FLD);

//======= Front Left Steer =======//
   driveTrainFrontLeftSteer = new WPI_TalonSRX(FLS);

//======= Front Rigth Drive =======//
   driveTrainFrontRightDrive = new WPI_TalonSRX(FRD);

//======= Front Right Steer =======//
   driveTrainFrontLeftSteer = new WPI_TalonSRX(FRS);

//======= Rear Left Drive =======//
   driveTrainRearLeftDrive = new WPI_TalonSRX(RLD);

//======= Rear Left Steer =======//
   driveTrainRearLeftSteer = new WPI_TalonSRX(RLS);

//======= Rear Right Drive =======//
   driveTrainRearRightDrive = new WPI_TalonSRX(RRD);

//======= Rear Right Steer =======//
   driveTrainRearRightSteer = new WPI_TalonSRX(RRS);


//======= Subsystem Motor Initialization =======//
   elevatorMotor = new rev::CANSparkMax(ELEVATOR,rev::CANSparkMaxLowLevel::MotorType::kBrushless);
   rollerMotor = new WPI_TalonSRX(ROLLER);
   clampMotor = new WPI_TalonSRX(CLAMP);

   servo1 = new Servo(4);

//======= System Initialization =======//
   oi = new OI();
   elevator = new Elevator();
   roller = new Roller();
   clamp = new Clamp();
}

void Robot::RobotInit() {
   DeviceInitialization();
}
   
void Robot::RobotPeriodic() {
   SmartDashboard::PutNumber("Elevator Encoder Position", elevatorMotor->GetEncoder().GetPosition());
}

void Robot::DisabledInit() {}

void Robot::DisabledPeriodic() { frc::Scheduler::GetInstance()->Run(); }

void Robot::AutonomousInit() {
   servo1->SetAngle(0);
}

void Robot::AutonomousPeriodic() { frc::Scheduler::GetInstance()->Run(); }

void Robot::TeleopInit() {
   servo1->SetAngle(15);
}

void Robot::TeleopPeriodic() { frc::Scheduler::GetInstance()->Run(); }

void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
