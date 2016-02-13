
#include "Shooter.h"

Shooter::Shooter() : Subsystem("Shooter"){
    shooterCANTalon = RobotMap::shooterSpeedController;
}
void Shooter::AddSmartDashboardItems()
{
	SmartDashboard::PutNumber("Shooter CAN Talon", shooterCANTalon->Get());
}
void Shooter::InitDefaultCommand() {
    // Set the default command for a subsystem here.
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
void Shooter::setSpeed(double sp){
	shooterCANTalon->Set(sp);
}
bool Shooter::getLimitSwitch(){
	return shooterCANTalon->IsFwdLimitSwitchClosed();
}
void Shooter::resetPosition(){
	shooterCANTalon->SetPosition(0);
}
double Shooter::getTalonPosition(){
	return shooterCANTalon->GetEncPosition();
}
