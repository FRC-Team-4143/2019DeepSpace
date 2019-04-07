#pragma once
#include <vector>
#include "Modules/Mode.h"

class Height {
public:
    static Height* GetInstance();

    void AddCargoTarget(double elevatorPos, double armPos);
    void AddHatchTarget(double elevatorPos, double armPos);
    void AddClimbingTarget(double elevatorPos, double armPos);
    double GetElevatorTarget();
    double GetArmTarget();
    void NextPosition();
    void PreviousPosition();
    void PickUpPiece();
    void UpdateSmartDashboard();

private:
    Height();
    Height(const Height&) = delete;

    std::vector<double> _cargoElevatorTargets;
    std::vector<double> _cargoArmTargets;
    std::vector<double> _hatchElevatorTargets;
    std::vector<double> _hatchArmTargets;
    std::vector<double> _climbingElevatorTargets;
    std::vector<double> _climbingArmTargets;

    int _index;
    Mode::GameMode _lastGameMode;

    static Height* _instance;
};