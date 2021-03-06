
#include "Fetcher.h"

Fetcher::Fetcher() : Subsystem("Fetcher"){
    fetcherCANTalon = RobotMap::fetcherSpeedController;
    fetcherTalon = RobotMap::fetcherWheelSpeedController;
    fetcherCANTalon->SetSafetyEnabled(false);
}
void Fetcher::AddSmartDashboardItems()
{
	SmartDashboard::PutNumber("Fetcher CAN Talon", fetcherCANTalon->Get());
	SmartDashboard::PutNumber("Fetcher Talon", fetcherTalon->Get());
}
void Fetcher::InitDefaultCommand() {
    // Set the default command for a subsystem here.
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
void Fetcher::setCANTalonSpeed(double speed){
	fetcherCANTalon->Set(speed);
}
void Fetcher::setTalonSpeed(double speed){
	fetcherTalon->Set(speed);
}
bool Fetcher::checkIfFinished(bool out)
{
	if((fetcherCANTalon->IsFwdLimitSwitchClosed() && out)
	|| (fetcherCANTalon->IsRevLimitSwitchClosed() && !out)){
		return true;
	}
	return false;
}
bool Fetcher::getLimitSwitch(bool a)
{
	SmartDashboard::PutNumber("CAN Talon 1", fetcherCANTalon->Get());
	if(a)
		return fetcherCANTalon->IsFwdLimitSwitchClosed();
	else
		return fetcherCANTalon->IsRevLimitSwitchClosed();
}
bool Fetcher::isDrawerOut(){
	return fetcherCANTalon->IsFwdLimitSwitchClosed();
}
