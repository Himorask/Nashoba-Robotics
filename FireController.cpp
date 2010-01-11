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
:	IRefCount(),
	kicker( 1 ),
	joystick( 2 )
{
	liftController = NULL;
	compressor.Start();
}

FireController :: ~FireController()
{
	compressor.Stop();
}

static void* FireController :: ThreadEntry( void *fireController )
{
	FireController *fc = (FireController *) fireController;
	fc->retain();
	
	fc->Run();
	
	fc->release();
	return NULL;
}

void FireController :: Run()
{
	// Only set the pneumatic if the value changes.
	static bool fire = false;
	while ( true )
	{
		bool f = joystick.GetTrigger();
		if ( f != fire )
			kicker.Set( f );
		fire = f;
		Wait( 0.005f );
	}
}
