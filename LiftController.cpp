/*
 *  LiftController.cpp
 *  Robotics
 *
 *  Created by RC Howe on 1/9/10.
 *  Copyright 2010 RC Howe. All rights reserved.
 *
 */

#include "LiftController.h"

LiftController :: LiftController()
:	IRefCount()
{
}

LiftController :: ~LiftController()
{
}

static void* LiftController :: ThreadEntry( void *liftController )
{
	LiftController *lc = (LiftController *) liftController;
	lc->retain();
	
	lc->Run();
	
	lc->release();
	return NULL;
}

void LiftController :: Run()

}