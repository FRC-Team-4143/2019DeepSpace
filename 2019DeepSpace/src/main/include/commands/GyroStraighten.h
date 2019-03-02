#pragma once

#include <frc/Commands/Command.h>

class GyroStraighten : public frc::Command {
public:
	GyroStraighten();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};
