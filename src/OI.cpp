
#include <Commands/DriveWithButton.h>
#include "OI.h"
#include "Commands/Rotate.h"
#include "Commands/Move.h"
#include "Commands/MoveFetcher.h"
#include "Commands/ShootMoveFetcher.h"
#include "SmartDashboard/SmartDashboard.h"


OI::OI() {
    // Process operator interface input here.
    driverJoystick.reset(new Joystick(0));
    shooterJoystick.reset(new Joystick(1));

    for(int i = 1; i <= 10; i++){
    	driverBtns.push_back(new JoystickButton(driverJoystick.get(), i));
    	shooterBtns.push_back(new JoystickButton(shooterJoystick.get(), i));
    }

    shooterBtns[0]->WhenPressed(new MoveFetcher(true));
    shooterBtns[1]->WhenPressed(new MoveFetcher(false));
    shooterBtns[2]->WhenPressed(new ShootMoveFetcher());

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
	return driverBtns[btnNum-1]->Get();
}

bool OI::getShooterButtonPressed(int btnNum)
{
	return shooterBtns[btnNum-1]->Get();
}
