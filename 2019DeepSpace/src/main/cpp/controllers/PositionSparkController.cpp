#include "controllers/PositionSparkController.h"

#define kP 0.1
#define kI 0.00001
#define kD 1
#define kIZONE 0
#define kFF 0
#define kMINOUTPUT -1
#define kMAXOUTPUT 1

#define ENCODER_COUNTS_PER_TURN 42

PositionSparkController::PositionSparkController(rev::CANSparkMax* motor){
    _motor = motor;
}

PositionSparkController::PositionSparkController(int canId){
	_motor = new rev::CANSparkMax(canId , rev::CANSparkMaxLowLevel::MotorType::kBrushless);
}

void PositionSparkController::SetPercentPower(double value){
    _motor->Set(value);
}

double PositionSparkController::GetEncoderPosition(){
    return _motor->GetEncoder().GetPosition();
}

void PositionSparkController::SetPosition(double value){
   	auto pidController = _motor->GetPIDController();
	
	pidController.SetReference(value * ENCODER_COUNTS_PER_TURN, rev::ControlType::kPosition);
}

void PositionSparkController::ConfigPID(){
	auto pidController = _motor->GetPIDController();

	pidController.SetP(kP);
	pidController.SetI(kI);
	pidController.SetD(kD);
	pidController.SetIZone(kIZONE);
	pidController.SetFF(kFF);
	pidController.SetOutputRange(kMINOUTPUT, kMAXOUTPUT);	
}