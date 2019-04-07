#include "Modules/Height.h"
#include <frc/smartdashboard/SmartDashboard.h>

Height* Height::_instance = nullptr;

Height* Height::GetInstance() {
    if(nullptr ==_instance){
        _instance = new Height();
    }
    return _instance;
}

Height::Height(){
    _index = 0;
    _lastGameMode = Mode::GetMode();
}

void Height::AddCargoTarget(double elevatorPos, double armPos){
    _cargoElevatorTargets.push_back(elevatorPos);
    _cargoArmTargets.push_back(armPos);
}

void Height::AddHatchTarget(double elevatorPos, double armPos){
    _hatchElevatorTargets.push_back(elevatorPos);
    _hatchArmTargets.push_back(armPos);
}

void Height::AddClimbingTarget(double elevatorPos, double armPos) {
    _climbingElevatorTargets.push_back(elevatorPos);
    _climbingArmTargets.push_back(armPos);
}

double Height::GetElevatorTarget() {
    auto mode = Mode::GetMode();
    if(mode != _lastGameMode){
        _index = 0;
    }
    _lastGameMode = mode;

    if (_lastGameMode == Mode::GameMode::CARGOMODE) {
        return _cargoElevatorTargets[_index];
    }
    else if (_lastGameMode == Mode::GameMode::HATCHMODE) {
        return _hatchElevatorTargets[_index];
    }
    else {
        return _climbingElevatorTargets[_index];
    }
}

double Height::GetArmTarget(){ 
    auto mode = Mode::GetMode();
    if(mode != _lastGameMode){
        _index = 0;
    }
    _lastGameMode = mode;

    if (_lastGameMode == Mode::GameMode::CARGOMODE) {
        return _cargoArmTargets[_index];
    }
    else if (_lastGameMode == Mode::GameMode::HATCHMODE) {
        return _hatchArmTargets[_index];
    }
    else {
        return _climbingArmTargets[_index];
    }
}

void Height::NextPosition() {
    int max = _hatchArmTargets.size() - 1;
    if(_lastGameMode == Mode::GameMode::CARGOMODE){
        max = _cargoArmTargets.size() - 1;
    }
    else if(_lastGameMode == Mode::GameMode::ENDGAME){
        max = _climbingArmTargets.size() - 1;
    }

    _index++;
    if(_index > max){ 
        _index = 0;
    }
}

void Height::PreviousPosition(){ 
    int max = _hatchArmTargets.size() - 1;
    if(_lastGameMode == Mode::GameMode::CARGOMODE){
        max = _cargoArmTargets.size() - 1;
    }
    else if(_lastGameMode == Mode::GameMode::ENDGAME){
        max = _climbingArmTargets.size() - 1;
    }

    _index--;
    if(_index < 0){
        _index = max;
    }
}

void Height::PickUpPiece(){
     if(_lastGameMode == Mode::GameMode::CARGOMODE){
        _index = 1;
    }
    else {
        _index = 0;
    }
}

void Height::UpdateSmartDashboard(){
    char sz[20];
    int count = _hatchArmTargets.size();

    for(int i = 0; i < count; i++){
        sprintf(sz, "Hatch Index %d", i);
        frc::SmartDashboard::PutBoolean(sz, Mode::IsHatchMode() ? (i == _index) : false);
    }
    count = _cargoArmTargets.size();
    for(int i = 0; i < count; i++){
        sprintf(sz, "Cargo Index %d", i);
        frc::SmartDashboard::PutBoolean(sz, Mode::IsCargoMode() ? (i == _index) : false);
    }
    count = _climbingArmTargets.size();
    for(int i = 0; i < count; i++){
        sprintf(sz, "Climbing Index %d", i);
        frc::SmartDashboard::PutBoolean(sz, Mode::IsEndGame() ? (i == _index) : false);
    }
}