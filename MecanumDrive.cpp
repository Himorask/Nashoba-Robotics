/*
 *  MecanumDrive.cpp
 *  
 *
 *  Created by RC Howe on 1/13/10.
 *  Copyright 2010 RC Howe. All rights reserved.
 *
 */

#include "MecanumDrive.h"
#include <math.h>

#ifndef PI
#define PI 3.141592653f
#endif

MecanumDrive :: MecanumDrive( Jaguar *frontLeftMotor,
							  Jaguar *rearLeftMotor,
							  Jaguar *frontRightMotor,
							  Jaguar *rearRightMotor,
							  float sensitivity )
:	RobotDrive( frontLeftMotor,
			    rearLeftMotor,
			    frontRightMotor,
			    rearRightMotor,
			    sensitivity )
{
	// Store pointers to the motors
	this->frontLeftMotor	= frontLeftMotor;
	this->frontRightMotor	= frontRightMotor;
	this->rearLeftMotor		= rearLeftMotor;
	this->rearRightMotor	= rearRightMotor;
}

MecanumDrive :: ~MecanumDrive()
{
}

void MecanumDrive :: HolonomicDrive( float magnitude, float direction, float rotation )
{
	float cosD = cosf( (direction + 45.0f) * PI / 180.0f );
	float sinD = sinf( (direction - 45.0f) * PI / 180.0f );
	
	float frontLeftSpeed	= ENFORCE_RANGE( sinD * magnitude + rotation );
	float rearLeftSpeed		= ENFORCE_RANGE( cosD * magnitude + rotation );
	float frontRightSpeed	= ENFORCE_RANGE( cosD * magnitude - rotation );
	float rearRightSpeed	= ENFORCE_RANGE( sinD * magnitude - rotation );
	
	frontLeftMotor->Set(	frontLeftSpeed );
	rearLeftMotor->Set(		rearLeftSpeed );
	frontRightMotor->Set(	frontRightSpeed );
	rearRightMotor->Set(	rearRightSpeed );
}
