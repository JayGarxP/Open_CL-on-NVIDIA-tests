// OpenCL_helloWorld.cpp : Defines the entry point for the console application.
//// my first program in C++ OPENCL
// Youtube Wesley Shillingford Youtube [OpenCL 1.2 C++ Tutorials 4/9]

#include "stdafx.h"
#include <iostream>

#include <CL/cl.hpp>

int main()
{
	std::vector<cl::Platform> platforms;
	std::vector<cl::Device> devices;
	std::vector<cl::Device> gpu_devices;
	cl::Platform::get(&platforms);


	_ASSERT(platforms.size() > 0);

	auto platform = platforms.front();
	auto gpu_platform = platforms.back();
	platform.getDevices(CL_DEVICE_TYPE_ALL, &devices);
	gpu_platform.getDevices(CL_DEVICE_TYPE_GPU, &gpu_devices);

	_ASSERT(devices.size() > 0);

	auto device = devices.front();
	auto intel_gpu_device = devices.back(); //Intel is CPU and GPU, 2 seperate devices.

	auto REAL_GPU_device = gpu_devices.front();


	auto intel_gpu_vendor = intel_gpu_device.getInfo<CL_DEVICE_VENDOR>();

	//getInfo works on platform, context, device, etc.
	auto vendor = device.getInfo<CL_DEVICE_VENDOR>(); 
	auto version = device.getInfo<CL_DEVICE_VERSION>();

	auto nvidia_vendor = REAL_GPU_device.getInfo<CL_DEVICE_VENDOR>();


	std::cout << "Hello World! End of Part 4 " + vendor;
	std::cout << "second vendor poll: " + intel_gpu_vendor;
	std::cout << "inVIDYA vendor poll: " + nvidia_vendor; //use Nsight legacy debug (have to detach THIS local c++ debugger, attach cuda/openCL debugger, not working yet)
	while (true) {}
    return 0;
}

