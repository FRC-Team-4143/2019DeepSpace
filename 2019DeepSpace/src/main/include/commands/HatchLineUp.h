#pragma once

#include <frc/commands/Command.h>

class HatchLineUp : public frc::Command {
 public:

  HatchLineUp();
  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End() override;
  void Interrupted() override;

  private:

   double _timeoutSeconds;
   int _counter;
   int _waiting;
   int _waitingCounter;
   double _angle;
   double _tol;
   double _center;
   double _yaw;
};

