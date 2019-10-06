#define DIFFSWERVE 1
#include "Robot.h"
#include <frc/commands/Scheduler.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <iostream>

#include "controllers/TalonController.h"
#include "controllers/VictorController.h"
#include "controllers/SteerTalonController.h"
#include "controllers/SparkMaxController.h"
#include "controllers/PositionSparkController.h"
#include "controllers/VelocitySparkController.h"

#include "Modules/Lights.h"
#include "Modules/Mode.h"
#include "Modules/Logger.h"
#include "Modules/Height.h"
#include "Modules/Constants.h"

#define USINGSPARKMAXDRIVE 1
#define USINGVICTORDRIVE 0 // 1 for Comp Bot 
#define ONROBORIONAVX 0 // 0 for Comp Bot
#define TESTBOT (0.45)


#define TESTELEVATOR 21
#define ELEVATOR 11
#define CLAMP 12
#define ROLLER 13
#define ARM 14
#define FRONTCLIMBER 15
#define REARCLIMBER 16

/*
#define FLD 1
#define FLS 2

#define FRD 3
#define FRS 4

#define RLD 5
#define RLS 6

#define RRD 7
#define RRS 8
*/

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
Compressor* Robot::comp = nullptr;


//======= Motor Definition =======//
#if DIFFSWERVE
VelocityMultiController* Robot::driveTrainFrontLeftDrive = nullptr;
VelocityMultiController* Robot::driveTrainFrontLeftSteer = nullptr;

VelocityMultiController* Robot::driveTrainFrontRightDrive = nullptr;
VelocityMultiController* Robot::driveTrainFrontRightSteer = nullptr;

VelocityMultiController* Robot::driveTrainRearLeftDrive = nullptr;
VelocityMultiController* Robot::driveTrainRearLeftSteer = nullptr;

VelocityMultiController* Robot::driveTrainRearRightDrive = nullptr;
VelocityMultiController* Robot::driveTrainRearRightSteer = nullptr;

SwerveModuleInterface* Robot::frontLeftModule = nullptr;
SwerveModuleInterface* Robot::frontRightModule = nullptr;
SwerveModuleInterface* Robot::rearLeftModule = nullptr;
SwerveModuleInterface* Robot::rearRightModule  = nullptr;

AnalogInput* Robot::frontRightPot = nullptr;
AnalogInput* Robot::frontLeftPot = nullptr;
AnalogInput* Robot::rearRightPot = nullptr;
AnalogInput* Robot::rearLeftPot = nullptr;

#else
MultiController* Robot::driveTrainFrontLeftDrive = nullptr;
PositionMultiController* Robot::driveTrainFrontLeftSteer = nullptr;

MultiController* Robot::driveTrainFrontRightDrive = nullptr;
PositionMultiController* Robot::driveTrainFrontRightSteer = nullptr;

MultiController* Robot::driveTrainRearLeftDrive = nullptr;
PositionMultiController* Robot::driveTrainRearLeftSteer = nullptr;

MultiController* Robot::driveTrainRearRightDrive = nullptr;
PositionMultiController* Robot::driveTrainRearRightSteer = nullptr;

SwerveModuleInterface* Robot::frontLeftModule = nullptr;
SwerveModuleInterface* Robot::frontRightModule = nullptr;
SwerveModuleInterface* Robot::rearLeftModule = nullptr;
SwerveModuleInterface* Robot::rearRightModule  = nullptr;
#endif

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

Solenoid* Robot::outsol = nullptr;
Solenoid* Robot::insol = nullptr;

double Robot::xCenterOffset = 0;
double Robot::yCenterOffset = 0;


