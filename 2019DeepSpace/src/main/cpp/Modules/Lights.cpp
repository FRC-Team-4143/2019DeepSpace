
#include "Modules/Lights.h"
#include "iostream"
// ==========================================================================

frc::I2C* Lights::i2c = nullptr;


void Lights::SetCargoLights()
{
    i2c->Write(1 , 0);
    frc::SmartDashboard::PutString("GameMode: ", "Cargo");
}

void Lights::SetHatchLights()
{
    i2c->Write(2 , 0);
    frc::SmartDashboard::PutString("GameMode: ", "Hatch");
}

void Lights::SetEndGameLights()
{
    i2c->Write(6, 0);
    frc::SmartDashboard::PutString("GameMode: ", "EndGame");
}

void Lights::Init()
{
    i2c = new frc::I2C((frc::I2C::Port) 1, 0x04);

}
// ==========================================================================
