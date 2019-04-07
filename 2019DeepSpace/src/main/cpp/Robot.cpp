#include "Robot.h"
#include <frc/commands/Scheduler.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <iostream>

#include "controllers/TalonController.h"
#include "controllers/VictorController.h"
#include "controllers/SteerTalonController.h"
#include "controllers/SparkMaxController.h"
#include "controllers/PositionSparkController.h"

#include "Modules/Lights.h"
#include "Modules/Mode.h"
#include "Modules/Logger.h"
#include "Modules/Height.h"

#define USINGSPARKMAXDRIVE 0
#define USINGVICTORDRIVE 1 // 1 for Comp Bot 
#define ONROBORIONAVX 0 // 0 for Comp Bot

#define TESTELEVATOR 21
#define ELEVATOR 11
#define CLAMP 12
#define ROLLER 13
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
Arm* Robot::arm = nullptr;  
Clamp* Robot::clamp = nullptr; 
Climber* Robot::climber = nullptr;
DriveTrain* Robot::driveTrain = nullptr;
Elevator* Robot::elevator = nullptr;
GyroSub* Robot::gyroSub = nullptr;
Roller* Robot::roller = nullptr;
VisionBridgeSub* Robot::visionBridge = nullptr;
PowerDistributionPanel* Robot::pdp = nullptr;


//======= Motor Definition =======//

MultiController* Robot::driveTrainFrontLeftDrive = nullptr;
PositionMultiController* Robot::driveTrainFrontLeftSteer = nullptr;

MultiController* Robot::driveTrainFrontRightDrive = nullptr;
PositionMultiController* Robot::driveTrainFrontRightSteer = nullptr;

MultiController* Robot::driveTrainRearLeftDrive = nullptr;
PositionMultiController* Robot::driveTrainRearLeftSteer = nullptr;

MultiController* Robot::driveTrainRearRightDrive = nullptr;
PositionMultiController* Robot::driveTrainRearRightSteer = nullptr;

PositionMultiController* Robot::armMotor = nullptr;
MultiController* Robot::clampMotor = nullptr;
MultiController* Robot::frontClimberMotor = nullptr;
MultiController* Robot::rearClimberMotor = nullptr;
PositionMultiController* Robot::elevatorMotor = nullptr;
MultiController* Robot::rollerMotor = nullptr;
MultiController* Robot::testElevator = nullptr;

Servo* Robot::frontServo = nullptr;
Servo* Robot::rearServo = nullptr;

AHRS* Robot::navx = nullptr;

void Robot::DeviceInitialization(){
   //======= Front Left Steer =======//
      driveTrainFrontLeftSteer = new SteerTalonController(FLS);

   //======= Front Right Steer =======//
      driveTrainFrontRightSteer = new SteerTalonController(FRS);

   //======= Rear Left Steer =======//
      driveTrainRearLeftSteer = new SteerTalonController(RLS);

   //======= Rear Right Steer =======//
      driveTrainRearRightSteer = new SteerTalonController(RRS);


   #if USINGSPARKMAXDRIVE
   //======= Front Left Drive =======//
      driveTrainFrontLeftDrive = new SparkMaxController(FLD);

   //======= Front Right Drive =======//
      driveTrainFrontRightDrive = new SparkMaxController(FRD);

   //======= Rear Left Drive =======//
      driveTrainRearLeftDrive = new SparkMaxController(RLD);

   //======= Rear Right Drive =======//
      driveTrainRearRightDrive = new SparkMaxController(RRD);

   #else
   #if USINGVICTORDRIVE
   //======= Front Left Drive =======//
      driveTrainFrontLeftDrive = new VictorController(FLD);

   //======= Front Right Drive =======//
      //driveTrainFrontRightDrive = new VictorController(FRD);
      driveTrainFrontRightDrive = new TalonController(FRD);

   //======= Rear Left Drive =======//
      driveTrainRearLeftDrive = new VictorController(RLD);

   //======= Rear Right Drive =======//
      driveTrainRearRightDrive = new VictorController(RRD);

   #else
   //======= Front Left Drive =======//
      driveTrainFrontLeftDrive = new TalonController(FLD);

   //======= Front Right Drive =======//
      driveTrainFrontRightDrive = new TalonController(FRD);

   //======= Rear Left Drive =======//
      driveTrainRearLeftDrive = new TalonController(RLD);

   //======= Rear Right Drive =======//
      driveTrainRearRightDrive = new TalonController(RRD);
   #endif
   #endif

//======= Subsystem Motor Initialization =======//
   armMotor = new PositionSparkController(ARM);
   clampMotor = new TalonController(CLAMP);
   frontClimberMotor = new PositionSparkController(FRONTCLIMBER);
   rearClimberMotor = new PositionSparkController(REARCLIMBER);
   elevatorMotor = new PositionSparkController(ELEVATOR); 
   rollerMotor = new TalonController(ROLLER);
   //testElevator = new TalonController(TESTELEVATOR);

   frontServo = new Servo(0);
   rearServo = new Servo(1);

//======= Sensor and Camera Initialization =======//
#if ONROBORIONAVX
   navx = new AHRS(I2C::Port::kMXP);
#else
   navx = new AHRS(I2C::Port::kOnboard); //kOnboard ?
#endif

//CameraServer::GetInstance()->StartAutomaticCapture(0);
//CameraServer::GetInstance()->StartAutomaticCapture(1);

//======= System Initialization =======//
   arm = new Arm();
   clamp = new Clamp();
   climber = new Climber();
   driveTrain = new DriveTrain();
   elevator = new Elevator();
   gyroSub = new GyroSub();
   roller = new Roller();
   visionBridge = new VisionBridgeSub();

   oi = new OI();
}

