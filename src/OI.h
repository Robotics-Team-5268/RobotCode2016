
#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI {
private:
	std::shared_ptr<Joystick> joystick1;
	std::shared_ptr<JoystickButton> joystickButton1;
	std::shared_ptr<JoystickButton> joystickButton2;
public:
	OI();

	std::shared_ptr<Joystick> getJoystick1();
	bool getButton1Pressed();
	bool getButton2Pressed();
};

#endif
