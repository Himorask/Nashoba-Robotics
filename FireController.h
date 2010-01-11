/*
 *  FireController.h
 *  Robotics
 *
 *  Created by RC Howe on 1/9/10.
 *  Copyright 2010 RC Howe. All rights reserved.
 *
 */

#pragma once

#include "WPILib.h"
#include "IRefCount.h"

class FireController : IRefCount
{
public:
	explicit FireController();
	virtual ~FireController();
	
	static void* ThreadEntry( void *fireController );
	
private:
	void Run();
	
	LiftController	*liftController;
	Joystick		joystick;
	Compressor		compressor;
	
	Solenoid		kicker;
};