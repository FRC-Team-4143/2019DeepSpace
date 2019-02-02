#include "Robot.h"
#include <frc/commands/Scheduler.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include "Modules/Lights.h"
#include "Modules/Mode.h"

#include "subsystems/Arm.h"
#include "subsystems/Elevator.h"
#include "subsystems/Roller.h"
#include "subsystems/Clamp.h"

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
rev::CANSparkMax* Robot::armMotor;
rev::CANSparkMax* Robot::frontClimberMotor;
rev::CANSparkMax* Robot::rearClimberMotor;

Servo* Robot::frontServo;
Servo* Robot::rearServo;

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
   armMotor = new rev::CANSparkMax(ARM,rev::CANSparkMaxLowLevel::MotorType::kBrushless);
   frontClimberMotor = new rev::CANSparkMax(FRONTCLIMBER,rev::CANSparkMaxLowLevel::MotorType::kBrushless);
   rearClimberMotor = new rev::CANSparkMax(REARCLIMBER,rev::CANSparkMaxLowLevel::MotorType::kBrushless);

   frontServo = new Servo(0);
   rearServo = new Servo(1);

//======= System Initialization =======//
   elevator = new Elevator();
   arm = new Arm();
   roller = new Roller();
   clamp = new Clamp();
   climber = new Climber();
   oi = new OI();
}

void Robot::RobotInit() {
   DeviceInitialization();
   Lights::Init();
   ::Mode::SetLED();
}
   
void Robot::RobotPeriodic() {
   if(elevatorMotor == nullptr)
   {
      SmartDashboard::PutNumber("Elevator Encoder Position", elevatorMotor->GetEncoder().GetPosition());
   }
   if(armMotor == nullptr)
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
int main() { return frc::StartRobot<Robot>(); }
#endif
