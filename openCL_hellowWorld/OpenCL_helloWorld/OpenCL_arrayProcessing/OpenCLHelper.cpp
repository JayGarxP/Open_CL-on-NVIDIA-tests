
#include "stdafx.h"
#include "OpenCLHelper.h"

cl::Program CreateProgram(const std::string &file)
{
	std::vector<cl::Platform> platforms;
	std::vector<cl::Device> devices;
	std::vector<cl::Device> nvidia_devices;
	cl::Platform::get(&platforms);

	_ASSERT(platforms.size() > 0);

	// Range-based for loop to iterate through the array of platforms.  
	for (auto platform : platforms) {   
		auto test = platform.getInfo<CL_PLATFORM_NAME>();
		
		
	}
		
	

	std::ifstream helloWorldFile("HelloWorld.cl");

	std::string src(std::istreambuf_iterator<char>(helloWorldFile), (std::istreambuf_iterator<char>()));

	//cl::Program::Sources sources(1, std::make_pair(src.c_str(), src.length() + 1));
	cl::Program::Sources sources(1, std::make_pair(src.c_str(), strlen(src.c_str())));


	//cl::Context context(REAL_GPU_device);
	//cl::Program program(context, sources);

	//auto buildError = program.build("-cl-std=CL1.2");
	cl::Program emptyProgram(NULL, sources);
	return emptyProgram;
}