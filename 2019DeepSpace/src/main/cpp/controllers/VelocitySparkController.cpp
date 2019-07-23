#include <iostream>
#include "controllers/VelocitySparkController.h"

#define BOTTOMLIMIT 1

#define kP 0.00005
#define kI 0.000001
#define kD 0
#define kIZONE 0
#define kFF 0.000156
#define kMINOUTPUT -1
#define kMAXOUTPUT 1

#define ENCODER_COUNTS_PER_TURN 42

VelocitySparkController::VelocitySparkController(rev::CANSparkMax* motor){
    _motor = motor;
	ConfigPID();
}

VelocitySparkController::VelocitySparkController(int canId){
	_motor = new rev::CANSparkMax(canId , rev::CANSparkMax::MotorType::kBrushless);
	ConfigPID();
}

void VelocitySparkController::SetPercentPower(double value){
    LOG("The motor controllr is not configured for PercentOutput");
}

double VelocitySparkController::GetEncoderPosition(){
    return _motor->GetEncoder().GetVelocity();
}

void VelocitySparkController::SetVelocity(double value){
	auto pidController = _motor->GetPIDController();
	pidController.SetReference(value, rev::ControlType::kSmartVelocity);
}

void VelocitySparkController::ConfigPID(){
	kMaxVel = 5500, kMinVel = 0, kMaxAcc = 6000, kAllErr = 0;
	auto pidController = _motor->GetPIDController();
	_motor->RestoreFactoryDefaults();
	pidController.SetP(kP);
	pidController.SetI(kI);
	pidController.SetD(kD);
	pidController.SetIZone(kIZONE);
	pidController.SetFF(kFF);
	pidController.SetOutputRange(kMINOUTPUT, kMAXOUTPUT);	
    pidController.SetSmartMotionMaxVelocity(kMaxVel);
    pidController.SetSmartMotionMinOutputVelocity(kMinVel);
    pidController.SetSmartMotionMaxAccel(kMaxAcc);
    pidController.SetSmartMotionAllowedClosedLoopError(kAllErr);
}