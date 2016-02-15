
#ifndef SHOOT_H
#define SHOOT_H


#include "Commands/Subsystem.h"
#include "../Robot.h"

class Shoot: public CommandBase {
public:
	Shoot();

	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
private:
	enum
	{
		SwitchClosed,
		SwitchOpen,
		armed
	}state;
};

#endif
