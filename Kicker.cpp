/*
 *  Kicker.cpp
 *  
 *
 *  Created by RC Howe on 1/19/10.
 *  Copyright 2010 RC Howe. All rights reserved.
 *
 */

#include "Kicker.h"

Kicker :: Kicker( UINT32 motorChannel, UINT32 pneumaticChannel,
				  UINT32 currentSensorSlot, UINT32 currentSensorChannel )
:	motor( motorChannel ),
	currentSensor( currentSensorSlot, currentSensorChannel ),
	solenoid( 4, pneumaticChannel )
{
	// Start the encoder
	encoder.Start();
	
	lastFired = 0;
}

Kicker :: ~Kicker()
{
}

void Kicker :: Kick( float power )
{
	// Assume the kicker is cocked.
	
	if ( power > 1.0f || power < 0 )
	{
		throw KickerException( "Invalid power value" );
		return;
	}
	
	ReleaseLatch();
	
	// Re-cock the kicker
	SetElastic( true );
}

void Kicker :: ReleaseLatch()
{
	// Fire the solenoid, which will open the latch
	pneumatic.Set( true );
	
	// Wait for the pneumatic to fire, then reset it
	Wait( kSolenoidTimeout );
	pneumatic.Set( false );
}

void Kicker :: SetElastic( bool back )
{
	if ( back )
		motor.Set( -1.0 );
	else
		motor.Set( 1.0 );
	
	// GetVoltage() returns a value from -10V to 10V
	while ( currentSensor.GetVoltage() < kCurrentSensorMaximumCurrent )
		Wait( kCurrentSensorTimeout );
}

Kicker :: KickerException :: KickerException( const std::string description )
{
	this->description = description;
}

Kicker :: KickerException :: ~KickerException()
{
}

const std::string Kicker :: KickerException :: Description() const throw()
{
	return description;
}