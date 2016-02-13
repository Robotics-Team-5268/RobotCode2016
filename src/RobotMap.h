
#ifndef ROBOTMAP_H
#define ROBOTMAP_H
#include "WPILib.h"

/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */

#define DRIVE_SPEED_CONTROLLER_1_CHANNEL 0
#define DRIVE_SPEED_CONTROLLER_2_CHANNEL 1
#define DRIVE_SPEED_CONTROLLER_3_CHANNEL 2
#define DRIVE_SPEED_CONTROLLER_4_CHANNEL 3
#define SHOOTER_SPEED_CONTROLLER_CHANNEL 6
#define FETCHER_WHEEL_SPEED_CONTROLLER_CHANNEL 7
#define FETCHER_SPEED_CONTROLLER_CHANNEL 9

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
	static void init();
};
#endif // ROBOTMAP_H
