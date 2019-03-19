#include "subsystems/Climber.h"
#include "Robot.h"
#include "Commands/ExtendRetractWheelsCommand.h"
#include <iostream>

#define SERVOPASS 45
#define SERVOLOCK 0

Climber::Climber() : frc::Subsystem("Climber") {
}

void Climber::InitDefaultCommand() {
  SetDefaultCommand(new ExtendRetractWheelsCommand());
}

 void Climber::RetractWheels(float _rearSpeed, float _frontSpeed){
   if(Robot::frontClimberMotor != nullptr && Robot::rearClimberMotor != nullptr){
    if(_frontSpeed != 0){
      Robot::frontServo->Set(SERVOPASS);
    }
    if(_rearSpeed != 0){
      Robot::rearServo->Set(SERVOPASS);
    }


    if(Robot::frontClimberMotor->GetEncoderPosition() > 2){
      Robot::frontClimberMotor->SetPercentPower(-_frontSpeed);
    }else{
      Robot::frontClimberMotor->SetPercentPower(-_frontSpeed *0.5);
    }

     if(Robot::rearClimberMotor->GetEncoderPosition() > 2){
      Robot::rearClimberMotor->SetPercentPower(-_rearSpeed);
    }else{
      Robot::rearClimberMotor->SetPercentPower(-_rearSpeed *0.5);
    }

   }
 }

 void Climber::ExtendWheels(float _rearSpeed, float _frontSpeed){
   if(Robot::frontClimberMotor != nullptr && Robot::rearClimberMotor != nullptr){
      Robot::frontClimberMotor->SetPercentPower(_frontSpeed);
      Robot::rearClimberMotor->SetPercentPower(_rearSpeed);
   }
 }

 void Climber::HoldWheels(){
   if(Robot::frontClimberMotor != nullptr && Robot::rearClimberMotor != nullptr){
     Robot::frontClimberMotor->SetPercentPower(0);
     Robot::frontServo->Set(SERVOLOCK);
     Robot::rearClimberMotor->SetPercentPower(0);
     Robot::rearServo->Set(SERVOLOCK);   
   }
 }
