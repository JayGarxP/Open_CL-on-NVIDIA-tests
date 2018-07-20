to get OpenCL on Nvidia working first:    

Download openCL sdk (2012 standalone mirror from the net) OR as part of the latest CUDA toolkit (2013+)    


Now change your project properties to connect up the .DLL and .lib that OpenCL needs  

Config->C/C++->General: Additional Include Directories    
Put the OpenCL include file parent folder here, like 
> C:\Program Files\NVIDIA GPU Computing Toolkit\CUDA\v9.2\include

Config->Linker->General: Additional Library Directories    
Put the OpenCL library parent folder here, like
> C:\Program Files\NVIDIA GPU Computing Toolkit\CUDA\v9.2\lib\x64
  
Config->Linker->Input: Additional Dependencies
Type in
> OpenCL.lib

(make sure you're targeting x64 platform in configuration manager)



Github Desktop (new 2018 version) cannot diff if file encodings are different! You will see 'binary file changed' instead of a useful diff.
Make sure to File->Save As    
then click the tiny hidden arrow next to save to access the 'Encoding' menu,
save and replace your file as UTF-8 to get diffs working again.
