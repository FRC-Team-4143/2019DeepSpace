#include "commands/HatchLineUp.h"
#include "modules/Logger.h"
#include "Robot.h"

// ==========================================================================

HatchLineUp::HatchLineUp(): frc::Command("HatchLineUp"),
	_timeoutSeconds(2.5),
	_counter(0), _waiting(0), _waitingCounter(0),
	_angle(0),
	_tol(0),
	_center(0) {
	Requires(Robot::driveTrain);
}

// ==========================================================================

void HatchLineUp::Initialize() {
	LOG(GetName() + "::Initialize");

	_counter = 0;
	_waiting = 0;
	_waitingCounter = 0;
	_angle = Robot::gyroSub->PIDGet();
	_angle /= 90.;
	_angle = floor(_angle + .5); // round
	_angle *= 90.;
	_tol = SmartDashboard::GetNumber("vision tol", 5);
	_center = SmartDashboard::GetNumber("vision center", 0.0);
	//Robot::driveTrain->enablePositionControl();
	SetTimeout(_timeoutSeconds);
}

// ==========================================================================

void HatchLineUp::Execute() {

	float pixels = Robot::visionBridge->GetBoilerPosition() - SmartDashboard::GetNumber("vision center", 0);
	SmartDashboard::PutNumber("GearPixels", pixels);

	float yaw = Robot::gyroSub->PIDGet();
	float desiredangle = 0;

	
	if(yaw > 45 && yaw < 135){
		desiredangle = 90;
	} else if((yaw > 135 && yaw < 179) || (yaw < -135 && yaw > -179)){
		desiredangle = 180; 
	} else if(yaw > -135 && yaw < -45){
		desiredangle = -90;
	}else if (yaw < 45 && yaw > -45){
		desiredangle = 0;
	}

	float twist = desiredangle - yaw;
	while (twist > 180.0) {
		twist -= 360.0;
	}
	while (twist < -180.0) {
		twist += 360.0;
	}

	twist = std::min(0.2, std::max(-0.2, twist * (0.2/10)));
	pixels = std::min(0.2, std::max(-0.2, pixels * .001));    // .2 / 100 pixels

  		Robot::driveTrain->Crab(twist, 0.3, -pixels, false);
		if (fabs(pixels) < _tol)
			_counter++;

		SmartDashboard::PutNumber("Autonomous Counter", _counter);

	//}
	_waiting++;
	if (_waiting > 20) {
		_waiting = 0;
	}

	//SmartDashboard::PutNumber("Angle Error", angleError);
	//Robot::driveTrain->PositionModeTwist(0);
}

// ==========================================================================

bool HatchLineUp::IsFinished() {
	return false; //IsTimedOut() || _counter > 50;
}

// ==========================================================================

void HatchLineUp::End() {
	LOG(GetName() + "::End");
	_Cleanup();
}

// ==========================================================================

void HatchLineUp::Interrupted() {
	LOG(GetName() + "::Interrupted");
	_Cleanup();
}

// ==========================================================================

void HatchLineUp::_Cleanup() {
	Robot::driveTrain->Crab(0, 0, 0, false);
	_counter = 0;
}

// ==========================================================================
