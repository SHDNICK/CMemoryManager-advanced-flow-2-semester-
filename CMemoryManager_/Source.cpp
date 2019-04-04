#include <iostream>
#include <vector>
#include "CMemoryManagerSwitcher.h"
#include "StandardMemoryManager.h"
#include "StackMemoryManager.h"

using namespace std;

template <typename T>
T* make(Instance *v) {
	CMemoryManagerSwitcher Switcher = CMemoryManagerSwitcher(v);
	return new T();
}


static std::vector<int> statVector{ 1, 2, 3, 4, 5 };

int main() {
	StackMemoryManager stackManager;
	StackMemoryManager* ptr = &stackManager;
	Instance t1(ptr);

	CMemoryManagerSwitcher Switcher(&t1);

	/*long double *x = new long double;
	*x = 5;
	char *y = new char;
	cout << *x;
	delete x;
	cout << x;*/
	system("pause");
}