#pragma once
#include <iostream>

class RuntimeHeap {
public:
	static void* Alloc(std::size_t size);
	static void Free(void* ptr);
};