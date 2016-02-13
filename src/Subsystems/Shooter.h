
#ifndef SHOOTER_H
#define SHOOTER_H
#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "RobotMap.h"

class Shooter: public Subsystem {
private:
	// It's desirable that everything possible is private except
	// for methods that implement subsystem capabilities
	std::shared_ptr<CANTalon> shooterCANTalon;
public:
	Shooter();
	void InitDefaultCommand();
	void AddSmartDashboardItems();
	void setSpeed(double sp);
	void takeInput();
	bool getLimitSwitch();
	void resetPosition();
	double getTalonPosition();
};

#endif // SHOOTER_H
