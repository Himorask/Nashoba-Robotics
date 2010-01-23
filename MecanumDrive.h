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
#include "PIDEncoder.h"

/**
 *	\brief An override of the WPILib RobotDrive class to use mecanum drive
 *
 *	This will eventually be replaced with a PID/Closed Loop Control.
 */
class MecanumDrive : public RobotDrive
{
public:
	/**
	 *	\brief Creates a new mecanum drive object.
	 *
	 *	@param frontLeftMotor	A pointer to the front left motor
	 *	@param rearLeftMotor	A pointer to the rear left motor
	 *	@param frontRightMotor	A pointer to the front right motor
	 *	@param rearRightMotor	A pointer to the rear right motor
	 */
	explicit MecanumDrive( Jaguar *frontLeftMotor,
						   Jaguar *rearLeftMotor,
						   Jaguar *frontRightMotor,
						   Jaguar *rearRightMotor,
						   float sensitivity = 0.5 );

	virtual ~MecanumDrive();
	
	/**
	 *	\brief Drives using mecanum wheels.
	 *
	 *	@param magnitude The magnitude as a value between 0.0 and 1.0
	 *	@param direction The direction as an angle in degrees and referencing
	 *						the front of the robot.
	 *	@param rotation  The rotation of the robot as a value between -1.0 and 1.0.
	 */
	void HolonomicDrive( float magnitude, float direction, float rotation );
	
	// Various PID constants
	// TODO: Test and find values for constants
	static const float kPIDProportional		= 1.0f;
	static const float kPIDIntegral			= 0.0f;
	static const float kPIDDerivitive		= 0.0f;
	
	static const float kDriveXYSensitivity	= 1.0f;
	static const float kDriveZSensitivity	= 1.0f;
	
private:
	Jaguar			*frontLeftMotor,
					*frontRightMotor,
					*rearLeftMotor,
					*rearRightMotor;
	
	PIDEncoder		frontLeftEncoder,
					frontRightEncoder,
					rearLeftEncoder,
					rearRightEncoder;
	
	PIDController	frontLeftPID,
					frontRightPID,
					rearLeftPID,
					rearRightPID;
};
