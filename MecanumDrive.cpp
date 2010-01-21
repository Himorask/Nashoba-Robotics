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
	frontLeftEncoder( 1, 2 ),
	frontRightEncoder( 3, 4 ),
	rearLeftEncoder( 5, 6 ),
	rearRightEncoder( 7, 8 ),
	
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
	// Convert angle and magnitude to x and y coordinates
	float x = magnitude * cos( direction * 180 / PI );
	float y = magnitude * sin( direction * 180 / PI );
	
	// Sets the PID setpoints to their mecanum values
	// according to the NASA spec
	frontLeftPID.SetSetpoint(  ( x + y ) / kDriveXYSensitivity + rotation / kDriveZSensitivity );
	frontRightPID.SetSetpoint( ( x - y ) / kDriveXYSensitivity - rotation / kDriveZSensitivity );
	rearLeftPID.SetSetpoint(   ( x - y ) / kDriveXYSensitivity + rotation / kDriveZSensitivity );
	rearRightPID.SetSetpoint(  ( x + y ) / kDriveXYSensitivity - rotation / kDriveZSensitivity );
}
