/*
 *  IRefCount.cpp
 *  Robotics
 *
 *  Created by RC Howe on 1/9/10.
 *  Copyright 2010 RC Howe. All rights reserved.
 *
 */

#include "IRefCount.h"

IRefCount :: IRefCount()
{
	__retcount = 1;
}

IRefCount :: ~IRefCount()
{
}

void IRefCount :: retain()
{
	__retcount++;
}

void IRefCount :: release()
{
	__retcount--;
	
	if ( __retcount <= 0 )
		delete this;
}