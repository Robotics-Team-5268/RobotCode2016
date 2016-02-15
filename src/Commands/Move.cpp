
#include "Commands/Move.h"

Move::Move(): CommandBase(), seconds(), speed() {

}
Move::Move(float tm, float spd): CommandBase() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	Requires(CommandBase::drive.get());
	seconds = tm;
	speed = spd;
}

// Called just before this Command runs the first time
void Move::Initialize() {
}

// Called repeatedly when this Command is scheduled to run
void Move::Execute() {
	drive->setMotors(speed, speed); //Left speed is first, right speed second
}

// Make this return true when this Command no longer needs to run execute()
bool Move::IsFinished() {
	if(seconds -TimeSinceInitialized() <= 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// Called once after isFinished returns true
void Move::End() {
	drive->setMotors(0, 0); //Left speed is first, right speed second
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Move::Interrupted() {
	End();
}
