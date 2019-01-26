#include "commands/SetEndGame.h"
#include "Modules/Mode.h"
#include "Robot.h"

SetEndGame::SetEndGame() {
  // Use Requires() here to declare subsystem dependencies
  Requires(Robot::elevator);
}


void SetEndGame::Initialize() {
  Mode::SetEndgame();
}

void SetEndGame::Execute() {
  
}

bool SetEndGame::IsFinished() { return true; }

void SetEndGame::End() {

}

void SetEndGame::Interrupted() {
  End();
}