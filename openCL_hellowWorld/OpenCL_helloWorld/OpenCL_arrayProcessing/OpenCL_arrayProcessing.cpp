// OpenCL_arrayProcessing.cpp : Defines the entry point for the console application.
// Youtube Wesley Shillingford Youtube [OpenCL 1.2 C++ Tutorials 7/9] array processing example.

#include "stdafx.h"
#include "OpenCLHelper.h"

int main()
{
	
	CreateProgram("HelloWorld.cl");

//char buf[16];
//cl::Buffer memBuf(context, CL_MEM_WRITE_ONLY | CL_MEM_HOST_READ_ONLY, sizeof(buf));
//cl::Kernel kernel(program, "HelloWorld", &buildError);
//
//kernel.setArg(0, memBuf);
//
//
//cl::CommandQueue queue(context, REAL_GPU_device);
//queue.enqueueTask(kernel); //execute task
//
////read back in; bool blocking true means WAIT until done (pause execution)
////Read from global memory of device to memory on our side
//queue.enqueueReadBuffer(memBuf, CL_TRUE, 0, sizeof(buf), buf);
//    
//std::cout << "\n\n\n" << buf;
std::cin.get();

return 0;
}

