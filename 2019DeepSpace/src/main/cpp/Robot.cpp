#include "Robot.h"
#include <frc/commands/Scheduler.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <iostream>

#include "controllers/TalonController.h"
#include "controllers/SteerTalonController.h"
#include "controllers/SparkMaxController.h"
#include "controllers/PositionSparkController.h"

#include "Modules/Lights.h"
#include "Modules/Mode.h"
#include "Modules/Logger.h"
#include "Modules/Height.h"

#define USINGSPARKMAXDRIVE 0

#define TESTELEVATOR 21
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
GyroSub* Robot::gyroSub = nullptr;

//======= Motor Definition =======//
MultiController* Robot::driveTrainFrontLeftDrive;
PositionMultiController* Robot::driveTrainFrontLeftSteer;

MultiController* Robot::driveTrainFrontRightDrive;
PositionMultiController* Robot::driveTrainFrontRightSteer;

MultiController* Robot::driveTrainRearLeftDrive;
PositionMultiController* Robot::driveTrainRearLeftSteer;

MultiController* Robot::driveTrainRearRightDrive;
PositionMultiController* Robot::driveTrainRearRightSteer;

PositionMultiController* Robot::elevatorMotor;
PositionMultiController* Robot::armMotor;
MultiController* Robot::testElevator;
MultiController* Robot::rollerMotor;
MultiController* Robot::clampMotor;
MultiController* Robot::frontClimberMotor;
MultiController* Robot::rearClimberMotor;

Servo* Robot::frontServo;
Servo* Robot::rearServo;
Servo* Robot::hatchServo;

AHRS* Robot::navx;

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
   testElevator = new TalonController(TESTELEVATOR);
   elevatorMotor = new PositionSparkController(ELEVATOR);
   rollerMotor = new TalonController(ROLLER);
   clampMotor = new TalonController(CLAMP);
   armMotor = new PositionSparkController(ARM);
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
   gyroSub = new GyroSub();

//======= Sensor Initialization =======//

   navx = new AHRS(I2C::Port::kOnboard);
}

void Robot::AddHeights(){
   auto h = Height::GetInstance();

   h.AddCargoTarget(0, 0); // Starting Position with Elevator Down and Arm In / CargoShip
   h.AddCargoTarget(10, 50); // Floor Pickup
   h.AddCargoTarget(15, 50); // 1st Level Rocket
   h.AddCargoTarget(15, 0); // 2nd Level Rocket
   h.AddCargoTarget(30, 25); // 3rd Level Rocket

   h.AddHatchTarget(0, 0); // Starting Position with Elevator DOwn and Arim In / CargoShip / Floor Pickup / Loading Station 
   h.AddHatchTarget(10, 0); // 2nd Level Rocket
   h.AddHatchTarget(25,0); // 3rd Level Rocket

   h.AddClimbingTarget(0,0);
}

void Robot::RobotInit() {
   DeviceInitialization();
   AddHeights();
   driveTrain->LoadWheelOffsets();
   Lights::Init();
   ::Mode::SetLED();
}
   
void Robot::RobotPeriodic() {

   SmartDashboard::PutNumber("Yaw", Robot::navx->GetYaw());

	if(frc::RobotController::GetUserButton() == 1 && counter == 0){
		Robot::driveTrain->SetWheelOffsets();
		counter = 100;
		std::cout << "SetWheelOffsets Complete" << std::endl;
      std::cout.flush();
	}
	if(counter > 0) counter -= 1;


   if(elevatorMotor != nullptr){
      SmartDashboard::PutNumber("Elevator Encoder Position", elevatorMotor->GetEncoderPosition());
   }
   if(armMotor != nullptr){
      SmartDashboard::PutNumber("Arm Encoder Position", armMotor->GetEncoderPosition());
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
   return frc::StartRobot<Robot>();
    }
#endif
