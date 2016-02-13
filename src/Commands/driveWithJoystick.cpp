
#include <Commands/driveWithJoystick.h>
#include <Subsystems/Drive.h>


driveWithJoystick::driveWithJoystick(): Command() {
        // Use requires() here to declare subsystem dependencies
    // eg. requires(chassis);
	Requires(Robot::drive.get());
}

// Called just before this Command runs the first time
void driveWithJoystick::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void driveWithJoystick::Execute() {
Robot::drive->takeInput();
}

// Make this return true when this Command no longer needs to run execute()
bool driveWithJoystick::IsFinished() {
return true;
}

// Called once after isFinished returns true
void driveWithJoystick::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void driveWithJoystick::Interrupted() {

}
