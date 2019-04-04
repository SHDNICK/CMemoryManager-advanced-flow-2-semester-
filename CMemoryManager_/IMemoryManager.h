#pragma once
#include <iostream>

class IMemoryManager {
public:
	virtual void* Alloc(std::size_t size) = 0;
	virtual void Free(void* ptr) = 0;
	~IMemoryManager() = default;
};