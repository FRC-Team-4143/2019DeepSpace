#include "commands/Turtle.h"
#include "Modules/Height.h"
#include "Robot.h"

Turtle::Turtle() {
  // Use Requires() here to declare subsystem dependencies
  Requires(Robot::arm);
  Requires(Robot::elevator);
}

void Turtle::Initialize() {

}

void Turtle::Execute() {
  Robot::arm->SetPosition(0);
  Robot::elevator->SetHeight(0);
}

bool Turtle::IsFinished() {
  return false;
}

void Turtle::End() {
}

void Turtle::Interrupted() {
  End();
}
