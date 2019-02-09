#pragma once
#include <ctre/Phoenix.h>
#include "controllers/MultiController.h"

class SteerTalonController : public MultiController  {
public:
    SteerTalonController(WPI_TalonSRX* motor);
    SteerTalonController(int canId);
    virtual void SetPercentPower(double value) override;
    virtual double GetEncoderPosition() override;
    virtual void SetPosition(double value, double deadzone) override;
    void ConfigPID();


private:
    WPI_TalonSRX* _motor;
};
