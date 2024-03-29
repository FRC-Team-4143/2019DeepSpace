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

double GyroSub::PIDGet() { 
	if(theGyro() != nullptr){
		return theGyro()->GetYaw() + (SmartDashboard::GetNumber("Yaw Offset", 0)); 
	}
	return 0;
}

// ==========================================================================
// Put methods for controlling this subsystem here.
// Call these from Commands.
// ==========================================================================

double GyroSub::GetHeading() { 
	if(theGyro() != nullptr){
		return theGyro()->GetCompassHeading(); 
	}
		return 0;
}

// ==========================================================================

bool GyroSub::IsCalibrating(){ 
		if(theGyro() != nullptr){
			return theGyro()->IsCalibrating();
		}
		return false;
	}

// ==========================================================================

void GyroSub::ResetGyro() {
	if(theGyro() != nullptr){
		theGyro()->ZeroYaw();
	}
}

// ==========================================================================

float GyroSub::GetDisplacementX() { 
	if(theGyro() != nullptr){
		return theGyro()->GetDisplacementX(); 
	}
	return 0;
}

// ==========================================================================

float GyroSub::GetDisplacementY() { 
	if(theGyro() != nullptr){
		return theGyro()->GetDisplacementY(); 
	}
	return 0;
}

// ==========================================================================

AHRS* GyroSub::theGyro() {
	return Robot::navx;
}

// ==========================================================================
