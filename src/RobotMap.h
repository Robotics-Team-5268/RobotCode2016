
#ifndef ROBOTMAP_H
#define ROBOTMAP_H
#include "WPILib.h"
#include "Relay.h"

#define DRIVE_SPEED_CONTROLLER_1_CHANNEL 		0   //front left
#define DRIVE_SPEED_CONTROLLER_2_CHANNEL 		1   //front right
#define DRIVE_SPEED_CONTROLLER_3_CHANNEL 		2   //back left
#define DRIVE_SPEED_CONTROLLER_4_CHANNEL 		3	//back right
#define SHOOTER_SPEED_CONTROLLER_CHANNEL 		9
#define FETCHER_WHEEL_SPEED_CONTROLLER_CHANNEL 	4   //
#define FETCHER_SPEED_CONTROLLER_CHANNEL 		6   //
#define GYRO_SPI_PORT 							SPI::kOnboardCS0
#define SHOOTER_LIMIT_SWITCH					9

class RobotMap {
public:
	static std::shared_ptr<SpeedController> speedControllerFL;
	static std::shared_ptr<SpeedController> speedControllerFR;
	static std::shared_ptr<SpeedController> speedControllerBL;
	static std::shared_ptr<SpeedController> speedControllerBR;
	static std::shared_ptr<RobotDrive> driveRobotDrive4;
	static std::shared_ptr<AnalogGyro> driveGyro;

	static std::shared_ptr<Relay> ledRelay1;
	static std::shared_ptr<Relay> ledRelay2;
	static std::shared_ptr<Relay> ledRelay3;
	static std::shared_ptr<Relay> ledRelay4;

	static void init();
};
#endif // ROBOTMAP_H
