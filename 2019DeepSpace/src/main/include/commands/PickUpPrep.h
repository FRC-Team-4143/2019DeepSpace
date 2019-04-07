#pragma once
#include <frc/commands/Command.h>

class PickUpPrep : public frc::Command {
public:
	PickUpPrep();
	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;
};
