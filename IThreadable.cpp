/*
 *	IThreadable.cpp
 *
 *	Copyright 2010 RC Howe
 *	All Rights Reserved
 */

#include "IThreadable.h"

IThreadable :: IThreadable()
: IRefCount()
{
}

IThreadable :: ~IThreadable()
{
}

static void* IThreadable :: ThreadEntry( void *infoAndObject )
{
	// Cast!
	// FIXME: Replace this with a fancy C++ cast
	UserInfoAndThreadable *uit = (UserInfoAndThreadable *) infoAndObject;
	
	// Call the run loop;
	uit->threadable->Run( uit->userInfo );
	
	// Delete the UIT from the calling method in Thread
	delete uit;
	
	// Return NULL so no one complains
	return NULL;
}
