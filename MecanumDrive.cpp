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

#define ENFORCE_RANGE(value,min,max) if ( value < min ) value = min; if ( value > max ) value = max
#define MOTOR_RANGE_MIN 1.0f
#define MOTOR_RANGE_MAX 1.0f

MecanumDrive :: MecanumDrive( SpeedController *frontLeftMotor,
							  SpeedController *rearLeftMotor,
							  SpeedController *frontRightMotor,
							  SpeedController *rearRightMotor,
							  float sensitivity )
: RobotDrive( frontLeftMotor,
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
	// Directions
	// These will be from -1 to 1
	float x, y;
	x = sinf( direction ) * magnitude;
	y = cosf( direction ) * magnitude;
	
	float leftFront, rightFront, leftRear, rightRear;
	
	leftFront = rightRear = y - x + 1.0f;
	rightFront = leftRear = 1.0f - y - x;
	
	// Reverse the direction of the rear motors
	rightRear = 1.0f - rightRear;
	leftRear  = 1.0f - leftRear;
	
	// Add spin in there
	rightFront = rightFront - rotation + 0.5f;
	rightRear  = rightRear  - rotation + 0.5f;
	leftFront  = leftFront  - rotation + 0.5f;
	leftRear   = leftRear   - rotation + 0.5f;
	
	// Ensure that we're not sending bad values to the motors
	ENFORCE_RANGE( rightFront, -1.0f, 1.0f );
	ENFORCE_RANGE( rightRear,  -1.0f, 1.0f );
	ENFORCE_RANGE( leftFront,  -1.0f, 1.0f );
	ENFORCE_RANGE( leftRear,   -1.0f, 1.0f );
	
	// Set the motors
	frontLeftMotor->Set( leftFront );
	frontRightMotor->Set( rightFront );
	rearLeftMotor->Set( leftRear );
	rearRightMotor->Set( rightRear );
}
