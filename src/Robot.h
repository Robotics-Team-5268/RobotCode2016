
#ifndef _ROBOT_H
#define _ROBOT_H

#include "WPILib.h"
#include "Commands/Command.h"
#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"
#include "SmartDashboard/SmartDashboard.h"
#include "Commands/Rotate.h"
#include "Subsystems/Drive.h"
#include "Subsystems/Shooter.h"
#include "Subsystems/Fetcher.h"

#include "OI.h"
#include "Commands/Autonomous.h"

class Robot : public IterativeRobot {
public:
	static std::unique_ptr<Command> autonomousCommand;
	//Autonomous autonomousCommand;
	static std::unique_ptr<OI> oi;
	LiveWindow *lw = LiveWindow::GetInstance();
    static std::shared_ptr<Drive> drive;
    static std::shared_ptr<Shooter> shooter;
    static std::shared_ptr<Fetcher> fetcher;

	virtual void RobotInit();
	virtual void DisabledInit();
	virtual void DisabledPeriodic();
	virtual void AutonomousInit();
	virtual void AutonomousPeriodic();
	virtual void TeleopInit();
	virtual void TeleopPeriodic();
	virtual void TestPeriodic();
	virtual void TestInit();
};
#endif
