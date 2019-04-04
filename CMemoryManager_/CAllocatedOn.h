#pragma once
#include <iostream>

template <typename Strategy>
class CAllocatedOn {
public:
	using _aloc = Strategy
	void* operator new(std::size_t size);
	void operator delete(void* ptr);
};

template <typename Strategy>
void* CAllocatedOn<Strategy>::operator new(std::size_t size) {
	return _aloc::Alloc(size);
}

template <typename Strategy>
void CAllocatedOn<Strategy>::operator delete(void* ptr) {
	return _aloc::Free(ptr);
}