#pragma once
#include <iostream>
#include "IMemoryManager.h"

class StandardMemoryManager : public IMemoryManager {
public:
	StandardMemoryManager() = default;
	void* Alloc(std::size_t size);
	void Free(void* ptr);
	~StandardMemoryManager() = default;
};