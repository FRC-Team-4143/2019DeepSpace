#include "controllers/SparkMaxController.h"

SparkMaxController::SparkMaxController(rev::CANSparkMax* motor){
    _motor = motor;
}

SparkMaxController::SparkMaxController(int canId){
    _motor = new rev::CANSparkMax(canId , rev::CANSparkMaxLowLevel::MotorType::kBrushless);
}

void SparkMaxController::SetPercentPower(double value){
    _motor->Set(value);
}

double SparkMaxController::GetEncoderPosition(){
    return _motor->GetEncoder().GetPosition();
}

void SparkMaxController::SetPosition(double value, double deadzone){
    if(GetEncoderPosition() > (value + deadzone)){
        _motor->Set(-(GetEncoderPosition() - value)/1); // 1 is a placeholder
    } else if(GetEncoderPosition() > (value - deadzone)){
        _motor->Set((GetEncoderPosition() - value)/1); // 1 is a placeholder
    }else{
        _motor->Set(0);
    }
}
