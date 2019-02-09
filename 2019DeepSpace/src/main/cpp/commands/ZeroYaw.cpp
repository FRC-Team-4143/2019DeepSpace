#include "commands/ZeroYaw.h"
#include "Robot.h"
#include "OI.h"

// ==========================================================================

ZeroYaw::ZeroYaw() {
	SetRunWhenDisabled(true);
}

// ==========================================================================

void ZeroYaw::Initialize() {
}

// ==========================================================================

void ZeroYaw::Execute() {
	Robot::navx->ZeroYaw();
}

// ==========================================================================

bool ZeroYaw::IsFinished() {
	return true;
}

// ==========================================================================

void ZeroYaw::End() {
}

// ==========================================================================

void ZeroYaw::Interrupted() {
	End();
}

// ==========================================================================
