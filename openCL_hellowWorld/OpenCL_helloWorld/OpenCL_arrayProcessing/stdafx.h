// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//
//Put things in precompiled headers that you aren't going to be touching within the scope of the project.
//DO NOT PUT your custom headers that change all the time in here, the speedup of stdafx.h will be RUINED if you have to rebuild a header.
//   put custom changing-often headers on top of your source code like normal.

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>


#include <CL/cl.hpp>

#include <iostream>
#include <fstream>