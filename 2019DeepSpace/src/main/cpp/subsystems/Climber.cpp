#include "subsystems/Climber.h"
#include "Robot.h"

#define SERVOPASS 45
#define SERVOLOCK 0

Climber::Climber() : frc::Subsystem("Climber") {
}

void Climber::InitDefaultCommand() {
  //SetDefaultCommand(new Command());
}

 void Climber::RetractWheels(char _side, float _speed){
   if(Robot::frontClimberMotor != nullptr && Robot::rearClimberMotor != nullptr){
     if(_side == 'F'){
       Robot::frontServo->Set(SERVOPASS);
       if(Robot::frontServo->GetAngle() == SERVOPASS){
         Robot::frontClimberMotor->Set(-_speed);
       }
     }else if(_side == 'R'){
       Robot::rearServo->Set(SERVOPASS);
       if(Robot::rearServo->GetAngle() == SERVOPASS){
         Robot::rearClimberMotor->Set(-_speed);
       }
     }else{
       Robot::frontServo->Set(SERVOPASS);
       Robot::rearServo->Set(SERVOPASS);
       if(Robot::frontServo->GetAngle() == SERVOPASS && Robot::rearServo->GetAngle() == SERVOPASS){
       Robot::frontClimberMotor->Set(-_speed);
       Robot::rearClimberMotor->Set(-_speed);
       }
     }
   }
 }

 void Climber::ExtendWheels(char _side, float _speed){
   if(Robot::frontClimberMotor != nullptr && Robot::rearClimberMotor != nullptr){
    if(_side == 'F'){
      Robot::frontClimberMotor->Set(_speed);
    }else if(_side == 'R'){
     Robot::rearClimberMotor->Set(_speed); 
    }else{
      Robot::frontClimberMotor->Set(_speed);
      Robot::rearClimberMotor->Set(_speed);
    }
   }
 }

 void Climber::HoldWheels(){
   if(Robot::frontClimberMotor != nullptr && Robot::rearClimberMotor != nullptr){
     Robot::frontClimberMotor->Set(0);
     Robot::frontServo->Set(SERVOLOCK);
     Robot::rearClimberMotor->Set(0);
     Robot::rearServo->Set(SERVOLOCK);   
   }
 }


