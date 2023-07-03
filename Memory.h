#pragma once
#include <memory>
struct  LinearAllocator  {
	int maxsize;
	int currentsize;
	std::allocator<int> allocator; //Žb’è“I‚Éint‚É‚µ‚Ä‚¨‚­
	int* allocate(int new_size);

	void deallocate(int size_to_remove);

};
struct MallocAllocator {
	std::allocator<int> allocator;
	void* allocate(int size);

	

	void deallocate(int* pointer,int size_to_remove);
};
namespace memory {
	LinearAllocator buffer;
	
	void Init(int in_max_size,int initialsize);
	

	

}