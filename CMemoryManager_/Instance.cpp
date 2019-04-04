#include <iostream>
#include <algorithm>
#include "Instance.h"

const size_t Instance_::Block::alignment = std::max(sizeof(IMemoryManager**), alignof(std::max_align_t));

Instance_::Instance::Instance(IMemoryManager* newManager) {
	_current = newManager;
}

void* Instance_::Instance::Alloc(std::size_t size) {
	uint8_t* mem = static_cast<uint8_t*>(_current->Alloc(size + Instance_::Block::alignment));
	new(mem) IMemoryManager*(_current);
	return mem + Instance_::Block::alignment;
}

void Instance_::Instance::Free(void* ptr) {
	IMemoryManager** cur = reinterpret_cast<IMemoryManager**>(static_cast<uint8_t*>(ptr) - Instance_::Block::alignment);
	(*cur)->Free(static_cast<void*>(cur));
}

