#include "Commands/AcquireGamePiece.h"
#include "Robot.h"
#include "Modules/Mode.h"

AcquireGamePiece::AcquireGamePiece() {
	Requires(Robot::roller);
	Requires(Robot::clamp);
}

void AcquireGamePiece::Initialize() {
}

void AcquireGamePiece::Execute() {
	if (Mode::IsCargoMode()){
		Robot::roller->RollerIn(1);
	}
	else if (Mode::IsHatchMode()) {
		Robot::clamp->ClampOut(.25);
	}
}

bool AcquireGamePiece::IsFinished() {
	return false;
}

void AcquireGamePiece::End() {
	Robot::roller->RollerStop();
	Robot::clamp->ClampStop();
}

void AcquireGamePiece::Interrupted() {
	End();
}
