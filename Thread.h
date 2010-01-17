/*
 *  Thread.h
 *  Robotics
 *
 *  Created by RC Howe on 1/6/10.
 *  Copyright 2010 RC Howe. All rights reserved.
 *
 */

#pragma once

#include <pthread.h>
#include "ThreadException.h"
#include "IThreadable.h"

/**
 *	A function reference to pass to a thread
 *
 *	In the thread class, the return value is never used.
 */
typedef void*(*FunctionRef)(void*);

/**
 *	\brief A thread class
 *	This class was created to abstract the POSIX threads API
 *
 *	Threads are one-shot; they cannot be run multiple times.
 *
 *	All threads are terminated upon program exit.
 */
class Thread
{
public:
	/**
	 *	Creates a new thread with function denoted by function
	 *	@param function The function to be run when the thread is run
	 */
	explicit Thread( FunctionRef function );
	
	/**
	 *	Creates a new thread which (indirectly) calls the Run method
	 *	in threadable in a new thread.
	 *	@param threadable An object containing the Run method to start
	 *	the thread on
	 */
	explicit Thread( IThreadable *threadable );
	
	/**
	 *	Destructor
	 */
	virtual ~Thread();
	
	/**
	 *	Starts the thread by calling the entry point function in a new thread.
	 *	@param userInfo An optional parameter for the function.
	 */
	void Start( void *userInfo = NULL );
	
	/**
	 *	Tests whether the thread is currently running.
	 */
	bool		IsRunning();

protected:
	FunctionRef		function;
	IRunnable		*object;
	
private:
	pthread_t		thread;
	
	bool			running;
	pthread_mutex_t	threadStartMutex;
	
	enum ThreadType { THREAD_TYPE_FUNCTION, THREAD_TYPE_CLASS };
	ThreadType type;
};

/**
 *	\brief A mutex
 *
 *	A mutex that can be locked or unlocked. Attempting to lock an already locked mutex will block.
 *	Attempting to unlock an already unlocked mutex will result in a ThreadException.
 */
class Mutex
{
public:
	/**
	 *	\brief Creates a mutex. If the mutex can't be created, a ThreadException is thrown.
	 */
	Mutex() throw ( ThreadException );
	~Mutex() throw( ThreadException );
	
	/**
	 *	Locks the mutex. If the mutex can't be locked, a ThreadException is thrown.
	 */
	void lock() throw ( ThreadException );
	void unlock() throw ( ThreadException );
	
	operator bool () const;
	
private:
	pthread_mutex_t critical;
	bool locked;
};