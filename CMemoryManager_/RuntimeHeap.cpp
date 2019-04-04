#include <iostream>
#include "RuntimeHeap.h"

void* RuntimeHeap::Alloc(std::size_t size) {
	return malloc(size);
}

void RuntimeHeap::Free(void* ptr) {
	free(ptr);
}