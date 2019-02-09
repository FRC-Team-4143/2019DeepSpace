#pragma once
#include <ctre/Phoenix.h>
#include "controllers/MultiController.h"

class TalonController : public MultiController  {
public:
    TalonController(WPI_TalonSRX* motor);
    TalonController(int canId);
    virtual void SetPercentPower(double value) override;
    virtual double GetEncoderPosition() override;
    virtual void SetPosition(double value, double deadzone) override;

private:
    WPI_TalonSRX* _motor;
};
