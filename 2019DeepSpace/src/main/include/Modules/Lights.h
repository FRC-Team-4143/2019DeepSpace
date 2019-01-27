// ==========================================================================
// Constants class
//
// FRC 4143 "MARS WARS"
// ==========================================================================
// 2015-02-01 JKSalmon - Initial development
// ==========================================================================
#pragma once
#include <frc/I2C.h>
// ==========================================================================

class Lights {
public:
	static void SetCargoLights();
	static void SetHatchLights();
	static void SetEndGameLights();
	static void Init();

private:

	static frc::I2C* i2c;


};

// ==========================================================================
