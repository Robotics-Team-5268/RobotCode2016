
#include "Autonomous.h"
#include "Commands/Move.h"
#include "Commands/Rotate.h"
#include "Commands/ShootMoveFetcher.h"
#include "Commands/MoveFetcher.h"

Autonomous::Autonomous() : CommandGroup("Autonomous") {
	// [AJN] I believe this is necessary to let the WPI code know that
	// each Subsystem you are going to use is needed by the command so
	// that it can ensure an instance is constructed.
	// Requires(Robot::drive.get());
	AddSequential(new MoveFetcher(true, false));
	AddSequential(new MoveFetcher(false, 1.5, false));
	AddSequential(new Move(1,.3));
	AddSequential(new Rotate(90));
	AddSequential(new ShootMoveFetcher());
}



