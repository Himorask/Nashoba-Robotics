/*
 *  MecanumDrive.h
 *  
 *
 *  Created by RC Howe on 1/13/10.
 *  Copyright 2010 RC Howe. All rights reserved.
 *
 */

#pragma once

#include "WPILib.h"

class MecanumDrive : public RobotDrive
{
public:
	MecanumDrive( SpeedController *frontLeftMotor,
				  SpeedController *rearLeftMotor,
				  SpeedController *frontRightMotor,
				  SpeedController *rearRightMotor,
				  float sensitivity = 0.5 );

	virtual ~MecanumDrive();
	
	void HolonomicDrive( float magnitude, float direction, float rotation );
	
private:
	SpeedController *frontLeftMotor,
					*frontRightMotor,
					*rearLeftMotor,
					*rearRightMotor;
};
