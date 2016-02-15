
#include <Commands/DriveWithButton.h>
#include "OI.h"
#include "Commands/Rotate.h"
#include "Commands/Move.h"
#include "SmartDashboard/SmartDashboard.h"


OI::OI() {
    // Process operator interface input here.
    joystick1.reset(new Joystick(0));
    joystickButton1.reset(new JoystickButton(joystick1.get(), 1));
    joystickButton1->WhenPressed(new Rotate(90));
    joystickButton2.reset(new JoystickButton(joystick1.get(), 2));
    joystickButton2->WhenPressed(new Move(30, .3));

    // SmartDashboard Buttons
    SmartDashboard::PutData("Rotate", new Rotate(90));
    SmartDashboard::PutData("Move", new Move(30, .3));
}


std::shared_ptr<Joystick> OI::getJoystick1() {
   return joystick1;
}
bool OI::getButton1Pressed()
{
	return joystickButton1->Get();
}
bool OI::getButton2Pressed()
{
	return joystickButton2->Get();
}
