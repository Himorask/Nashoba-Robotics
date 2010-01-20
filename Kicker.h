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
	/**
	 *	Creates a new kicker.
	 *
	 *	@param motorChannel Channel for the motor that winds the kicker
	 *	@param pneumaticChannel The pneumatic that holds the kicker back
	 *	@param encoderChannel1 The encoder
	 *	@param encoderChannel2 The encoder
	 */
	explicit Kicker( UINT32 motorChannel, UINT32 pneumaticChannel,
					 UINT32 encoderChannel1, UINT32 encoderChannel2 );
	
	/**
	 *	Destroys the encoder
	 */
	virtual ~Kicker();
	
	/**
	 *	Releases the pneumatic to kick, then winds the motor back up
	 *
	 *	This currently assumes that we're using a solenoid.
	 *
	 *	It will wind the motor back up with the given power
	 *	@param power Power to kick with
	 */
	void Kick( float power = 1 );
	
	class KickerException : public std::exception
	{
	public:
		explicit KickerException( const std::string description );
		virtual ~KickerException();
		
		virtual const std::string Description() const throw();
		
	private:
		std::string description;
	};
	
private:
	Encoder encoder;
	Victor	motor;
	Solenoid pneumatic;
	
	int		lastFired;
	
	// TODO: Make this a real value
	const int kWoundTicks = 10;
};