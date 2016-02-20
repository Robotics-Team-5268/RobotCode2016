
#include "Commands/MoveFetcher.h"

MoveFetcher::MoveFetcher(): CommandBase(), isOut(true) {
        // Use requires() here to declare subsystem dependencies
    // eg. requires(chassis);
	Requires(fetcher.get());
	// Makes sure that the shooter is not doing anything while the fetcher is moving
	Requires(shooter.get());
	SetTimeout(6);
	runWheel = true;
	seconds = 0;
}

MoveFetcher::MoveFetcher(bool oOrI, double tm, bool runW): CommandBase() {
	Requires(fetcher.get());
	// Makes sure that the shooter is not doing anything while the fetcher is moving
	Requires(shooter.get());
	isOut = oOrI;
	runWheel = runW;
	timer.reset(new Timer());
	seconds = tm;
}

MoveFetcher::MoveFetcher(bool oOrI, bool runW): CommandBase() {
        // Use requires() here to declare subsystem dependencies
    // eg. requires(chassis);
	Requires(fetcher.get());
	// Makes sure that the shooter is not doing anything while the fetcher is moving
	Requires(shooter.get());
	isOut = oOrI;
	runWheel = runW;
	seconds = 0;
}

// Called just before this Command runs the first time
void MoveFetcher::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void MoveFetcher::Execute() {
	if(!fetcher->checkIfFinished(isOut)){
		fetcher->setCANTalonSpeed(isOut ? .65 : -.65);
	}
	if(timer){
		if(timer->Get() == 0){
			timer->Start();
		}
	}
}

// Make this return true when this Command no longer needs to run execute()
bool MoveFetcher::IsFinished() {
	if(seconds != 0){
		if(timer){
			if(timer->HasPeriodPassed(seconds)){
				return true;
			}
		}
	}
	if(fetcher->checkIfFinished(isOut)){
		fetcher->setCANTalonSpeed(0);
	}
	if(runWheel){
		if(isOut == false && !oi->getShooterButtonPressed(2)){
			return true;
		}
		else if(isOut && !oi->getShooterButtonPressed(1)){
			return true;
		}
	}else{
		return fetcher->checkIfFinished(isOut);
	}
	return false;//fetcher->checkIfFinished(isOut);
}

// Called once after isFinished returns true
void MoveFetcher::End() {
	fetcher->setCANTalonSpeed(0);
	if(runWheel){
		fetcher->setTalonSpeed(isOut ? -1 : 0);
	}
	if(timer){
		timer->Stop();
		timer->Reset();
	}
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void MoveFetcher::Interrupted() {
	End();
}
