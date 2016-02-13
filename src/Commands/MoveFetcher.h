
#ifndef MOVEFETCHER_H
#define MOVEFETCHER_H


#include "Commands/Subsystem.h"
#include "../Robot.h"

class MoveFetcher: public Command {
public:

	MoveFetcher(bool oOrI); // 0 = in, 1 = out
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
private:
	MoveFetcher();
	bool isOut;
};

#endif
