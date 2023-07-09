#include "Memory.h"
#include <stdexcept>
#include <string>
#include "File.h"

void  memory::Init(int in_max_size, int initialsize)
{
	buffer.maxsize = in_max_size;

	buffer.currentsize = initialsize;


}


void* MallocAllocator::allocate(int size)
{
	return allocator.allocate( size);
}

void MallocAllocator::deallocate(int* pointer, int size_to_remove)
{
	allocator.deallocate(pointer, size_to_remove);
}
