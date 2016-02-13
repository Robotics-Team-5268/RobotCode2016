
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
void Shooter::setPosition(double distance){
	shooterCANTalon->Set(distance);
}
