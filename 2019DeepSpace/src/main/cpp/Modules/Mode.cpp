// ==========================================================================
// Constants class
//
// FRC 4143 "MARS WARS"
// ==========================================================================
// 2015-02-01 JKSalmon - Initial development
// ==========================================================================
#include "Modules/Mode.h"
#include "Modules/Lights.h"

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
    SetLED();
}

void Mode::ToggleInGameMode()
{
    if(gameMode == GameMode::HATCHMODE)
    {
        gameMode = GameMode::CARGOMODE;
        SetLED();
    }
    else
    {
        gameMode = GameMode::HATCHMODE;
        SetLED();
    }
}

void Mode::SetLED()
{
    if(gameMode = GameMode::HATCHMODE){
        Lights::SetHatchLights();
    }
    else if(gameMode = GameMode::CARGOMODE){
        Lights::SetCargoLights();
    }
    else if(gameMode = GameMode::ENDGAME){
        Lights::SetEndGameLights();
    }

}

// ==========================================================================
