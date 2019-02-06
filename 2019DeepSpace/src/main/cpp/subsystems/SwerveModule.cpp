#include "subsystems/SwerveModule.h"
#include "subsystems/EncoderConstants.h"
#include  <frc/Preferences.h>

#define USINGTALON 0

SwerveModule::SwerveModule(rev::CANSparkMax* drive, WPI_TalonSRX* steer, std::string configName) { //CHANGE drive BACK TO WPI_TalonSRX
  _drive = drive;
  _steer = steer;
  _configName = configName;
}

void SwerveModule::SetGeometry(double x, double y){
  _x = x;
  _y = y;
}
#if USINGTALON
double SwerveModule::GetSteerPosition(){
  float currentPosition = _steer->GetSelectedSensorPosition(0) / EncoderConstants::COUNTS_PER_TURN;
  int turns = trunc(currentPosition);
  float currentAngle = currentPosition - turns;
  return currentAngle *EncoderConstants::FULL_TURN;

}

void SwerveModule::SetWheelOffset(){
  _steerPosition = GetSteerPosition();
  auto prefs = frc::Preferences::GetInstance();
  prefs->PutDouble(_configName, _steerPosition);
}

void SwerveModule::LoadWheelOffset(){

}
#endif
void SwerveModule::TESTSetDriveSpeed(float _speed){
  _drive->Set(_speed);
}
