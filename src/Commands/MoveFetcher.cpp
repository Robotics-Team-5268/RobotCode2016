
#include "Commands/MoveFetcher.h"
#include "Subsystems/Fetcher.h"

MoveFetcher::MoveFetcher(): Command(), isOut(true) {
        // Use requires() here to declare subsystem dependencies
    // eg. requires(chassis);
	Requires(Robot::fetcher.get());
}

MoveFetcher::MoveFetcher(bool oOrI): Command(), isOut(true) {
        // Use requires() here to declare subsystem dependencies
    // eg. requires(chassis);
	Requires(Robot::fetcher.get());
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
return Robot::fetcher->checkIfFinished(isOut);
}

// Called once after isFinished returns true
void MoveFetcher::End() {
Robot::fetcher->setCANTalonSpeed(0);
if(isOut)
	Robot::fetcher->setTalonSpeed(1);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void MoveFetcher::Interrupted() {
End();
}
