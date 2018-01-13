
#include <Commands/DriveWithJoystick.h>
#include "Robot.h"
#include "Drive.h"
#include "../RobotMap.h"

Drive::Drive() : Subsystem("Drive"){
    speedControllerFL = RobotMap::speedControllerFL;
    speedControllerFR = RobotMap::speedControllerFR;
    speedControllerBL = RobotMap::speedControllerBL;
    speedControllerBR = RobotMap::speedControllerBR;
    robotDrive4 = RobotMap::driveRobotDrive4;
    speedControllerFL->SetInverted(true);
    speedControllerFR->SetInverted(false);
    speedControllerBL->SetInverted(true);
    speedControllerBR->SetInverted(false);
    gyro = RobotMap::driveGyro;
    oldY = 0.0;
    oldX = 0.0;
}
void Drive::AddSmartDashboardItems()
{
	SmartDashboard::PutNumber("Speed Controller 1", speedControllerFL->Get());
	SmartDashboard::PutNumber("Speed Controller 2", speedControllerFR->Get());
	SmartDashboard::PutNumber("Speed Controller 3", speedControllerBL->Get());
	SmartDashboard::PutNumber("Speed Controller 4", speedControllerBR->Get());
	SmartDashboard::PutNumber("Gyro Angle", gyro->GetAngle());
}
void Drive::InitDefaultCommand() {
    // Set the default command for a subsystem here.
	SetDefaultCommand(new DriveWithJoystick());
}
// Put methods for controlling this subsystem
// here. Call these from Commands.

void Drive::takeInput(){
	float X = -CommandBase::oi->getDriverJoystick()->GetX();
	float Y = -CommandBase::oi->getDriverJoystick()->GetY();

	// Limit the acceleraion of the robot.
	// This is done to prevent brownouts.
	if (X > oldX + MAX_CHANGE) X = oldX + MAX_CHANGE; // MAX_CHANGE set in header file
	else if (X < oldX - MAX_CHANGE) X = oldX - MAX_CHANGE;
	if (Y > oldY + MAX_CHANGE) Y = oldY + MAX_CHANGE;
	else if (Y < oldY - MAX_CHANGE) Y = oldY - MAX_CHANGE;


	/*if (CommandBase::oi->getDriverButtonPressed1)) {
		//robotDrive4->ArcadeDrive(2*Y/3, X);
		return;
	}*/
	robotDrive4->ArcadeDrive(X, Y);

	// Store these values for next time
	oldX = X;
	oldY = Y;
}
void Drive::setMotors(float leftSpeed, float rightSpeed){
	//speedControllerFL->Set(-leftSpeed);
	//speedControllerFR->Set(-rightSpeed);
	//speedControllerBL->Set(leftSpeed);
	//speedControllerBR->Set(rightSpeed);
}
float Drive::returnAngle(){
	return gyro->GetAngle();
}
AnalogGyro* Drive::getGyro()
{
	return gyro.get();
}

