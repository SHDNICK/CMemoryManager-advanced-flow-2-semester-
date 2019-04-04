#pragma once
#include "StandardMemoryManager.h"

namespace Instance_ {
	class Instance {
	private:
		IMemoryManager* _current;
	public:
		Instance(IMemoryManager* newManager = new(malloc(sizeof(StandardMemoryManager))) StandardMemoryManager());
		~Instance() {};

		void* Alloc(std::size_t size);
		void Free(void* ptr);
	};

	class Block {
	public:
		static const size_t alignment;
	};
}