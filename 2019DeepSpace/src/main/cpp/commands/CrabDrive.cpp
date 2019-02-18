#include "commands/CrabDrive.h"
#include "Robot.h"

CrabDrive::CrabDrive() {
  // Use Requires() here to declare subsystem dependencies
  Requires(Robot::driveTrain);
}

void CrabDrive::Initialize() {
	SmartDashboard::PutString("Driving Mode","Crab Drive");
}

void CrabDrive::Execute() {
	float x = 0;
	float y = 0;
	float z = 0;
	if (!DriverStation::GetInstance().IsAutonomous()) {
		x = Robot::oi->GetJoystickX();
		y = Robot::oi->GetJoystickY();
		z = Robot::oi->GetJoystickZ();
	}

	//x *= (x < 0 ? -x: x);
	//z *= (z < 0 ? -z: z);
	if (fabs(y) > 0.5)
		z *= 0.75;
	//y *= (y < 0 ? -y: y);

	if(Robot::oi->GetButtonLeft() == false){
		Robot::driveTrain->Crab(z, -y, x, true);
		SmartDashboard::PutString("Driving Speed","Full");
	}
	else{
		Robot::driveTrain->Crab(z/2, -y/2, x/2, true);
		SmartDashboard::PutString("Driving Speed","Half");
	}

}

bool CrabDrive::IsFinished() { return false; }

void CrabDrive::End() {
  SmartDashboard::PutString("Driving Mode","Unknown");
}

void CrabDrive::Interrupted() {
  End();
}