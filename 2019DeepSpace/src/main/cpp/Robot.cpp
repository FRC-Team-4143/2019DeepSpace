#include "Robot.h"
#include <frc/commands/Scheduler.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <iostream>
#include "Modules/Lights.h"
#include "Modules/Mode.h"

#include "subsystems/Arm.h"
#include "subsystems/Elevator.h"
#include "subsystems/Roller.h"
#include "subsystems/Clamp.h"

#define USINGSPARKMAX 1

#define ELEVATOR 11
#define ROLLER 13
#define CLAMP 12
#define ARM 14
#define FRONTCLIMBER 15
#define REARCLIMBER 16

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
Roller* Robot::roller = nullptr;
Clamp* Robot::clamp = nullptr; 
Arm* Robot::arm = nullptr;  
Climber* Robot::climber = nullptr;
DriveTrain* Robot::driveTrain = nullptr;

//======= Motor Definition =======//
MultiController* Robot::driveTrainFrontLeftDrive;
MultiController* Robot::driveTrainFrontLeftSteer;

MultiController* Robot::driveTrainFrontRightDrive;
MultiController* Robot::driveTrainFrontRightSteer;

MultiController* Robot::driveTrainRearLeftDrive;
MultiController* Robot::driveTrainRearLeftSteer;

MultiController* Robot::driveTrainRearRightDrive;
MultiController* Robot::driveTrainRearRightSteer;

rev::CANSparkMax* Robot::elevatorMotor;
MultiController* Robot::rollerMotor;
MultiController* Robot::clampMotor;
rev::CANSparkMax* Robot::armMotor;
MultiController* Robot::frontClimberMotor;
MultiController* Robot::rearClimberMotor;

Servo* Robot::frontServo;
Servo* Robot::rearServo;
Servo* Robot::hatchServo;

void Robot::DeviceInitialization(){
   //======= Front Left Steer =======//
      driveTrainFrontLeftSteer = new SteerTalonController(FLS);

   //======= Front Right Steer =======//
      driveTrainFrontRightSteer = new SteerTalonController(FRS);

   //======= Rear Left Steer =======//
      driveTrainRearLeftSteer = new SteerTalonController(RLS);

   //======= Rear Right Steer =======//
      driveTrainRearRightSteer = new SteerTalonController(RRS);


   #if USINGSPARKMAX
   //======= Front Left Drive =======//
      driveTrainFrontLeftDrive = new SparkMaxController(FLD);

   //======= Front Rigth Drive =======//
      driveTrainFrontRightDrive = new SparkMaxController(FRD);

   //======= Rear Left Drive =======//
      driveTrainRearLeftDrive = new SparkMaxController(RLD);

   //======= Rear Right Drive =======//
      driveTrainRearRightDrive = new SparkMaxController(RRD);

   #else
   //======= Front Left Drive =======//
      driveTrainFrontLeftDrive = new TalonController(FLD);

   //======= Front Rigth Drive =======//
      driveTrainFrontRightDrive = new TalonController(FRD);

   //======= Rear Left Drive =======//
      driveTrainRearLeftDrive = new TalonController(RLD);

   //======= Rear Right Drive =======//
      driveTrainRearRightDrive = new TalonController(RRD);
   #endif



//======= Subsystem Motor Initialization =======//
   elevatorMotor = new rev::CANSparkMax(ELEVATOR,rev::CANSparkMaxLowLevel::MotorType::kBrushless);
   rollerMotor = new TalonController(ROLLER);
   clampMotor = new TalonController(CLAMP);
   armMotor = new rev::CANSparkMax(ARM,rev::CANSparkMaxLowLevel::MotorType::kBrushless);
   frontClimberMotor = new SparkMaxController(FRONTCLIMBER);
   rearClimberMotor = new SparkMaxController(REARCLIMBER);

   frontServo = new Servo(0);
   rearServo = new Servo(1);
   hatchServo = new Servo(2);

//======= System Initialization =======//
   elevator = new Elevator();
   arm = new Arm();
   roller = new Roller();
   clamp = new Clamp();
   climber = new Climber();
   oi = new OI();
   driveTrain = new DriveTrain();
}

void Robot::RobotInit() {
   DeviceInitialization();
   Lights::Init();
   ::Mode::SetLED();
}
   
void Robot::RobotPeriodic() {

	if(frc::RobotController::GetUserButton() == 1 && counter == 0){
		Robot::driveTrain->SetWheelOffsets();
		counter = 100;
		std::cout << "SetWheelOffsets Complete" << std::endl;
      std::cout.flush();
	}
	if(counter > 0) counter -= 1;


   if(elevatorMotor != nullptr)
   {
      SmartDashboard::PutNumber("Elevator Encoder Position", elevatorMotor->GetEncoder().GetPosition());
   }
   if(armMotor != nullptr)
   {
      SmartDashboard::PutNumber("Arm Encoder Position", armMotor->GetEncoder().GetPosition());
   }
}

void Robot::DisabledInit() {}

void Robot::DisabledPeriodic() { frc::Scheduler::GetInstance()->Run(); }

void Robot::AutonomousInit() {
   
}

void Robot::AutonomousPeriodic() { frc::Scheduler::GetInstance()->Run(); }

void Robot::TeleopInit() {
   
}

void Robot::TeleopPeriodic() { frc::Scheduler::GetInstance()->Run(); }

void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main(){
   std::cout << "maincalled" << std::endl; 
   std::cout.flush();
   return frc::StartRobot<Robot>();
    }
#endif
