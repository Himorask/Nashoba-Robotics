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
// TODO: Change to actual values
:	frontLeftMotor( 1 ),
	frontRightMotor( 2 ),
	backLeftMotor( 3 ),
	backRightMotor( 4 ),
	drive( &frontLeftMotor, &backLeftMotor, &frontRightMotor, &backRightMotor ),
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
	drive.HolonomicDrive( 1.0f, PI, 0.0f );
	Wait( 1.0f );
	drive.HolonomicDrive( 0.0f, 0, 0.0f );
}

void DriveController :: OperatorControl()
{
	while ( IsOperatorControl() )
	{
		GetWatchdog().Feed();
		
		int x = joystick.GetX();
		int y = joystick.GetY();
		
		// TODO: I doubt the angle will be, but if it is not an angle from the
		//		 front of the robot, that will need to be changed.
		drive.HolonomicDrive( joystick.GetMagnitude(),
							  joystick.GetDirectionRadians(),
							  joystick.GetTwist() );
		
		Wait( 0.005f );
	}
}