#pragma once


class MultiController {
public:
    virtual void SetPercentPower(double value) = 0;
    virtual double GetEncoderPosition() = 0;

};
