#include "LEDController.h"
#include "../RobotMap.h"

LEDController::LEDController() :
		Subsystem("ExampleSubsystem")
{
	ledRelay1 = RobotMap::ledRelay1;
	ledRelay2 = RobotMap::ledRelay2;
	ledRelay3 = RobotMap::ledRelay3;
	ledRelay4 = RobotMap::ledRelay4;
}

void LEDController::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
void LEDController::TurnOff()
{
	ledRelay1->Set(Relay::kOff);
	ledRelay2->Set(Relay::kOff);
	ledRelay3->Set(Relay::kOff);
	ledRelay4->Set(Relay::kOff);
}

void LEDController::TurnOn()
{
	ledRelay1->Set(Relay::kOn);
	ledRelay2->Set(Relay::kOn);
	ledRelay3->Set(Relay::kOn);
	ledRelay4->Set(Relay::kOn);
}
