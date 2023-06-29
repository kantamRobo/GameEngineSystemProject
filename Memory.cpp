#include "Memory.h"
#include <stdexcept>
#include <string>


void memory::Init(int in_max_size, int initialsize)
{
	buffer.maxsize = in_max_size;

	buffer.currentsize = initialsize;


}

int* memory::allocate(int size_to_add)
{
	if (buffer.currentsize + size_to_add < buffer.maxsize) {

		int  new_size = buffer.currentsize + size_to_add;


		buffer.currentsize = new_size;

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

void memory::deallocate(int size_to_remove)
{
	if (buffer.currentsize > 0)
	{
		
		allocator.deallocate(&buffer.currentsize,size_to_remove);
		buffer.currentsize -= size_to_remove;

	}

}
