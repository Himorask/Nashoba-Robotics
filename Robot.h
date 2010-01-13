/*
 *  Robot.h
 *  Robotics
 *
 *  Created by RC Howe on 1/6/10.
 *  Copyright 2010 RC Howe. All rights reserved.
 *
 */

#pragma once

#include "WPILib.h"

#include "DriveController.h"

#include "Thread.h"
#include "ThreadException.h"

/**
 *	\brief The main robot class.
 *
 *	Program execution starts at this point.
 */
class Robot : public SimpleRobot
{
public:
	Robot( void );
	virtual ~Robot();
	
	/**
	 *	Runs the robot in autonomous mode
	 */
	void Autonomous( void );
	
	/**
	 *	Runs the robot in operator controlled mode.
	 */
	void OperatorControl( void );
	
private:
	DriveController	driveController;
	FireController	*fireController;
};

START_ROBOT_CLASS(Robot);