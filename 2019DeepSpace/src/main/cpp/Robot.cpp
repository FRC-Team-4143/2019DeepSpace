#include "Robot.h"
#include <frc/commands/Scheduler.h>
#include <frc/smartdashboard/SmartDashboard.h>

#include <subsystems/Elevator.h>

#define ELEVATOR 3

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

//======= Motor Definition =======//
WPI_TalonSRX* Robot::driveTrainFrontLeftDrive;
WPI_TalonSRX* Robot::driveTrainFrontLeftSteer;

WPI_TalonSRX* Robot::driveTrainFrontRightDrive;
WPI_TalonSRX* Robot::driveTrainFrontRightSteer;

WPI_TalonSRX* Robot::driveTrainRearLeftDrive;
WPI_TalonSRX* Robot::driveTrainRearLeftSteer;

<<<<<<< HEAD
WPI_TalonSRX* Robot::driveTrainRearRightDrive;
WPI_TalonSRX* Robot::driveTrainRearRightSteer;

rev::CANSparkMax* Robot::elevatorMotor;
=======
//======= Variables =======//

float speed = 1;
float firstPos=1;
float secondPos=10; 
float thirdPos=20;

//================================//
>>>>>>> 4fe52a49260ffb5b69e6df87db9488eaaa806eb7

void Robot::RobotInit() {
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
