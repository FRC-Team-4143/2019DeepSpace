#pragma once

#include <frc/commands/command.h>


// ==========================================================================

class HatchLineUp : public frc::Command {
public:
	HatchLineUp();

	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

private:
	double _timeoutSeconds;
	int _counter;
	int _waiting;
	int _waitingCounter;
	double _angle;
	double _tol;
	double _center;

	void _Cleanup();
};

// ==========================================================================