void Robot::DeviceInitialization(){
   CameraServer::GetInstance()->StartAutomaticCapture();
   comp = new Compressor(0);

   insol = new Solenoid(0);
   outsol = new Solenoid(1);

   #if DIFFSWERVE

 /*     driveTrainFrontLeftSteer = new VelocitySparkController(&sparkmax1);
      driveTrainFrontRightSteer = new VelocitySparkController(&sparkmax2);
      driveTrainRearLeftSteer = new VelocitySparkController(&sparkmax3);
      driveTrainRearRightSteer = new VelocitySparkController(&sparkmax4);
      driveTrainFrontLeftDrive = new VelocitySparkController(&sparkmax5);
      driveTrainFrontRightDrive = new VelocitySparkController(&sparkmax6);
      driveTrainRearLeftDrive = new VelocitySparkController(&sparkmax7);
      driveTrainRearRightDrive = new VelocitySparkController(&sparkmax8); */

      driveTrainFrontLeftSteer = new VelocitySparkController(5);
      driveTrainFrontLeftDrive = new VelocitySparkController(6);
      driveTrainFrontRightSteer = new VelocitySparkController(3);
      driveTrainFrontRightDrive = new VelocitySparkController(4);
      driveTrainRearLeftSteer = new VelocitySparkController(7);
      driveTrainRearLeftDrive = new VelocitySparkController(8);
      driveTrainRearRightSteer = new VelocitySparkController(1);
      driveTrainRearRightDrive = new VelocitySparkController(2); 
   #else
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
   #endif

//======= Subsystem Motor Initialization =======//
   //armMotor = new PositionSparkController(ARM);
   clampMotor = new TalonController(CLAMP);
   //frontClimberMotor = new PositionSparkController(FRONTCLIMBER);
   //rearClimberMotor = new PositionSparkController(REARCLIMBER);
   //elevatorMotor = new PositionSparkController(ELEVATOR); 
   //rollerMotor = new TalonController(ROLLER);
   //testElevator = new TalonController(TESTELEVATOR);

   frontServo = new Servo(0);
   rearServo = new Servo(1);
   LOG("DeviceInit Navx");

//======= Sensor and Camera Initialization =======//
#if ONROBORIONAVX
   //navx = new AHRS(I2C::Port::kMXP);
#else
   navx = new AHRS(I2C::Port::kOnboard); //kOnboard ?
#endif

//======= System Initialization =======//
   //arm = new Arm();
   //LOG("DeviceInit Arm");
   clamp = new Clamp();
   LOG("DeviceInit Clamp");
   //climber = new Climber();
   //LOG("DeviceInit Climber");
   //elevator = new Elevator();
   //LOG("DeviceInit Elevator");
   gyroSub = new GyroSub();
   //roller = new Roller();
   //visionBridge = new VisionBridgeSub();
   oi = new OI();

   LOG("DeviceInit Analog");

//======== Swerve Module Initialization =========//
#if DIFFSWERVE
   frontLeftPot = new AnalogInput(2);
   frontRightPot = new AnalogInput(1);
   rearLeftPot = new AnalogInput(3);
   rearRightPot = new AnalogInput(0);

   frontLeftModule = new DiffSwerveModule(driveTrainFrontLeftDrive, driveTrainFrontLeftSteer, Constants::FL_POS_NAME, frontLeftPot);
   frontRightModule = new DiffSwerveModule(driveTrainFrontRightDrive, driveTrainFrontRightSteer, Constants::FR_POS_NAME, frontRightPot);
   rearLeftModule = new DiffSwerveModule(driveTrainRearLeftDrive, driveTrainRearLeftSteer, Constants::RL_POS_NAME, rearLeftPot);
   rearRightModule = new DiffSwerveModule(driveTrainRearRightDrive, driveTrainRearRightSteer, Constants::RR_POS_NAME, rearRightPot);
#else
   frontLeftModule = new SwerveModule(driveTrainFrontLeftDrive, driveTrainFrontLeftSteer, Constants::FL_POS_NAME);
   frontRightModule = new SwerveModule(driveTrainFrontRightDrive, driveTrainFrontRightSteer, Constants::FR_POS_NAME);
   rearLeftModule = new SwerveModule(driveTrainRearLeftDrive, driveTrainRearLeftSteer, Constants::RL_POS_NAME);
   rearRightModule = new SwerveModule(driveTrainRearRightDrive, driveTrainRearRightSteer, Constants::RR_POS_NAME);
#endif
   driveTrain = new DriveTrain();
   LOG("DeviceInit DriveTrain");
   LOG("DeviceInit end");
}

