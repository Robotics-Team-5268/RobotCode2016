#include "LED.h"

LED::LED()
{
	Requires(leds.get());
}

// Called just before this Command runs the first time
void LED::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void LED::Execute()
{
	leds->TurnOn();
}

// Make this return true when this Command no longer needs to run execute()
bool LED::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void LED::End()
{
	leds->TurnOff();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LED::Interrupted()
{

}