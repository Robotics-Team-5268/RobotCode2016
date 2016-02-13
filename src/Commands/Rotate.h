
#ifndef ROTATE_H
#define ROTATE_H


#include "Commands/Subsystem.h"
#include "../Robot.h"

class Rotate: public Command {
private:
	Rotate();
public:
	Rotate( float amount );

	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
	float degrees;
	float gyroAngle;

	PIDController* pid;
private:

};
class RotatePIDOutput: public PIDOutput
	{
		virtual ~RotatePIDOutput();
		void PIDWrite(float a);
	};
#endif
