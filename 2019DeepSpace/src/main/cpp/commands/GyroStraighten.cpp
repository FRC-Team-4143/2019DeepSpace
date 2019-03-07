#include "commands/GyroStraighten.h"
#include "Robot.h"

GyroStraighten::GyroStraighten() {
	// Use Requires() here to declare subsystem dependencies
	Requires(Robot::driveTrain);
}

void GyroStraighten::Initialize() {
}

void GyroStraighten::Execute() {

	auto yaw = Robot::gyroSub->PIDGet();

	if(yaw > 45 && yaw < 135){
		Robot::driveTrain->GyroRotate(90, 0.25);
	} else if((yaw > 135 && yaw < 179) || (yaw < -135 && yaw > -179)){
	 Robot::driveTrain->GyroRotate(180, 0.25);
	} else if(yaw > -135 && yaw < -45){
		Robot::driveTrain->GyroRotate(-90, 0.25);
	}else if (yaw < 45 && yaw > -45){
		Robot::driveTrain->GyroRotate(0, 0.25);
	}

	/* Rocket at 60 degrees
	if(yaw > 30 && yaw < 75){

	}
	*/
}


bool GyroStraighten::IsFinished() {
	return false;
}

void GyroStraighten::End() {
}

void GyroStraighten::Interrupted() {
	End();
}
