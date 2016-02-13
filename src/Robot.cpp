
#include "Robot.h"

std::shared_ptr<Drive> Robot::drive;
std::unique_ptr<OI> Robot::oi;
std::shared_ptr<Shooter> Robot::shooter;
std::shared_ptr<Fetcher> Robot::fetcher;
std::unique_ptr<Command> Robot::autonomousCommand;
void Robot::RobotInit() {
	RobotMap::init();
    drive.reset(new Drive());
	oi.reset(new OI());
	shooter.reset(new Shooter());
	fetcher.reset(new Fetcher());
	// This MUST be here. If the OI creates Commands (which it very likely
	// will), constructing it during the construction of CommandBase (from
	// which commands extend), subsystems are not guaranteed to be
	// yet. Thus, their requires() statements may grab null pointers. Bad
	// news. Don't move it.

	lw->AddActuator("Drive", "Drive Gyro", drive->getGyro());
	drive->safetyOff();

	//instantiate the command used for the autonomous period
	autonomousCommand.reset(new Autonomous());
  }

/**
 * This function is called when the disabled button is hit.
 * You can use it to reset subsystems before shutting down.
 */
void Robot::DisabledInit(){

}

void Robot::DisabledPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::AutonomousInit() {
	//autonomousCommand.Start();
	RobotMap::driveGyro->Reset();
	if(autonomousCommand.get() != nullptr)
	{
		autonomousCommand->Start();
	}
}

void Robot::AutonomousPeriodic() {
	Scheduler::GetInstance()->Run();
	drive->AddSmartDashboardItems();
}

void Robot::TeleopInit() {
	// This makes sure that the autonomous stops running when
	// teleop starts running. If you want the autonomous to
	// continue until interrupted by another command, remove
	// these lines or comment it out.
	if(autonomousCommand.get() != nullptr)
	{
		autonomousCommand->Cancel();
	}
	drive->getGyro()->Reset();
}

void Robot::TeleopPeriodic() {
	Scheduler::GetInstance()->Run();
	drive->AddSmartDashboardItems();
}

void Robot::TestPeriodic() {
	lw->Run();
}
void Robot::TestInit(){

}


START_ROBOT_CLASS(Robot);

