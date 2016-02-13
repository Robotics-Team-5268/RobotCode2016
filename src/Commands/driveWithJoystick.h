
#ifndef DRIVEWITHJOYSTICK_H
#define DRIVEWITHJOYSTICK_H


#include "Commands/Subsystem.h"
#include "../Robot.h"

class driveWithJoystick: public Command {
public:
	driveWithJoystick();

	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();

private:

};

#endif
