#include "commands/HatchLineUp.h"
#include <networktables/NetworkTable.h>
#include <networktables/NetworkTableEntry.h>
#include <networktables/NetworkTableInstance.h>
#include "Robot.h"

HatchLineUp::HatchLineUp() {
	Requires(Robot::driveTrain);
}

void HatchLineUp::Initialize() {

  SmartDashboard::PutString("Driving Mode","Hatch LineUp");

  _timeoutSeconds = 10;
  _counter = 0;
	_waiting = 0;
	_waitingCounter = 0;
	_angle = Robot::gyroSub->PIDGet();
	_angle /= 90.;
	_angle = floor(_angle + .5); // round
	_angle *= 90.;
  _tol = SmartDashboard::GetNumber("vision tol", 1);
	_center = SmartDashboard::GetNumber("vision center", 0.0);
	SetTimeout(_timeoutSeconds);

}

void HatchLineUp::Execute() {

  auto tapeYaw = nt::NetworkTableInstance::GetDefault().GetTable("ChickenVision")->GetEntry("tapeYaw");
  _yaw = tapeYaw.GetDouble(0.0);
  auto pixels = _yaw - _center;
	pixels *= 1;
	

		if (pixels < -_tol) {
			Robot::driveTrain->Crab(0, -0.2, 0, false);
		} else if (pixels > _tol){
			Robot::driveTrain->Crab(0, 0.2, 0, false);
		} else {
			Robot::driveTrain->Crab(0, 0, 0, false);
		}
		if (fabs(pixels) < _tol)
			_counter++;
		

	//}
	_waiting++;
	if (_waiting > 20) {
		_waiting = 0;
  }
}

bool HatchLineUp::IsFinished() {
  return IsTimedOut() || _counter > 50;
}

void HatchLineUp::End() {
  Robot::driveTrain->Crab(0, 0, 0, false);
  SmartDashboard::PutString("Driving Mode","Unknown");

}

void HatchLineUp::Interrupted() {
  End();
}
