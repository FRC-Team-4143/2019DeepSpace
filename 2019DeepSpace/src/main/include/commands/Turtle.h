#pragma once
#include <frc/commands/Command.h>

class Turtle : public frc::Command {
public:
	Turtle();
	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;

	float currentheading;
};
