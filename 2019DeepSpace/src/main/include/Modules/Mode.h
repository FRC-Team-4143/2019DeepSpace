#pragma once
// ==========================================================================

class Mode {
public:
	enum GameMode {HATCHMODE,CARGOMODE,ENDGAME};

	static bool IsHatchMode();
	static bool IsCargoMode();
	static bool IsEndGame();
	static GameMode GetMode();

	static void SetLED();
	static void SetEndgame();
	static void ToggleInGameMode();
private:
	Mode() = delete;
	static GameMode gameMode;
};

// ==========================================================================
