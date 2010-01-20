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
#include "IThreadable.h"

/**
 *	A fire controller class
 *	To be implemented later.
 */
class FireController : IThreadable
{
public:
	FireController();
	virtual ~FireController();
	
	void SetAutonomous();
	void SetOperatorControl();
	
private:
	void Run();
	
	Kicker			kicker;
	LiftController	*liftController;
	Joystick		joystick;
	
	RobotState state;
	
	enum RobotState { RobotStateAutonomous = 1, RobotStateOperatorControl = 2 };
};