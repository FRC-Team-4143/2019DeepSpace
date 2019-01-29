// ==========================================================================
// Constants class
//
// FRC 4143 "MARS WARS"
// ==========================================================================
// 2015-02-01 JKSalmon - Initial development
// ==========================================================================
#include "Modules/Lights.h"
#include "iostream"
// ==========================================================================

frc::I2C* Lights::i2c = nullptr;


void Lights::SetCargoLights()
{
    i2c->Write(1 , 0);
    std::cout << "CargoMode";
}

void Lights::SetHatchLights()
{
    i2c->Write(2 , 0);
    std::cout << "HatchMode";
}

void Lights::SetEndGameLights()
{
    i2c->Write(3 , 0);
    std::cout << "EndGameMode";
}

void Lights::Init()
{
    i2c = new frc::I2C((frc::I2C::Port) 1, 0x04);

}
// ==========================================================================
