#pragma once
#include <iostream>
#include "Instance.h"

using namespace Instance_;

	class Instance_List {
	private:
		Instance* cur;
		Instance* prev;
	public:
		std::size_t size;
		Instance_List(Instance* rep) : prev(nullptr), cur(rep) {};
		void push_back(Instance* rep);
		void pop_back();

		Instance* get() { return cur; }
	};

	class CMemoryManagerSwitcher {
	public:
		Instance* cur;
		static Instance_List* list_;

		CMemoryManagerSwitcher(Instance* rep) {
			//if (list_ == nullptr)
				//list_ = new(malloc(sizeof(Instance_List*))) Instance_List(rep);
			//else {
				list_->push_back(rep);
			//}
			//list_->push_back(rep);
			cur = rep;
		}
		~CMemoryManagerSwitcher();

		static Instance* get();
	};


