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

void* StackAllocator::Allocate(size_t size, size_t alignment)
{
	const size_t newstart = memory_align(allocated_size, alignment);

	const size_t new_allocated_size = newstart + size;
	if (new_allocated_size > total_size)
	{
		throw std::runtime_error("Overflow");
		return nullptr;
	}

	allocated_size = new_allocated_size;
	return nullptr;
}

void StackAllocator::Deallocate(void* pointer)
{
	if (pointer < memory + total_size)
	{
		throw std::runtime_error("out of bound");
	}
	if (pointer < memory + allocated_size)
	{
		throw std::runtime_error("out of bound");
	}

	const size_t size_at_pointer= (uint8_t*)pointer - memory;

	allocated_size = size_at_pointer;
}