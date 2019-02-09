#pragma once
#include <ctre/Phoenix.h>
#include "controllers/PositionMultiController.h"

class SteerTalonController : public PositionMultiController  {
public:
    SteerTalonController(WPI_TalonSRX* motor);
    SteerTalonController(int canId);
    virtual void SetPercentPower(double value) override;
    virtual double GetEncoderPosition() override;
    virtual void SetPosition(double value) override;
    void ConfigPID();


private:
    WPI_TalonSRX* _motor;
};
