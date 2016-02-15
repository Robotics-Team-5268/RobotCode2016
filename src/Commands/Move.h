
#ifndef MOVE_H
#define MOVE_H

#include "../CommandBase.h"
#include "Commands/Subsystem.h"
#include "../Robot.h"

class Move: public CommandBase {
private:
	Move();
public:
	Move( float tm, float spd );

	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
	float seconds;
	float speed;
private:

};

#endif
