// OpenCL_helloWorld.cpp : Defines the entry point for the console application.
//// my first program in C++ OPENCL
// Youtube Wesley Shillingford Youtube [OpenCL 1.2 C++ Tutorials 2/9]
//TEST this aint no binary file
#include "stdafx.h"
#include <iostream>

#include <CL/cl.hpp>

int main()
{
	cl::Platform platform;

	std::cout << "Hello World! UTF-8";
    return 0;
}

