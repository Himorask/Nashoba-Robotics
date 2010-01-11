/*
 *  Synchronized.h
 *  Robotics
 *
 *  Created by RC Howe on 1/6/10.
 *  Copyright 2010 RC Howe. All rights reserved.
 *
 */

/**
 *	\file Synchronized.h
 *	A synchronization macro
 */

#pragma once
#include "Thread.h"

/**
 *	\def synchronized
 *	This indicates a synchronized block. Synchronized blocks take a mutex and will lock the mutex when the block starts and unlock the mutex when it exits.
 *
 *	Example:
 *	\code
 *	Mutex mutex;
 *
 *	synchronized( mutex )
 *	{
 *		cout << "The mutex is locked.";
 *	}
 *
 *	cout << "The mutex is unlocked.";
 *	\endcode
 */
#define synchronized(M) for( M.lock(); M; M.unlock() )