
#include <Commands/DriveWithJoystick.h>
#include "Robot.h"
#include "Drive.h"
#include "../RobotMap.h"

Drive::Drive() : Subsystem("Drive"){
    speedController1 = RobotMap::driveSpeedController1;
    speedController2 = RobotMap::driveSpeedController2;
    speedController3 = RobotMap::driveSpeedController3;
    speedController4 = RobotMap::driveSpeedController4;
    robotDrive4 = RobotMap::driveRobotDrive4;
    speedController1->SetInverted(true);
    speedController2->SetInverted(true);
    gyro = RobotMap::driveGyro;
}
void Drive::AddSmartDashboardItems()
{
	SmartDashboard::PutNumber("Speed Controller 1", speedController1->Get());
	SmartDashboard::PutNumber("Speed Controller 2", speedController2->Get());
	SmartDashboard::PutNumber("Speed Controller 3", speedController3->Get());
	SmartDashboard::PutNumber("Speed Controller 4", speedController4->Get());
	SmartDashboard::PutNumber("Gyro Angle", gyro->GetAngle());
}
void Drive::InitDefaultCommand() {
    // Set the default command for a subsystem here.
	SetDefaultCommand(new DriveWithJoystick());
}
// Put methods for controlling this subsystem
// here. Call these from Commands.

void Drive::takeInput(){
	robotDrive4->ArcadeDrive((-CommandBase::oi->getDriverJoystick()->GetY()), -CommandBase::oi->getDriverJoystick()->GetX()/2);
}
void Drive::setMotors(float leftSpeed, float rightSpeed){
	speedController1->Set(leftSpeed);
	speedController2->Set(leftSpeed);
	speedController3->Set(-rightSpeed);
	speedController4->Set(-rightSpeed);
}
float Drive::returnAngle(){
	return gyro->GetAngle();
}
ADXRS450_Gyro* Drive::getGyro()
{
	return gyro.get();
}

