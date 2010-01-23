/*
 *	PIDEncoder.h
 *
 *	Created by RC Howe on 1/21/10
 *  Copyright 2010 RC Howe. All rights reserved.
 */

#pragma once

#include "WPILib.h"

/**
 *	\brief A wrapper class to allow us to use a PID loop with the encoder.
 */
class PIDEncoder : public Encoder, public PIDSource
{
public:
	/**
	 *	\brief Creates a new PIDEncoder on the given channels assuming the default module
	 *	
	 *	@param channelA Channel A
	 *	@param channelB Channel B
	 */
	PIDEncoder( UINT32 channelA, UINT32 channelB, bool reverseDirection = false );
	
	/**
	 *	\brief Creates a new PIDEncoder on the default channels and module
	 *
	 *	@param slotA Slot A
	 *	@param channelA Channel A
	 *	@param slotB Slot B
	 *	@param channelB Channel B
	 */
	PIDEncoder( UINT32 slotA, UINT32 channelA, UINT32 slotB, UINT32 channelB, bool reverseDirection = false );
	
	/**
	 *	\brief Destroys a PIDController instance
	 */
	virtual ~PIDEncoder();
	
	/**
	 *	\brief Gets gear count for the PID parent
	 *	@return	Gear Count
	 */
	virtual double PIDGet();
};
