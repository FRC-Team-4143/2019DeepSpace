#include "Modules/Height.h"

Height& Height::GetInstance(){
    static Height* instance = nullptr;
    if(!instance){
        instance = new Height();
    }
    return *instance;
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

void Height::AddClimbingTarget(double elevatorPos, double armPos){
    _climbingElevatorTargets.push_back(elevatorPos);
    _climbingArmTargets.push_back(armPos);
}

double Height::GetElevatorTarget(){ 
    auto mode = Mode::GetMode();
    if(mode != _lastGameMode){
        _index = 0;
    }
    _lastGameMode = mode;

    if(_lastGameMode == Mode::GameMode::CARGOMODE){
        return _cargoElevatorTargets[_index];
    }else if(_lastGameMode == Mode::GameMode::HATCHMODE){
        return _hatchElevatorTargets[_index];
    }else{
        return _climbingElevatorTargets[_index];
    }
}
double Height::GetArmTarget(){ 
    auto mode = Mode::GetMode();
    if(mode != _lastGameMode){
        _index = 0;
    }

    _lastGameMode = mode;

    if(_lastGameMode == Mode::GameMode::CARGOMODE){
        return _cargoArmTargets[_index];
    }else if(_lastGameMode == Mode::GameMode::HATCHMODE){
        return _hatchArmTargets[_index];
    }else{
        return _climbingArmTargets[_index];
    }
}

void Height::NextPosition(){  
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