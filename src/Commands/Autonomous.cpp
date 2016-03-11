
#include "Autonomous.h"
#include "Commands/Move.h"
#include "Commands/Rotate.h"
#include "Commands/ShootMoveFetcher.h"
#include "Commands/MoveFetcher.h"

Autonomous::Autonomous(int selection) : CommandGroup("Autonomous") {
	// [AJN] I believe this is necessary to let the WPI code know that
	// each Subsystem you are going to use is needed by the command so
	// that it can ensure an instance is constructed.
	// Requires(Robot::drive.get());

	switch(selection){
	case 1: // Drive forward
		AddSequential(new Move(4, .4));
		break;
	case 2: // Drive and shoot (lowbar)
		AddSequential(new ShootMoveFetcher());
		AddSequential(new MoveFetcher(false, 1, false));
		AddSequential(new Move(4, .4));
		AddSequential(new Rotate(45));
		AddSequential(new Move(1, .4));
		AddSequential(new ShootMoveFetcher());
		break;
	case 3: // Drive forward short
		AddSequential(new Move(1.5, .4));
		break;
	default:
		break;
	}

}
