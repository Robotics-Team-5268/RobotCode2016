
#ifndef MOVEFETCHER_H
#define MOVEFETCHER_H

#include "../CommandBase.h"
#include "Commands/Subsystem.h"
#include "../Robot.h"

class MoveFetcher: public CommandBase {
public:
	MoveFetcher(bool oOrI, double tm, bool runW = true);
	MoveFetcher(bool oOrI, bool runW = true); // 0 = in, 1 = out
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
private:
	MoveFetcher();
	bool isOut;
	bool runWheel;
	std::shared_ptr<Timer> timer;
	double seconds;
};

#endif
