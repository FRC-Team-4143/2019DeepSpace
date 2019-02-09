#pragma once

#include <frc/TimedRobot.h>
#include <frc/commands/Command.h>
#include <frc/smartdashboard/SendableChooser.h>
#include <frc/WPILib.h>
#include <rev/CANSparkMax.h>
#include <rev/SparkMax.h>
#include <ctre/Phoenix.h>
#include "controllers/MultiController.h"
#include "controllers/TalonController.h"
#include "controllers/SteerTalonController.h"
#include "controllers/SparkMaxController.h"

#include "OI.h"
#include "subsystems/Elevator.h"
#include "subsystems/Arm.h"
#include "subsystems/Roller.h"
#include "subsystems/Clamp.h"
#include "subsystems/Climber.h"
#include "subsystems/DriveTrain.h"

class Robot : public frc::TimedRobot {
 public:

//======= System Declaration =======//
  static OI* oi;
  static Elevator* elevator;
  static Roller* roller;
  static Clamp* clamp;
  static Arm* arm;
  static Climber* climber;
  static DriveTrain* driveTrain;



//======= Drive Train =======//

  static MultiController* driveTrainFrontLeftDrive;
  static MultiController* driveTrainFrontLeftSteer;

  static MultiController* driveTrainFrontRightDrive;
  static MultiController* driveTrainFrontRightSteer;

  static MultiController* driveTrainRearLeftDrive;
  static MultiController* driveTrainRearLeftSteer;

  static MultiController* driveTrainRearRightDrive;
  static MultiController* driveTrainRearRightSteer;


//======= Susystem Motors and Sensors =======//
  static rev::CANSparkMax* elevatorMotor;
  static MultiController* rollerMotor;
  static MultiController* clampMotor;
  static MultiController* frontClimberMotor;
  static MultiController* rearClimberMotor;
  static Servo* frontServo;
  static Servo* rearServo;
  static Servo* hatchServo;
  static rev::CANSparkMax* armMotor;

//===========================================//

  void DeviceInitialization();
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

 private:
  // Have it null by default so that if testing teleop it
  // doesn't have undefined behavior and potentially crash.
};
