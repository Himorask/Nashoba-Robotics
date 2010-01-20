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
				  UINT32 encoderChannel1, UINT32 encoderChannel2 )
:	motor( motorChannel ),
	encoder( encoderChannel1, encoderChannel2 ),
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
	if ( power > 1.0f || power < 0 )
	{
		throw KickerException( "Invalid power value" );
		return;
	}
	
	// Release the solenoid
	solenoid.Set( false );
	Wait( 1 );
	lastFired = encoder.Get();
	
	// Wind up the motor
	while ( encoder.Get() < lastFired + (power * kWoundTicks) )
	{
		motor.Set( 0.7f );
		Wait( 0.005f );
	}
	motor.Set( 0.0f );
	
	// Reaffix the solenoid
	solenoid.Set( true );
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