void Robot::AddHeights(){
   auto h = Height::GetInstance();

   h->AddCargoTarget(0, 0); // Starting Position with Elevator Down and Arm In
   h->AddCargoTarget(0, 62); // Floor Pickup
   h->AddCargoTarget(-48, 60); // CargoShip Down
   h->AddCargoTarget(0, 39); // 1st Level Rocket
   h->AddCargoTarget(-43, 41); // 2nd Level Rocket
   h->AddCargoTarget(-81.5, 41); // 3rd Level Rocket

   h->AddHatchTarget(0, 0); // Starting Position with Elevator Down and Arm In / CargoShip / Loading Station 
   h->AddHatchTarget(-44, 0); // 2nd Level Rocket
   h->AddHatchTarget(-81,0); // 3rd Level Rocket

   h->AddClimbingTarget(0,0);
}

void Robot::RobotInit() {
   DeviceInitialization();
   SmartDashboard::PutNumber("Yaw Offset", 0);
   AddHeights();
   driveTrain->LoadWheelOffsets();
   Lights::Init();
   ::Mode::SetLED();
}
   
void Robot::RobotPeriodic() {
   auto yawOff = SmartDashboard::GetNumber("Yaw Offset", 0);
   SmartDashboard::PutNumber("Yaw", Robot::navx->GetYaw() + yawOff);

	if (frc::RobotController::GetUserButton() == 1 && counter == 0) {
		Robot::driveTrain->SetWheelOffsets();
		counter = 100;
		std::cout << "SetWheelOffsets Complete" << std::endl;
      std::cout.flush();
	}

	if (counter > 0) {
      counter -= 1;
   }

   if (elevatorMotor != nullptr) {
      SmartDashboard::PutNumber("Elevator Encoder Position", elevatorMotor->GetEncoderPosition());
   }

   if (armMotor != nullptr) {
      SmartDashboard::PutNumber("Arm Encoder Position", armMotor->GetEncoderPosition());
   }

   if (frontClimberMotor != nullptr) {
      SmartDashboard::PutNumber("Front Climber Encoder Position", frontClimberMotor->GetEncoderPosition());
   }

   if (rearClimberMotor != nullptr) {
      SmartDashboard::PutNumber("Rear Climber Encoder Position", rearClimberMotor->GetEncoderPosition());
   }
}

void Robot::DisabledInit() {
}

void Robot::DisabledPeriodic() {
   frc::Scheduler::GetInstance()->Run();
}

void Robot::AutonomousInit() {

}

void Robot::AutonomousPeriodic() {
   frc::Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit() {
}

void Robot::TeleopPeriodic() {
   frc::Scheduler::GetInstance()->Run();
   Height::GetInstance()->UpdateSmartDashboard();
}

void Robot::TestPeriodic() {
}

#ifndef RUNNING_FRC_TESTS
int main(){
   return frc::StartRobot<Robot>();
}
#endif
