/*
 *  Stub.h
 *  
 *
 *  Created by RC Howe on 1/29/10.
 *  Copyright 2010 RC Howe. All rights reserved.
 *
 */

#pragma once

/**
 *	\file Stub.h
 */

/*
 *	\def STUB(message)
 *	\brief A macro to indicate a stub
 */

#include <iostream>

#define STUB(message) std::cout << "STUB: Method " + message + " is a stub."