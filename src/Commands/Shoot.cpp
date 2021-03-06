
#include "Commands/Shoot.h"

Shoot::Shoot(): CommandBase(), state(SwitchClosed){
	// Use requires() here to declare subsystem dependencies
    // eg. requires(chassis);
	Requires(shooter.get());
	Requires(fetcher.get());
}

// Called just before this Command runs the first time
void Shoot::Initialize() {
}

// Called repeatedly when this Command is scheduled to run
void Shoot::Execute() {
	SmartDashboard::PutBoolean("Shooter limit", shooter->getLimitSwitch());
	// In case the drawer is in while the shoot command is running.
	// Only the first time check
	if(shooter->getSpeed() == 0 && !fetcher->isDrawerOut())
	{
			//End();
			return;
	}
	shooter->setSpeed(1);
	if(!shooter->getLimitSwitch() && state == SwitchClosed){
		state = SwitchOpen;
	}else if(shooter->getLimitSwitch() && state == SwitchOpen){
		state = armed;
	}
}

// Make this return true when this Command no longer needs to run execute()
bool Shoot::IsFinished() {
	if(state == armed)
	{
		leds->TurnOn(3);
		return true;
	}
	else
	{
		leds->TurnOff(3);
		return false;
	}
}

// Called once after isFinished returns true
void Shoot::End() {
	shooter->setSpeed(0);
	state = SwitchClosed;
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Shoot::Interrupted() {
	Shoot::End();
}
