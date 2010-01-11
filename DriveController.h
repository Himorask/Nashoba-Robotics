/*
 *  DriveController.h
 *  Robotics
 *
 *  Created by RC Howe on 1/9/10.
 *  Copyright 2010 RC Howe. All rights reserved.
 *
 */

#pragma once

#include "WPILib.h"

class DriveController
{
public:
	explicit DriveController();
	virtual ~DriveController();
	
	void Run();
	
protected:
	void Autonomous();
	void OperatorControl();
	
	RobotDrive	drive;
	Joystick	joystick;
};