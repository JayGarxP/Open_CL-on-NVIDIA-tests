// OpenCL_helloWorld.cpp : Defines the entry point for the console application.
//// my first program in C++ OPENCL
// Youtube Wesley Shillingford Youtube [OpenCL 1.2 C++ Tutorials 6/9] first proper example.

#include "stdafx.h"
#include <iostream>
#include <fstream>

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
	

	std::ifstream helloWorldFile("HelloWorld.cl");

	std::string src(std::istreambuf_iterator<char>(helloWorldFile), (std::istreambuf_iterator<char>()));

	//cl::Program::Sources sources(1, std::make_pair(src.c_str(), src.length() + 1));
	cl::Program::Sources sources(1, std::make_pair(src.c_str(), strlen(src.c_str())));


	cl::Context context(REAL_GPU_device);
	cl::Program program(context, sources);

auto buildError = program.build("-cl-std=CL1.2");

char buf[16];
cl::Buffer memBuf(context, CL_MEM_WRITE_ONLY | CL_MEM_HOST_READ_ONLY, sizeof(buf));
cl::Kernel kernel(program, "HelloWorld", &buildError);

kernel.setArg(0, memBuf);


cl::CommandQueue queue(context, REAL_GPU_device);
queue.enqueueTask(kernel); //execute task

//read back in; bool blocking true means WAIT until done (pause execution)
//Read from global memory of device to memory on our side
queue.enqueueReadBuffer(memBuf, CL_TRUE, 0, sizeof(buf), buf);
    
std::cout << "\n\n\n" << buf;
std::cin.get();

return 0;
}

