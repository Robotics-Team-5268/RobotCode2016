
#include "Commands/Shoot.h"
#include "Subsystems/Shooter.h"

Shoot::Shoot(): Command() {
	// Use requires() here to declare subsystem dependencies
    // eg. requires(chassis);
	Requires(Robot::shooter.get());
}

// Called just before this Command runs the first time
void Shoot::Initialize() {
}

// Called repeatedly when this Command is scheduled to run
void Shoot::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool Shoot::IsFinished() {

}

// Called once after isFinished returns true
void Shoot::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Shoot::Interrupted() {

}