void Robot::AddHeights(){
   auto h = Height::GetInstance();

   h->AddCargoTarget(0, 0); // Starting Position with Elevator Down and Arm In
   h->AddCargoTarget(0, (62 * TESTBOT)); // Floor Pickup
   h->AddCargoTarget(-48, (60 * TESTBOT)); // CargoShip Down
   h->AddCargoTarget(0, (39 * TESTBOT)); // 1st Level Rocket
   h->AddCargoTarget(-43, (41 * TESTBOT)); // 2nd Level Rocket
   h->AddCargoTarget(-81.5, (41 * TESTBOT)); // 3rd Level Rocket

   h->AddHatchTarget(0, 0); // Starting Position with Elevator Down and Arm In / CargoShip / Loading Station 
   h->AddHatchTarget(-44, 0); // 2nd Level Rocket
   h->AddHatchTarget(-81,0); // 3rd Level Rocket

   h->AddClimbingTarget(0,0);
}

void Robot::RobotInit() {
   DeviceInitialization();
   SmartDashboard::PutNumber("Yaw Offset", 0);
   //AddHeights();
   driveTrain->LoadWheelOffsets();
   //Lights::Init();
   //::Mode::SetLED();
   LOG("RobotInit end");
}
   
void Robot::RobotPeriodic() {
   //LOG("robotperiodic start");
   if (navx != nullptr) {
      auto yawOff = SmartDashboard::GetNumber("Yaw Offset", 0);
      SmartDashboard::PutNumber("Yaw", Robot::navx->GetYaw() + yawOff);
   }

   if(oi->GetButtonY()){
      LOG("sol out");
      insol->Set(false);
      outsol->Set(true);
   }else if(oi->GetButtonA()){
      LOG("sol in");
      outsol->Set(false);
      insol->Set(true);
   }

   if(oi->GetButtonX() || oi->GetLeftBumper())
      clampMotor->SetPercentPower(-.3);
   else if(oi->GetButtonB() || oi->GetRightBumper())
      clampMotor->SetPercentPower(.3);
   else
   {
      clampMotor->SetPercentPower(0);
   }
   


	if (frc::RobotController::GetUserButton() == 1 && counter == 0) {
		Robot::driveTrain->SetWheelOffsets();
		counter = 100;
		std::cout << "SetWheelOffsets Complete" << std::endl;
      std::cout.flush();
	}
	if (counter > 0) {
      counter -= 1;
   }

   xCenterOffset = SmartDashboard::GetNumber("X Center Offset", 0);
   yCenterOffset = SmartDashboard::GetNumber("Y Center Offset", 0);
   SmartDashboard::PutNumber("X Center Offset", xCenterOffset);
   SmartDashboard::PutNumber("Y Center Offset", yCenterOffset);

   SmartDashboard::PutNumber("fl position", frontLeftModule->GetSteerPosition());
   SmartDashboard::PutNumber("fr position", frontRightModule->GetSteerPosition());
   SmartDashboard::PutNumber("rl position", rearLeftModule->GetSteerPosition());
   SmartDashboard::PutNumber("rr position", rearRightModule->GetSteerPosition());
 
 
   SmartDashboard::PutNumber("fl setpoint", frontLeftModule->GetSetpoint());
   SmartDashboard::PutNumber("fr setpoint", frontRightModule->GetSetpoint());
   SmartDashboard::PutNumber("rl setpoint", rearLeftModule->GetSetpoint());
   SmartDashboard::PutNumber("rr setpoint", rearRightModule->GetSetpoint());

   SmartDashboard::PutNumber("fl power", frontLeftModule->GetPower());
   SmartDashboard::PutNumber("fr power", frontRightModule->GetPower());
   SmartDashboard::PutNumber("rl power", rearLeftModule->GetPower());
   SmartDashboard::PutNumber("rr power", rearRightModule->GetPower());


   Robot::driveTrain->SetWheelbase(14, 14);

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
      comp->SetClosedLoopControl(true);


}

void Robot::AutonomousPeriodic() {
   frc::Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit() {
      comp->SetClosedLoopControl(true);

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
