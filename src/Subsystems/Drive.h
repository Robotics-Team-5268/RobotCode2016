
#ifndef DRIVE_H
#define DRIVE_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

class Drive: public Subsystem {
private:
	// It's desirable that everything possible is private except
	// for methods that implement subsystem capabilities
	std::shared_ptr<SpeedController> speedControllerFL;
	std::shared_ptr<SpeedController> speedControllerFR;
	std::shared_ptr<SpeedController> speedControllerBL;
	std::shared_ptr<SpeedController> speedControllerBR;
	std::shared_ptr<RobotDrive> robotDrive4;

	std::shared_ptr<AnalogGyro> gyro;
public:
	Drive();
	void safetyOff(){robotDrive4->SetSafetyEnabled(false);}
	void InitDefaultCommand();
	void AddSmartDashboardItems();
	AnalogGyro* getGyro();
	void setMotors(float leftSpeed, float rightSpeed);
	float returnAngle();
	void takeInput();
	float oldX, oldY;
	const float MAX_CHANGE = 0.05;
};

#endif
