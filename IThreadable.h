/*
 *	IThreadable.h
 *
 *	Copyright 2010 RC Howe
 *	All Rights Reserved
 */

#pragma once

#include "IRefCount.h"

/**
 *	\brief A class for threaded objects to derive from.
 *
 *	Objects only need to derive from this class if they're going to use
 *	the IThreadable overload of the Thread class. Objects in this class
 *	need to call the IThreadable constructor from their constructor.
 *
 *	This is very similar to the Java Runnable interface.
 *
 *	You should never explicitly free an IThreadable object. Always call
 *	release() instead. This ensures that other objects that are using
 *	this object still have a valid reference. If you need to ensure that
 *	an IThreadable reference remains valid, call retain() before performing
 *	operations that need it, then call release() when you no longer need
 *	it.
 */
class IThreadable : IRefCount
{
public:
	/**
	 *	Creates a new threadable object and initializes reference counting.
	 */
	IThreadable();
	virtual ~IThreadable();
	
protected:
	/**
	 *	Runs an IThreadable object. This is called by the Thread object when
	 *	run.
	 */
	virtual void Run() throw () = 0;
	
private:
	static void* ThreadEntry( void *infoAndObject );
	
	class UserInfoAndThreadable
	{
	public:
		IThreadable *threadable;
		void *userInfo;
	};
	
	friend class Thread;
};
