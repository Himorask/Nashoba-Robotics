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
	kicker( 1 ),
	joystick( 2 )
{
	liftController = NULL;
}

FireController :: ~FireController()
{
}

void FireController :: Run()
{
}
