/*
 *  ThreadException.cpp
 *  Robotics
 *
 *  Created by RC Howe on 1/6/10.
 *  Copyright 2010 RC Howe. All rights reserved.
 *
 */

#include "ThreadException.h"

ThreadException :: ThreadException( const char *message )
{
	this->message = message;
}

const char * ThreadException :: what() const throw ()
{
	return message;
}