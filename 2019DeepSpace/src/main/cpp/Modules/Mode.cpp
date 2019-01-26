// ==========================================================================
// Constants class
//
// FRC 4143 "MARS WARS"
// ==========================================================================
// 2015-02-01 JKSalmon - Initial development
// ==========================================================================
#include "Modules/Mode.h"

// ==========================================================================

Mode::GameMode Mode::gameMode = Mode::GameMode::HATCHMODE;

bool Mode::IsHatchMode()
{
    return(gameMode == GameMode::HATCHMODE);
}
bool Mode::IsCargoMode()
{
     return(gameMode == GameMode::CARGOMODE);
}
bool Mode::IsEndGame()
{
     return(gameMode == GameMode::ENDGAME);
}

void Mode::SetEndgame()
{
    gameMode = GameMode::ENDGAME;
}

void Mode::ToggleInGameMode()
{
    if(gameMode == GameMode::HATCHMODE)
    {
        gameMode = GameMode::CARGOMODE;
    }
    else
    {
        gameMode = GameMode::HATCHMODE;
    }
}

// ==========================================================================
