#pragma once
#include <memory>
struct Buffer {
	int maxsize;
	int currentsize;

};
namespace memory {
	Buffer buffer;
	std::allocator<int> allocator; //�b��I��int�ɂ��Ă���
	void Init(int in_max_size,int initialsize);
	int* allocate(int new_size);

	void deallocate(int size_to_remove);
	

	

}