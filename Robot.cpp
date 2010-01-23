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
	
	// Start the camera
	
	// I think we need to stop the video server before doing this
	// FIXME: Check this
	videoServer.Stop();
	
	if ( StartCameraTask( 13, 0, k320x240, ROT_0 ) == -1 )
		dprintf( LOG_ERROR, "Failed to spawn camera task: %s", GetVisionErrorText( GetLastVisionError() ) );
	
	// Camera startup timeout
	Wait( 2.0f );
	
	videoServer.Start();
}

Robot :: ~Robot()
{
}

void Robot :: Autonomous( void )
{
	GetWatchdog().SetEnabled( false );
}

void Robot :: OperatorControl( void )
{
	GetWatchdog().SetEnabled( true );
}
