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
:	IRefCount()
{
	liftController = NULL;
}

FireController :: ~FireController()
{
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
}
