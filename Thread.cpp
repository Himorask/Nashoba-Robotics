/*
 *  Thread.cpp
 *  Robotics
 *
 *  Created by RC Howe on 1/6/10.
 *  Copyright 2010 RC Howe. All rights reserved.
 *
 */

#include "Thread.h"

Thread :: Thread( FunctionRef function )
{
	running = false;
	this->function = function;
}

Thread :: ~Thread()
{
}

void Thread :: start( void *userInfo )
{
	if ( running )
		return;
	
	running = true;
	pthread_create( &thread, NULL, function, userInfo );
}

bool Thread :: isRunning()
{
	return running;
}

Mutex :: Mutex() throw( ThreadException )
{
	locked = false;
	
	if ( pthread_mutex_init( &critical, NULL ) != 0 )
		throw ThreadException( "Unable to create mutex" );
}

Mutex :: ~Mutex() throw( ThreadException )
{
	if ( pthread_mutex_destroy( &critical ) != 0 )
		throw ThreadException( "Unable to destroy mutex" );}

void Mutex :: lock() throw( ThreadException )
{
	if ( pthread_mutex_lock( &critical ) != 0 )
		throw ThreadException( "Unable to lock mutex" );
	
	locked = true;
}

void Mutex :: unlock() throw( ThreadException )
{
	if ( locked == false )
		throw ThreadException( "Attempting to unlock an already unlocked mutex." );
	
	locked = false;
	
	if ( pthread_mutex_unlock( &critical ) != 0 )
		throw ThreadException( "Unable to unlock mutex" );
}

Mutex :: operator bool () const
{
	return locked;
}
