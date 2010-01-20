/*
 *  FireController.cpp
 *  Robotics
 *
 *  Created by RC Howe on 1/9/10.
 *  Copyright 2010 RC Howe. All rights reserved.
 *
 */

#include "FireController.h"

FireController :: FireController()
:	IThreadable(),
kicker( 5, 6, 9, 10 ),
joystick( 2 )
{
	liftController = NULL;
	state = 0;
}

FireController :: ~FireController()
{
	if ( liftController != NULL )
		delete liftController;
}

void FireController :: Run()
{
	while ( true )
	{
		while ( state == RobotStateOperatorControl )
		{
			while ( joystick.GetTrigger() != true )
			{
				Wait( 0.05 );
			}
			
			float throttle = joystick.GetThrottle();
			kicker.Kick( (throttle > 1) ? 1 : throttle );
		}
		
		while ( state == RobotStateAutonomous )
		{
			Wait( 0.1 );
		}
		
		if ( state != RobotStateAutonomous && state != RobotStateOperatorControl )
			Wait( 0.1 );
	}
}

void FireController :: SetAutonomous()
{
	state = RobotStateAutonomous;
}

void FireController :: SetOperatorControl()
{
	state = RobotStateOperatorControl;
}
