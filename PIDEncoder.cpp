/*
 *	PIDEncoder.h
 *
 *	Created by RC Howe on 1/21/10
 *  Copyright 2010 RC Howe. All rights reserved.
 */

#include "PIDEncoder.h"

PIDEncoder :: PIDEncoder( UINT32 channelA, UINT32 channelB, bool reverseDirection )
:	Encoder( channelA, channelB, reverseDirection )
{
}

PIDEncoder :: PIDEncoder( UINT32 slotA, UINT32 channelA, UINT32 slotB, UINT32 channelB, bool reverseDirection )
:	Encoder( slotA, channelA, slotB, channelB, reverseDirection )
{
}

double PIDEncoder :: PIDGet()
{
	return GetRate();
}
