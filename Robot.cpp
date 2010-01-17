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
:	driveController( &GetWatchdog() )
{
	GetWatchdog().SetExpiration( 0.1f );
}

Robot :: ~Robot()
{
}

void Robot :: Autonomous( void )
{
	GetWatchdog().SetEnabled( false );
	
	driveController.Autonomous();
}

void Robot :: OperatorControl( void )
{
	GetWatchdog().SetEnabled( true );
	
	driveController.OperatorControl();
}
