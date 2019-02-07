#include "commands/ClimberTest.h"
#include "subsystems/Climber.h"
#include "Robot.h"

ClimberTest::ClimberTest() {
  // Use Requires() here to declare subsystem dependencies
  Requires(Robot::climber);
}


void ClimberTest::Initialize() {
}

void ClimberTest::Execute() {
  Robot::climber->Default();
}

bool ClimberTest::IsFinished() { return false; }

void ClimberTest::End() {

}

void ClimberTest::Interrupted() {
  End();
}