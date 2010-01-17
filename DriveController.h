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
#include "MecanumDrive.h"

// Define pi if not defined already
#ifndef PI
#define PI 3.141592653f
#endif

class DriveController
{
public:
	DriveController();
	virtual ~DriveController();
	
	void Run();
	
protected:
	void Autonomous();
	void OperatorControl();
	
	Jaguar		 frontLeftMotor,
				 frontRightMotor,
				 backLeftMotor,
				 backRightMotor;
	MecanumDrive drive;
	Joystick	 joystick;
};