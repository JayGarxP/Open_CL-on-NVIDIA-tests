// OpenCL_arrayProcessing.cpp : Defines the entry point for the console application.
// Youtube Wesley Shillingford Youtube [OpenCL 1.2 C++ Tutorials 7/9] array processing example.

#include "stdafx.h"
#include "OpenCLHelper.h"

int main()
{
	
	auto program  = CreateProgram("HelloWorld.cl");
	auto context = program.getInfo<CL_PROGRAM_CONTEXT>(); 
	auto devices = context.getInfo<CL_CONTEXT_DEVICES>();
	//Test if vendor is intel or nvidia
	/*
	// Range-based for loop to iterate through the array of platforms.  
	for (auto platform : platforms) {   
		auto test = platform.getInfo<CL_PLATFORM_NAME>();
		//if Intel, for all device(s) = intel
		//if Nvidia, for all Nvidia device(s) = nvidia device reference 
		
	}
	*/
	//'&' address reference to front device; //https://stackoverflow.com/questions/13230480/what-does-auto-tell-us
	auto& device = devices.front(); //prolly intel

char buf[16];
cl::Buffer memBuf(context, CL_MEM_WRITE_ONLY | CL_MEM_HOST_READ_ONLY, sizeof(buf));
cl::Kernel kernel(program, "HelloWorld");

kernel.setArg(0, memBuf);


//cl::CommandQueue queue(context, REAL_GPU_device);
cl::CommandQueue queue(context, device);
queue.enqueueTask(kernel); //execute task

//read back in; bool blocking true means WAIT until done (pause execution)
//Read from global memory of device to memory on our side
queue.enqueueReadBuffer(memBuf, CL_TRUE, 0, sizeof(buf), buf);
    
std::cout << "\n\n\n" << buf;
std::cin.get();

return 0;
}

