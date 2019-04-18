#include "commands/Turtle.h"
#include "Modules/Height.h"
#include "Robot.h"

Turtle::Turtle() {
  // Use Requires() here to declare subsystem dependencies
  Requires(Robot::arm);
  Requires(Robot::elevator);
}

void Turtle::Initialize() {
  //currentheading = Robot::driveTrain->GetNearestHeading();
}

void Turtle::Execute() {
  
  Robot::arm->SetPosition(0);
  Robot::elevator->SetHeight(0);
  //Robot::driveTrain->RotateAboutPoint(currentheading);

}

bool Turtle::IsFinished() {
  return false;
}

void Turtle::End() {
  Robot::driveTrain->SetWheelbase(0, 0, 0, 0);
}

void Turtle::Interrupted() {
  End();
}
