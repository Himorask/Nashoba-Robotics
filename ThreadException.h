/*
 *  ThreadException.h
 *  Robotics
 *
 *  Created by RC Howe on 1/6/10.
 *  Copyright 2010 RC Howe. All rights reserved.
 *
 */

#pragma once

#include <exception>

/**
 *	A thread exception.
 */
class ThreadException : public std::exception
{
public:
	ThreadException( const char *message );
	
	virtual const char* what() const throw ();
	
private:
	const char *message;
};