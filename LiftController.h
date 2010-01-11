/*
 *  LiftController.h
 *  Robotics
 *
 *  Created by RC Howe on 1/9/10.
 *  Copyright 2010 RC Howe. All rights reserved.
 *
 */

#pragma once

#include "WPILib.h"
#include "IRefCount.h"

class LiftController : IRefCount
{
public:
	LiftController();
	void ~LiftController();
	
	static void* ThreadEntry( void *liftController );
	
	void Run();
	
private:
	
};