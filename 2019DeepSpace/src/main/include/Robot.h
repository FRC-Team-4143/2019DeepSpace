#pragma once

#include <frc/TimedRobot.h>
#include <frc/commands/Command.h>
#include <frc/smartdashboard/SendableChooser.h>
#include <rev/CANSparkMax.h>
#include <rev/SparkMax.h>
#include <ctre/Phoenix.h>


#include "OI.h"
#include <subsystems/Elevator.h>
#include <subsystems/Arm.h>
#include <subsystems/Roller.h>
#include <subsystems/Clamp.h>

class Robot : public frc::TimedRobot {
 public:

//======= System Declaration =======//
  static OI* oi;
  static Elevator* elevator;
  static Roller* roller;
  static Clamp* clamp;
  static Arm* arm;



//======= Drive Train =======//
  static WPI_TalonSRX* driveTrainFrontLeftDrive;
  static WPI_TalonSRX* driveTrainFrontLeftSteer;

  static WPI_TalonSRX* driveTrainFrontRightDrive;
  static WPI_TalonSRX* driveTrainFrontRightSteer;

  static WPI_TalonSRX* driveTrainRearLeftDrive;
  static WPI_TalonSRX* driveTrainRearLeftSteer;

  static WPI_TalonSRX* driveTrainRearRightDrive;
  static WPI_TalonSRX* driveTrainRearRightSteer;



//======= Susystem Motors and Sensors =======//
  static rev::CANSparkMax* elevatorMotor;
  static WPI_TalonSRX* rollerMotor;
  static WPI_TalonSRX* clampMotor;
  static Servo* servo1;
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

 private:
  // Have it null by default so that if testing teleop it
  // doesn't have undefined behavior and potentially crash.
};
