
#include "Autonomous.h"
#include "Commands/Move.h"
#include "Commands/Rotate.h"

Autonomous::Autonomous() : CommandGroup("Autonomous") {
	// [AJN] I believe this is necessary to let the WPI code know that
	// each Subsystem you are going to use is needed by the command so
	// that it can ensure an instance is constructed.
	// Requires(Robot::drive.get());

	AddSequential(new Move(1,.5));
	AddSequential(new Rotate(90));
	AddSequential(new Move(1,.5));
	AddSequential(new Rotate(180));
	AddSequential(new Move(1,.5));
	AddSequential(new Rotate(270));
	AddSequential(new Move(1,.5));
	AddSequential(new Rotate(0));
}



