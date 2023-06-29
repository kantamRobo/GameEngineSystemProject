#pragma once
#include <memory>
struct Buffer {
	int maxsize;
	int currentsize;

};
namespace memory {
	Buffer buffer;
	std::allocator<int> allocator; //暫定的にintにしておく
	void Init(int in_max_size,int initialsize);
	int* allocate(int new_size);

	void deallocate(int size_to_remove);
	

	

}