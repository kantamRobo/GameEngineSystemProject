#pragma once
#include <memory>
#include <vector>
template  <class T>
struct  LinearAllocator  {
	
	std::vector<T> allocator; //Žb’è“I‚Éint‚É‚µ‚Ä‚¨‚­
	void allocate(T& newinstance)
	{
		
			allocator.push_back(newinstance);
		
	}

	void deallocate(T& instance)
	{
		
		for(auto i=0;i<allocator.size()i++){
		if(allocator[i]==instance)
			allocator.erase(instance);
		}
		else
		{
			throw std::runtime_error("Instance‚Í‘¶Ý‚µ‚Ü‚¹‚ñ");
		}



	}

};
struct MallocAllocator {
	std::allocator<int> allocator;
	void* allocate(int size);

	

	void deallocate(int* pointer,int size_to_remove);
};
template <class T>
struct memory {
	
	
	
	void Init(int in_max_size,int initialsize);
	


	

}