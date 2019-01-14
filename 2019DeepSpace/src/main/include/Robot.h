#pragma once

#include <frc/TimedRobot.h>
#include <frc/commands/Command.h>
#include <frc/smartdashboard/SendableChooser.h>
#include <rev/CANSparkMax.h>
#include <ctre/Phoneix.h>


#include "OI.h"
#include "subsystems/Elevator.h"

class Robot : public frc::TimedRobot {
 public:

//======= System Declaration =======//

  static OI oi;
  static Elevator* elevator;

//======= Drive Train =======//

  static rev::CANSparkMax* driveTrainFrontLeftDrive;
  static rev::CANSparkMax* driveTrainFrontLeftSteer;

  static rev::CANSparkMax* driveTrainFrontRightDrive;
  static rev::CANSparkMax* driveTrainFrontRightSteer;

  static rev::CANSparkMax* driveTrainRearLeftDrive;
  static rev::CANSparkMax* driveTrainRearLeftSteer;

  static rev::CANSparkMax* driveTrainRearRightDrive;
  static rev::CANSparkMax* driveTrainRearRightSteer;


//======= Susystem Motors and Sensors =======//

  static rev::CANSparkMax* decoyMotor; // Motor to allow tests on incomplete frames
  static rev::CANSparkMax* elevatorMotor;

//===========================================//

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
