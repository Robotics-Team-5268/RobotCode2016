
#include "Commands/Shoot.h"

Shoot::Shoot(): CommandBase(), state(SwitchClosed){
	// Use requires() here to declare subsystem dependencies
    // eg. requires(chassis);
	Requires(shooter.get());
}

// Called just before this Command runs the first time
void Shoot::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void Shoot::Execute() {
	if(fetcher->getLimitSwitch()) // In case the drawer is in while the shoot command is running.
	{
			End();
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
	return (state == armed);
}

// Called once after isFinished returns true
void Shoot::End() {
	shooter->setSpeed(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Shoot::Interrupted() {
	Shoot::End();
}
