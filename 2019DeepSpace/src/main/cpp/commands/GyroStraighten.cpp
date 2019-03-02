#include "commands/GyroStraighten.h"
#include "Robot.h"

GyroStraighten::GyroStraighten() {
	// Use Requires() here to declare subsystem dependencies
	Requires(Robot::driveTrain);
}

void GyroStraighten::Initialize() {
}

void GyroStraighten::Execute() {

	if(Robot::gyroSub->PIDGet() > 45 && Robot::gyroSub->PIDGet() < 135){
		Robot::driveTrain->GyroRotate(90, 0.25);
	} else if((Robot::gyroSub->PIDGet() > 135 && Robot::gyroSub->PIDGet() < 179) || (Robot::gyroSub->PIDGet() < -135 && Robot::gyroSub->PIDGet() > -179)){
	 Robot::driveTrain->GyroRotate(180, 0.25);
	} else if(Robot::gyroSub->PIDGet() > -135 && Robot::gyroSub->PIDGet() < -45){
		Robot::driveTrain->GyroRotate(-90, 0.25);
	}else if (Robot::gyroSub->PIDGet() < 45 && Robot::gyroSub->PIDGet() > -45){
		Robot::driveTrain->GyroRotate(0, 0.25);
	}
}


bool GyroStraighten::IsFinished() {
	return false;
}

void GyroStraighten::End() {
}

void GyroStraighten::Interrupted() {
	End();
}
