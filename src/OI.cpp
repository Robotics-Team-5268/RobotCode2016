
#include <Commands/DriveWithButton.h>
#include "OI.h"
#include "Commands/Rotate.h"
#include "Commands/Move.h"
#include "Commands/MoveFetcher.h"
#include "SmartDashboard/SmartDashboard.h"


OI::OI() {
    // Process operator interface input here.
    driverJoystick.reset(new Joystick(0));
    shooterJoystick.reset(new Joystick(1));

    for(int i = 0; i < 10; i++){
    	driverBtns.push_back(JoystickButton(driverJoystick.get(), i));
    	shooterBtns.push_back(JoystickButton(shooterJoystick.get(), i));
    }

    shooterBtns[0].WhenPressed(new MoveFetcher(true));
    shooterBtns[1].WhenPressed(new MoveFetcher(false));

    // SmartDashboard Buttons
    SmartDashboard::PutData("Rotate", new Rotate(90));
    SmartDashboard::PutData("Move", new Move(30, .3));
}

std::shared_ptr<Joystick> OI::getDriverJoystick() {
   return driverJoystick;
}

std::shared_ptr<Joystick> OI::getShooterJoystick() {
   return shooterJoystick;
}

bool OI::getDriverButtonPressed(int btnNum)
{
	return driverBtns[btnNum].Get();
}

bool OI::getShooterButtonPressed(int btnNum)
{
	return shooterBtns[btnNum].Get();
}
