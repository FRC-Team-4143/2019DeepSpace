#include "subsystems/Climber.h"
#include "Robot.h"
#include "Commands/ClimberTest.h"
#include <iostream>

#define SERVOPASS 45
#define SERVOLOCK 0

Climber::Climber() : frc::Subsystem("Climber") {
}

void Climber::InitDefaultCommand() {
  SetDefaultCommand(new ClimberTest());
}

 void Climber::RetractWheels(char _side, float _speed){
   if(Robot::frontClimberMotor != nullptr && Robot::rearClimberMotor != nullptr){
     if(_side == 'F'){
       Robot::frontServo->Set(SERVOPASS);
       if(Robot::frontServo->GetAngle() == SERVOPASS){
         Robot::frontClimberMotor->Set(_speed);
         Robot::rearClimberMotor->Set(0);
       }
     }else if(_side == 'R'){
       Robot::rearServo->Set(SERVOPASS);
       if(Robot::rearServo->GetAngle() == SERVOPASS){
         Robot::rearClimberMotor->Set(-_speed);
         Robot::frontClimberMotor->Set(0);
       }
     }else{
       Robot::frontServo->Set(SERVOPASS);
       Robot::rearServo->Set(SERVOPASS);
       if(Robot::frontServo->GetAngle() == SERVOPASS && Robot::rearServo->GetAngle() == SERVOPASS){
       Robot::frontClimberMotor->Set(_speed);
       Robot::rearClimberMotor->Set(-_speed);
       }
     }
   }
 }

 void Climber::ExtendWheels(char _side, float _speed){
   std::cout << "ExtendWheels Subsystem" << std::endl;
   std::cout.flush();
   if(Robot::frontClimberMotor != nullptr && Robot::rearClimberMotor != nullptr){
    if(_side == 'F'){
      Robot::frontClimberMotor->Set(-_speed);
      Robot::rearClimberMotor->Set(0);
    }else if(_side == 'R'){
     Robot::rearClimberMotor->Set(_speed);
     Robot::frontClimberMotor->Set(0); 
    }else{
      Robot::frontClimberMotor->Set(-_speed);
      Robot::rearClimberMotor->Set(_speed);
    }
   }
 }

 void Climber::HoldWheels(){
   std::cout << "Hold Wheels" << std::endl;
   std::cout.flush();
   if(Robot::frontClimberMotor != nullptr && Robot::rearClimberMotor != nullptr){
     Robot::frontClimberMotor->Set(0);
     Robot::frontServo->Set(SERVOLOCK);
     Robot::rearClimberMotor->Set(0);
     Robot::rearServo->Set(SERVOLOCK);   
   }
 }


void Climber::Default(){
  if(Robot::oi->GetButtonY()){
    Robot::frontClimberMotor->Set(-0.25);
  }else if(Robot::oi->GetButtonX()){
    Robot::frontClimberMotor->Set(0.25);
  }else{
    Robot::frontClimberMotor->Set(0);
  }
  
  if(Robot::oi->GetButtonB()){
    Robot::rearClimberMotor->Set(0.25);
  }else if(Robot::oi->GetButtonA()){
    Robot::rearClimberMotor->Set(-0.25);
  }else{
    Robot::rearClimberMotor->Set(0);
  }
}