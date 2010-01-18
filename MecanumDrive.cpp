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

/**
 *	\brief Holnomic Drive convenience method
 *
 *	@param magnitude A magnitude from (I think) 0.0 to 1.0.
 *	@param direction Direction in degrees and (I think) from the front of the robot.
 *	@param rotation Rotation from -1.0 to 1.0
 */
void MecanumDrive :: HolonomicDrive( float magnitude, float direction, float rotation )
{
	directionRad = direction * 180 / PI;
	
	float x, y;
	x = sinf( directionRad ) * magnitude;
	y = cosf( directionRad ) * magnitude;
	
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
