/*
 *  Kicker.h
 *  
 *
 *  Created by RC Howe on 1/19/10.
 *  Copyright 2010 RC Howe. All rights reserved.
 *
 */

#pragma once

class Kicker
{
public:
	explicit Kicker( UINT32 motorChannel, UINT32 pneumaticChannel,
					 UINT32 encoderChannel1, UINT32 encoderChannel2 );
	virtual ~Kicker();
	
	void Kick();
	
private:
	Encoder encoder;
	Victor	motor;
	Solenoid pneumatic;
	
	int		lastFired;
	
	// TODO: Make this a real value
	const int kWoundTicks = 10;
};