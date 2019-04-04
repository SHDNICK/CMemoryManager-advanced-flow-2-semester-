#include "StandardMemoryManager.h"
#include "Instance.h"
#include <iostream>

using namespace Instance_;

void* StandardMemoryManager::Alloc(std::size_t size) {
	return malloc(size);
}

void StandardMemoryManager::Free(void* ptr) {
	free(ptr);
}