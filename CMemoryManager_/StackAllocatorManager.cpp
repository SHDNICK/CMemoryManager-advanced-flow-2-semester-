#include <iostream>
#include "StackMemoryManager.h"

void* StackMemoryManager::Alloc(std::size_t size) {
	return (void*)_alloc.allocate(size);
}

void StackMemoryManager::Free(void* ptr) {
	_alloc.deallocate((uint8_t*)ptr, 1);
}