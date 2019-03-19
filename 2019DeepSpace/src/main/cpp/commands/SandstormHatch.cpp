#include "commands/SandstormHatch.h"
#include "Robot.h"
#include "OI.h"

// ==========================================================================

SandstormHatch::SandstormHatch(): frc::Command("Sandstorm Hatch") {

}

// ==========================================================================

void SandstormHatch::Initialize() {
	SetTimeout(1);
}

// ==========================================================================

void SandstormHatch::Execute() {
	Robot::arm->ArmDown(0.15);
	Robot::clamp->ClampOut(0.3);
}

// ==========================================================================

bool SandstormHatch::IsFinished() {
	return IsTimedOut();
}

// ==========================================================================

void SandstormHatch::End() {
	Robot::arm->ArmStop();
	Robot::clamp->ClampOut(0.3);
}

// ==========================================================================

void SandstormHatch::Interrupted() {
	End();
}

// ==========================================================================
