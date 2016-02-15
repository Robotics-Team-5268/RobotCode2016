#ifndef LED_H
#define LED_H

#include "../CommandBase.h"
#include "WPILib.h"
#include "Robot.h"

class LED: public CommandBase
{
public:
	LED();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
