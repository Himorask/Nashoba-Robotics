/*
 *  Robot.cpp
 *  Robotics
 *
 *  Created by RC Howe on 1/6/10.
 *  Copyright 2010 RC Howe. All rights reserved.
 *
 */

#include "Robot.h"

Robot :: Robot( void )
{
	GetWatchdog().SetExpiration( 0.1f );
	
	fireController = new FireController();
}

Robot :: ~Robot()
{
	fireController->release();
}

void Robot :: Autonomous( void )
{
	GetWatchdog().SetEnabled( false );
	
	// Create and start the fire controller thread
	Thread fireControllerThread( FireController::ThreadEntry );
	fireControllerThread.start( fireController );
	
	driveController.Run();
}

void Robot :: OperatorControl( void )
{
	GetWatchdog().SetEnabled( true );
	
	driveController.Run();
}
