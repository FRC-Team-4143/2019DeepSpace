// ==========================================================================
// GyroSub class
// The GyroSub subsystem represents the NavX accelerometer.
//
// FRC 4143: MARS/WARS
// ==========================================================================
#include "subsystems/GyroSub.h"
#include "Robot.h"

// ==========================================================================

GyroSub::GyroSub(): Subsystem("GyroSub") {

}

// ==========================================================================

void GyroSub::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MyCommand());
}

// ==========================================================================
// PIDSource methods
// ==========================================================================

double GyroSub::PIDGet() { return theGyro()->GetYaw(); }

// ==========================================================================
// Put methods for controlling this subsystem here.
// Call these from Commands.
// ==========================================================================

double GyroSub::GetHeading() { return theGyro()->GetCompassHeading(); }

// ==========================================================================

bool GyroSub::IsCalibrating() { return theGyro()->IsCalibrating(); }

// ==========================================================================

void GyroSub::ResetGyro() {
	//theGyro()->ResetDisplacement();
	theGyro()->ZeroYaw();
}

// ==========================================================================

float GyroSub::GetDisplacementX() { return theGyro()->GetDisplacementX(); }

// ==========================================================================

float GyroSub::GetDisplacementY() { return theGyro()->GetDisplacementY(); }

// ==========================================================================

AHRS* GyroSub::theGyro() {
	return Robot::navx;
}

// ==========================================================================
