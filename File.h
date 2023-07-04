#pragma once
template <class T>
class File {
public:

	LinearAllocator<T> fileallocator;
	bool Open(const char* filepath);
	bool Close(const char* filepath);
	

	void ReserveFileBuffer(const char* file)
	{
		std::ifstream instance(file);
		fileallocator<std::ifstream>.allocate(instance);
	}
};