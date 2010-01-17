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
	type = THREAD_TYPE_FUNCTION;
	this->function = function;
}

Thread :: Thread( IThreadable *threadable )
{
	running = false;
	type = THREAD_TYPE_CLASS;
	this->object = threadable;
}

Thread :: ~Thread()
{
}

void Thread :: Start( void *userInfo )
{
	// Lock the mutex to determine if it's running or not.
	if ( pthread_mutex_lock( &threadStartMutex ) == 0 )
		return;
	
	if ( running )
		return;
	
	running = true;
	
	pthread_mutex_unlock( &threadStartMutex );
	
	// If it's a function pointer, call it
	if ( type == THREAD_TYPE_FUNCTION )
		pthread_create( &thread, NULL, function, userInfo );
	
	// Otherwise, if it's an IThreadable, run it
	else if ( type == THREAD_TYPE_CLASS )
	{
		// This will be deleted in the ThreadEntry method.
		IThreadable::UserInfoAndThreadable *infoAndEntry = new UserInfoAndThreadable();
		
		infoAndEntry->threadable = object;
		infoAndEntry->userInfo = userInfo;
		
		pthread_create( &thread, NULL, IRunnable::ThreadEntry, infoAndEntry );
	}
}

bool Thread :: IsRunning()
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
