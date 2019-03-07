#pragma once
#include <frc/commands/Command.h>

class ArmHoldCommand : public frc::Command {
public:
	ArmHoldCommand();
	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;
};
