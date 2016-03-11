
#ifndef ROBOTMAP_H
#define ROBOTMAP_H
#include "WPILib.h"

#define DRIVE_SPEED_CONTROLLER_1_CHANNEL 		0   //right
#define DRIVE_SPEED_CONTROLLER_2_CHANNEL 		1   //right
#define DRIVE_SPEED_CONTROLLER_3_CHANNEL 		2   //left
#define DRIVE_SPEED_CONTROLLER_4_CHANNEL 		3	//left
#define SHOOTER_SPEED_CONTROLLER_CHANNEL 		9
#define FETCHER_WHEEL_SPEED_CONTROLLER_CHANNEL 	4   //
#define FETCHER_SPEED_CONTROLLER_CHANNEL 		6   //
#define GYRO_SPI_PORT 							SPI::kOnboardCS0
#define SHOOTER_LIMIT_SWITCH					9

class RobotMap {
public:
	static std::shared_ptr<SpeedController> driveSpeedController1;
	static std::shared_ptr<SpeedController> driveSpeedController2;
	static std::shared_ptr<SpeedController> driveSpeedController3;
	static std::shared_ptr<SpeedController> driveSpeedController4;
	static std::shared_ptr<RobotDrive> driveRobotDrive4;
	static std::shared_ptr<ADXRS450_Gyro>driveGyro;
	static std::shared_ptr<CANTalon> shooterSpeedController;
	static std::shared_ptr<CANTalon> fetcherSpeedController;
	static std::shared_ptr<Talon> fetcherWheelSpeedController;
	static std::shared_ptr<DigitalInput> shooterDigitalInput;

	static std::shared_ptr<Relay> ledRelay1;
	static std::shared_ptr<Relay> ledRelay2;
	static std::shared_ptr<Relay> ledRelay3;
	static std::shared_ptr<Relay> ledRelay4;

	static std::shared_ptr<DigitalInput> shooterLimit;

	static void init();
};
#endif // ROBOTMAP_H
