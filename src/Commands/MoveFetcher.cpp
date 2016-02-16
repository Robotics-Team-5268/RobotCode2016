
#include "Commands/MoveFetcher.h"

MoveFetcher::MoveFetcher(): CommandBase(), isOut(true) {
        // Use requires() here to declare subsystem dependencies
    // eg. requires(chassis);
	Requires(fetcher.get());
	// Makes sure that the shooter is not doing anything while the fetcher is moving
	Requires(shooter.get());
}

MoveFetcher::MoveFetcher(bool oOrI): CommandBase() {
        // Use requires() here to declare subsystem dependencies
    // eg. requires(chassis);
	Requires(fetcher.get());
	// Makes sure that the shooter is not doing anything while the fetcher is moving
	Requires(shooter.get());
	isOut = oOrI;
}

// Called just before this Command runs the first time
void MoveFetcher::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void MoveFetcher::Execute() {
	if(!fetcher->checkIfFinished(isOut)){
		fetcher->setCANTalonSpeed(isOut ? .5 : -.5);
	}
}

// Make this return true when this Command no longer needs to run execute()
bool MoveFetcher::IsFinished() {
	return true;//fetcher->checkIfFinished(isOut);
}

// Called once after isFinished returns true
void MoveFetcher::End() {
	if(Command::IsCanceled()){
		fetcher->setCANTalonSpeed(0);
	}
	fetcher->setTalonSpeed(isOut ? 1 : 0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void MoveFetcher::Interrupted() {
	End();
}
