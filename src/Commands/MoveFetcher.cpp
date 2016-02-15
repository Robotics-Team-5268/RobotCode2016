
#include "Commands/MoveFetcher.h"

MoveFetcher::MoveFetcher(): CommandBase(), isOut(true) {
        // Use requires() here to declare subsystem dependencies
    // eg. requires(chassis);
	Requires(fetcher.get());
}

MoveFetcher::MoveFetcher(bool oOrI): CommandBase(), isOut(true) {
        // Use requires() here to declare subsystem dependencies
    // eg. requires(chassis);
	Requires(fetcher.get());
	isOut = oOrI;
}

// Called just before this Command runs the first time
void MoveFetcher::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void MoveFetcher::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool MoveFetcher::IsFinished() {
	return fetcher->checkIfFinished(isOut);
}

// Called once after isFinished returns true
void MoveFetcher::End() {
	fetcher->setCANTalonSpeed(0);
	if(isOut){
		fetcher->setTalonSpeed(1);
	}
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void MoveFetcher::Interrupted() {
End();
}
