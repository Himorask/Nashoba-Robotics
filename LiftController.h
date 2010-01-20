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
#include "IThreadable.h"

class LiftController : IThreadable
{
public:
	LiftController();
	void ~LiftController();
		
	void Run();
	
private:
	
};