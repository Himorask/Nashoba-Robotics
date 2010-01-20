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
	
	try
	{
		// Create and start the fire controller thread
		Thread fireControllerThread( FireController );
		fireControllerThread.Start();
	}
	
	catch ( Kicker::KickerException &e )
	{
		cout << e.Description();
	}
}

Robot :: ~Robot()
{
	fireController->release();
}

void Robot :: Autonomous( void )
{
	GetWatchdog().SetEnabled( false );
	
	fireController->SetAutonomous();
	driveController.Autonomous();
}

void Robot :: OperatorControl( void )
{
	GetWatchdog().SetEnabled( true );
	
	fireController->SetOperatorControl();
	driveController.OperatorControl();
}
