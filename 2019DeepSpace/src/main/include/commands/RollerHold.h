#pragma once
#include <frc/commands/Command.h>

class RollerHold : public frc::Command {
public:
	RollerHold();
	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;
};
