#include <iostream>
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
    if(GameMode::HATCHMODE == gameMode){
        Lights::SetHatchLights();
    }
    else if(GameMode::CARGOMODE == gameMode){
        Lights::SetCargoLights();
    }
    else if(GameMode::ENDGAME == gameMode){
        Lights::SetEndGameLights();
    }

}

// ==========================================================================
