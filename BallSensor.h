/*
 *  BallSensor.h
 *  
 *
 *  Created by RC Howe on 1/29/10.
 *  Copyright 2010 RC Howe. All rights reserved.
 *
 */

#pragma once

#include "WPILib.h"

/**
 *	\brief A class to abstract away the ball sensor
 *
 *	There is no implementation in this class - Get() returns true every time
 */
class BallSensor : public SensorBase
{
public:
	/**
	 *	Creates a new ball sensor on the given port and slot
	 *	@param slot Slot in the cRIO to use
	 *	@param port Port on the digital sidecar to use
	 */
	BallSensor( UINT32 slot, UINT32 port );
	
	/**
	 *	Destroys a ball sensor
	 */
	virtual ~BallSensor();
	
	/**
	 *	Gets whether or not a ball breaks the beam of the sensor
	 *	Currently this function only returns true
	 *
	 *	@return True if a ball is present, otherwise false
	 */
	bool Get();
};