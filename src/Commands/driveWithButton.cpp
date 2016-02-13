
#include <Commands/driveWithButton.h>
#include <Subsystems/Drive.h>
#include <oi.h>


driveWithButton::driveWithButton(): Command() {
        // Use requires() here to declare subsystem dependencies
    // eg. requires(chassis);
	Requires(Robot::drive.get());
}

// Called just before this Command runs the first time
void driveWithButton::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void driveWithButton::Execute() {
Robot::drive->setMotors(1, 1);
}

// Make this return true when this Command no longer needs to run execute()
bool driveWithButton::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void driveWithButton::End() {
Robot::drive->setMotors(0, 0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void driveWithButton::Interrupted() {

}
