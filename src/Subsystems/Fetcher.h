
#ifndef FETCHER_H
#define FETCHER_H
#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "RobotMap.h"

class Fetcher: public Subsystem {
private:
	// It's desirable that everything possible is private except
	// for methods that implement subsystem capabilities
	std::shared_ptr<CANTalon> fetcherCANTalon;
	std::shared_ptr<Talon> fetcherTalon;
public:
	Fetcher();
	void InitDefaultCommand();
	void AddSmartDashboardItems();
	void setCANTalonSpeed(double speed);
	void setTalonSpeed(double speed);
	void takeInput();
	bool checkIfFinished(bool a);
	bool getLimitSwitch();
};

#endif //No comment
