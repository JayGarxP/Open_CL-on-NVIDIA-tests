
#include "stdafx.h"
#include "OpenCLHelper.h"

cl::Program CreateProgram(const std::string &file)
{
	std::vector<cl::Platform> platforms;
	std::vector<cl::Device> devices;
	std::vector<cl::Device> nvidia_devices;
	cl::Platform::get(&platforms);

	_ASSERT(platforms.size() > 0);

	std::string INTEL_PLATFORM_NAME("Intel(R) OpenCL");
	// char word[] = "Intel(R) OpenCL"; basic_string<allocator> not playing nicely with \0 null character
	// basic_string.compare(PLATFORM) == 0 also not working, makes no sense, can't find info about this
	std::string NVIDIA_PLATFORM_NAME("NVIDIA CUDA");
	// Range-based for loop to iterate through the array of platforms.  
	for (auto platform : platforms) {   
		auto test = platform.getInfo<CL_PLATFORM_NAME>();

		//if Intel, for all device(s) = intel "Intel(R) OpenCL" 
		if (test[0] == INTEL_PLATFORM_NAME[0]) 
		{
			std::cout << "INTEL HIT\n";
			//save cpu device here if you want to in future
		}
		else if (test[0] == NVIDIA_PLATFORM_NAME[0]) 
		{
			std::cout << "NVIDIA GPU HiiT\n";

			platform.getDevices(CL_DEVICE_TYPE_GPU, &nvidia_devices);
		}
		else { std::cout << "BZZZT! No intel or nvidia devices found on any platforms"; }
		//if Nvidia, for all Nvidia device(s) = nvidia device reference "Intel(R) OpenCL" "NVIDIA CUDA"
		
	}
		
	
	std::ifstream helloWorldFile("HelloWorld.cl");

	std::string src(std::istreambuf_iterator<char>(helloWorldFile), (std::istreambuf_iterator<char>()));

	//cl::Program::Sources sources(1, std::make_pair(src.c_str(), src.length() + 1));
	cl::Program::Sources sources(1, std::make_pair(src.c_str(), strlen(src.c_str())));


	auto REAL_GPU_device = nvidia_devices.front();
	cl::Context context(REAL_GPU_device);
	cl::Program program(context, sources);

	auto buildError = program.build("-cl-std=CL1.2");
	//cl::Program emptyProgram(NULL, sources);
	//return emptyProgram;
	return program;
}