/*
 *  DriveController.cpp
 *  Robotics
 *
 *  Created by RC Howe on 1/9/10.
 *  Copyright 2010 RC Howe. All rights reserved.
 *
 */

#include "DriveController.h"

DriveController :: DriveController()
:	drive( 1, 2 ),
	joystick( 1 )
{
}

DriveController :: ~DriveController()
{
}

void DriveController :: Run()
{
	if ( IsAutonomous() )
		Autonomous();
	
	else if ( IsOperatorControl() )
		OperatorControl();
}

void DriveController :: Autonomous()
{
	// Drive forward for two seconds
	drive.Drive( 0.5, 0.0 );
	Wait( 2.0f );
	drive.Drive( 0.0, 0.0 );
}

void DriveController :: OperatorControl()
{
	while ( IsOperatorControl() )
	{
		GetWatchdog().Feed();
		
		drive.ArcadeDrive( joystick );
		Wait( 0.005f );
	}
}