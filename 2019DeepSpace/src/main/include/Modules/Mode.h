// ==========================================================================
// Constants class
//
// FRC 4143 "MARS WARS"
// ==========================================================================
// 2015-02-01 JKSalmon - Initial development
// ==========================================================================
#pragma once
// ==========================================================================

class Mode {
public:
	enum GameMode {HATCHMODE,CARGOMODE,ENDGAME};

	static bool IsHatchMode();
	static bool IsCargoMode();
	static bool IsEndGame();

	static void SetEndgame();
	static void ToggleInGameMode();
private:
	Mode() = delete;
	static GameMode gameMode;
};

// ==========================================================================
