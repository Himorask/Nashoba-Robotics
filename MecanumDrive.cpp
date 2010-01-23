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
			    sensitivity ),
	// Encoders
	frontLeftEncoder(	1, 2 ),
	frontRightEncoder(	3, 4 ),
	rearLeftEncoder(	5, 6 ),
	rearRightEncoder(	7, 8 ),
	
	// PIDs
	frontLeftPID(	kPIDProportional, kPIDIntegral, kPIDDerivitive, &frontLeftEncoder,	frontLeftMotor	),
	frontRightPID(	kPIDProportional, kPIDIntegral, kPIDDerivitive, &frontRightEncoder, frontRightMotor ),
	rearLeftPID(	kPIDProportional, kPIDIntegral, kPIDDerivitive, &rearLeftEncoder,	rearLeftMotor	),
	rearRightPID(	kPIDProportional, kPIDIntegral, kPIDDerivitive, &rearRightEncoder,	rearRightMotor	)
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
	
	frontLeftPID->SetSetpoint(	frontLeftSpeed );
	rearLeftPID->SetSetpoint(	rearLeftSpeed );
	frontRightPID->SetSetpoint(	frontRightSpeed );
	rearRightPID->SetSetpoint(	rearRightSpeed );
}
