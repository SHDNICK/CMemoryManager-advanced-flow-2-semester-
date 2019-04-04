#include <iostream>
#include "CMemoryManagerSwitcher.h"


Instance_List* CMemoryManagerSwitcher::list_ = new(malloc(sizeof(Instance_List*))) Instance_List(new(malloc(sizeof(Instance*))) Instance());

void Instance_List::push_back(Instance* rep) {
	size++;
	prev = cur;
	cur = rep;
}

void Instance_List::pop_back() {
	//size--;
	cur = prev;
}

Instance* CMemoryManagerSwitcher::get() {
	if (list_ == nullptr) {
		Instance* First = new(malloc(sizeof(Instance*))) Instance();
		CMemoryManagerSwitcher* standard = new(malloc(sizeof(CMemoryManagerSwitcher*))) CMemoryManagerSwitcher(First);
		return list_->get();
	}
	return list_->get();
}

CMemoryManagerSwitcher::~CMemoryManagerSwitcher() {
	list_->pop_back();
}

void* operator new(std::size_t size) {
	return CMemoryManagerSwitcher::get()->Alloc(size);
}

void operator delete(void* ptr){
	return CMemoryManagerSwitcher::get()->Free(ptr);
}




void* operator new(std::size_t size, const std::nothrow_t&) noexcept {
	void* p = nullptr;
	try {
		p = ::operator new(size);
	}
	catch (...) {}
	return p;
}

void* operator new[](std::size_t size) noexcept(false) {
	return ::operator new(size);
}

void* operator new[](std::size_t size, const std::nothrow_t&) noexcept {
	void* p = nullptr;
	try {
		p = ::operator new[](size);
	}
	catch (...) {}
	return p;
}

void operator delete(void* ptr, const std::nothrow_t&) noexcept {
	::operator delete(ptr);
}

void operator delete(void* ptr, std::size_t) noexcept {
	::operator delete(ptr);
}

void operator delete[](void* ptr) noexcept {
	::operator delete(ptr);
}

void operator delete[](void* ptr, const std::nothrow_t&) noexcept {
	::operator delete[](ptr);
}

void operator delete[](void* ptr, std::size_t) noexcept {
	::operator delete[](ptr);
}