#include "Memory.h"
#include <stdexcept>
#include <string>
#include "File.h"

void  memory::Init(int in_max_size, int initialsize)
{
	buffer.maxsize = in_max_size;

	buffer.currentsize = initialsize;


}

int* LinearAllocator::allocate(int size_to_add)
{
	if (currentsize + size_to_add < maxsize) {

		int  new_size = currentsize + size_to_add;


		currentsize = new_size;

		auto alloc = allocator.allocate(size_to_add);
	
		return alloc;
	}
	else
	{
		const std::string error ="memory over flow";
		throw std::runtime_error(error);
	}

	return nullptr;
}

void LinearAllocator::deallocate(int size_to_remove)
{
	if (currentsize > 0)
	{
		
		allocator.deallocate(&currentsize,size_to_remove);
		currentsize -= size_to_remove;

	}

}

void* MallocAllocator::allocate(int size)
{
	return allocator.allocate( size);
}

void MallocAllocator::deallocate(int* pointer, int size_to_remove)
{
	allocator.deallocate(pointer, size_to_remove);
}
