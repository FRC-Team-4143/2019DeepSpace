#pragma once
#define DIFFSWERVE 1

#include <frc/TimedRobot.h>
#include <frc/commands/Command.h>
#include <frc/smartdashboard/SendableChooser.h>
#include <frc/WPILib.h>
#include <rev/CANSparkMax.h>
#include <rev/SparkMax.h>
#include <ctre/Phoenix.h>
#include <AHRS.h>
#include <frc/I2C.h>

#include "controllers/PositionMultiController.h"
#include "Modules/SwerveModuleInterface.h"

#include "OI.h"
#include "subsystems/Elevator.h"
#include "subsystems/Arm.h"
#include "subsystems/Roller.h"
#include "subsystems/Clamp.h"
#include "subsystems/Climber.h"
#include "subsystems/DriveTrain.h"
#include "subsystems/GyroSub.h"
#include "subsystems/VisionBridgeSub.h"

class Robot : public frc::TimedRobot {
 public:

//======= System Declaration =======//
  static OI* oi;
  static Arm* arm;
  static Clamp* clamp;
  static Climber* climber;
  static DriveTrain* driveTrain;
  static Elevator* elevator;
  static GyroSub* gyroSub;
  static Roller* roller;
  static VisionBridgeSub* visionBridge;
  static PowerDistributionPanel* pdp;
  static Compressor* comp;

//======= Drive Train =======//
#if DIFFSWERVE
  static VelocityMultiController* driveTrainFrontLeftDrive;
  static VelocityMultiController* driveTrainFrontLeftSteer;

  static VelocityMultiController* driveTrainFrontRightDrive;
  static VelocityMultiController* driveTrainFrontRightSteer;

  static VelocityMultiController* driveTrainRearLeftDrive;
  static VelocityMultiController* driveTrainRearLeftSteer;

  static VelocityMultiController* driveTrainRearRightDrive;
  static VelocityMultiController* driveTrainRearRightSteer;

  static SwerveModuleInterface* frontLeftModule;
  static SwerveModuleInterface* frontRightModule;
  static SwerveModuleInterface *rearLeftModule;
  static SwerveModuleInterface* rearRightModule;

  static AnalogInput* frontLeftPot;
  static AnalogInput* frontRightPot;
  static AnalogInput* rearLeftPot;
  static AnalogInput* rearRightPot;

  static Solenoid* outsol;
  static Solenoid* insol;

 /* rev::CANSparkMax sparkmax1{1, rev::CANSparkMax::MotorType::kBrushless};
  rev::CANSparkMax sparkmax2{2, rev::CANSparkMax::MotorType::kBrushless};
  rev::CANSparkMax sparkmax3{3, rev::CANSparkMax::MotorType::kBrushless};
  rev::CANSparkMax sparkmax4{4, rev::CANSparkMax::MotorType::kBrushless};
  rev::CANSparkMax sparkmax5{5, rev::CANSparkMax::MotorType::kBrushless};
  rev::CANSparkMax sparkmax6{6, rev::CANSparkMax::MotorType::kBrushless};
  rev::CANSparkMax sparkmax7{7, rev::CANSparkMax::MotorType::kBrushless};
  rev::CANSparkMax sparkmax8{8, rev::CANSparkMax::MotorType::kBrushless}; */
 
#else
  static MultiController* driveTrainFrontLeftDrive;
  static PositionMultiController* driveTrainFrontLeftSteer;

  static MultiController* driveTrainFrontRightDrive;
  static PositionMultiController* driveTrainFrontRightSteer;

  static MultiController* driveTrainRearLeftDrive;
  static PositionMultiController* driveTrainRearLeftSteer;

  static MultiController* driveTrainRearRightDrive;
  static PositionMultiController* driveTrainRearRightSteer;

  static SwerveModuleInterface* frontLeftModule;
  static SwerveModuleInterface* frontRightModule;
  static SwerveModuleInterface *rearLeftModule;
  static SwerveModuleInterface* rearRightModule;
#endif

//======= Susystem Motors and Sensors =======//
  static PositionMultiController* armMotor;
  static MultiController* clampMotor;
  static MultiController* frontClimberMotor;
  static MultiController* rearClimberMotor;
  static PositionMultiController* elevatorMotor;
  static MultiController* rollerMotor;
  static MultiController* testElevator;

  static Servo* frontServo;
  static Servo* rearServo;

  static AHRS* navx;

//===========================================//

  void DeviceInitialization();
  void AddHeights();
  void RobotInit() override;
  void RobotPeriodic() override;
  void DisabledInit() override;
  void DisabledPeriodic() override;
  void AutonomousInit() override;
  void AutonomousPeriodic() override;
  void TeleopInit() override;
  void TeleopPeriodic() override;
  void TestPeriodic() override;

  int counter = 0;
  int hatchCounter = 0;
  static double xCenterOffset;
  static double yCenterOffset;

 private:
  // Have it null by default so that if testing teleop it
  // doesn't have undefined behavior and potentially crash.
};
