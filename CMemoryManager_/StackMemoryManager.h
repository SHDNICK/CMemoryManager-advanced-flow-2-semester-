#pragma once
#include <iostream>
#include "StackAllocator.h"
#include "IMemoryManager.h"

class StackMemoryManager : public IMemoryManager {
public:
	StackMemoryManager() = default;
	void* Alloc(std::size_t);
	void Free(void* ptr);
	~StackMemoryManager() {};
private:

	StackAllocator<uint8_t> _alloc;
};