/*
 *  IRefCount.h
 *  Robotics
 *
 *  Created by RC Howe on 1/9/10.
 *  Copyright 2010 RC Howe. All rights reserved.
 *
 */

#pragma once

class IRefCount
{
public:
	IRefCount();
	virtual ~IRefCount();
	
	void retain();
	void release();
	
private:
	__retcount;
};