#pragma once
#include <rev/CANSparkMax.h>
#include "controllers/MultiController.h"

class SparkMaxController : public MultiController  {
public:
    SparkMaxController(rev::CANSparkMax* motor);
    SparkMaxController(int canId);
    virtual void SetPercentPower(double value) override;
    virtual double GetEncoderPosition() override;
    virtual void SetPosition(double value, double deadzone) override;

private:
    rev::CANSparkMax* _motor;
};
