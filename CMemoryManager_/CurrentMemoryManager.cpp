#include <iostream>
#include "CurrentMemoryManager.h"
#include "CMemoryManagerSwitcher.h"

void* CurrentMemoryManager::Alloc(std::size_t size) {
	return CMemoryManagerSwitcher::get()->Alloc(size);
}

void CurrentMemoryManager::Free(void* ptr) {
	CMemoryManagerSwitcher::get()->Free(ptr);
}