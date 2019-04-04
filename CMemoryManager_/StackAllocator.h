#pragma once
#include <iostream>
#include <cstdint>
#include <memory>

const int BlockSize = 1e7;

class memoryBlock {

public:
	typedef std::size_t size_type;
	typedef uint8_t* ptr;

	memoryBlock* previousBlock;
	size_type offsetBlock;
	char* buffer;


	memoryBlock() :
		previousBlock(nullptr), buffer(nullptr), offsetBlock(0) {};
	~memoryBlock() = default;

};


template < class T >
class StackAllocator {

public:
	memoryBlock* finishBlocks;

	typedef T value_type;
	typedef T* pointer;
	typedef const T* const_pointer;
	typedef T& reference;
	typedef const T& const_reference;
	typedef std::size_t size_type;
	typedef std::ptrdiff_t difference_type;
	typedef uint8_t* ptr;
	typedef uint8_t var;
	typedef int count_type;

	template < class U >
	struct rebind {
		typedef StackAllocator<U> other;
	};

	StackAllocator() :
		finishBlocks(nullptr) {};

	template < class U >
	StackAllocator(const StackAllocator<U>& other) :
		finishBlocks(other.finishBlocks) {};

	char* allocate(size_type n);
	void deallocate(pointer p, size_type n);

	~StackAllocator() = default;
};

template < class T >
char* StackAllocator<T>::allocate(size_type n) {

	count_type cnt_byte = n * sizeof(value_type);

	if (finishBlocks == nullptr) {
		memoryBlock* newBlock = reinterpret_cast<memoryBlock*>(malloc(sizeof(memoryBlock)));
		newBlock->buffer = reinterpret_cast<char*>(malloc(BlockSize));
		finishBlocks = newBlock;
		finishBlocks->offsetBlock = cnt_byte;
		return reinterpret_cast<char*>(finishBlocks->buffer);
	}

	count_type temp = BlockSize - finishBlocks->offsetBlock;

	if (cnt_byte > temp) {
		memoryBlock* newBlock = reinterpret_cast<memoryBlock*>(malloc(sizeof(memoryBlock)));
		newBlock->buffer = reinterpret_cast<char*>( malloc(BlockSize));
		newBlock->previousBlock = finishBlocks;
		newBlock->offsetBlock = cnt_byte;
		finishBlocks = newBlock;
		finishBlocks->previousBlock->offsetBlock = BlockSize;
		return reinterpret_cast<char*> (finishBlocks->buffer);
	}

	count_type begin = finishBlocks->offsetBlock;
	finishBlocks->offsetBlock += cnt_byte;
	return reinterpret_cast<char*>(finishBlocks->buffer + begin);
};

template < class T >
void StackAllocator<T>::deallocate(pointer p, size_type n) {}
