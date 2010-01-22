/*
 *  DriveController.cpp
 *  Robotics
 *
 *  Created by RC Howe on 1/9/10.
 *  Copyright 2010 RC Howe. All rights reserved.
 *
 */

#include "DriveController.h"

DriveController :: DriveController( Watchdog *watchdog )
// TODO: Change to actual values
:	frontLeftMotor(  4, 1 ),
	frontRightMotor( 4, 2 ),
	backLeftMotor(   4, 3 ),
	backRightMotor(  4, 4 ),
	drive( &frontLeftMotor, &backLeftMotor, &frontRightMotor, &backRightMotor ),
	joystick( 1 ),
	gyro( 4, 5 )
{
	this->watchdog = watchdog;
}

DriveController :: ~DriveController()
{
}

void DriveController :: Autonomous()
{
	drive.HolonomicDrive( 1.0f, PI, 0.0f );
	Wait( 1.0f );
	drive.HolonomicDrive( 0.0f, 0, 0.0f );
}

void DriveController :: OperatorControl()
{
	watchdog->Feed();
	
	// TODO: I doubt the angle will be, but if it is not an angle from the
	//		 front of the robot, that will need to be changed.
	drive.HolonomicDrive( joystick.GetMagnitude(),
						  (float) ((joystick.GetDirectionDegrees() + gyro.GetAngle()) % 360),
						  joystick.GetTwist() );
	Wait( 0.005f );
}
