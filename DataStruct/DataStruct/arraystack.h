#pragma once

#include <iostream>
#include <new>
#include <iterator>

#include "stack.h"
#include "arraylist.h"

template<class T>
class ArrayStack : public Stack<T>
{
public:
	ArrayStack(int initialCapicity = 10);
	~ArrayStack() { delete[] stack_; }

	bool empty() const { return stack_top_ == -1; }
	int size() const { return stack_top_ + 1; }
	T& top()
	{
		if (stack_top_ == -1)
			throw "stack empty!";
		return stack_[stack_top_];
	}
	void pop()
	{
		if (stack_top_ == -1)
			throw "stack empty!";
		stack_[stack_top_--].~T();
	}
	void push(const T& theElement);
	void output() const 
	{
		if (!empty())
		{
			for (int i = 0; i < size(); ++i)
				std::cout << stack_[i];
			std::cout << std::endl;
		}
	}
private:
	int stack_top_;
	int array_length_;
	T* stack_;
};

template<class T>
ArrayStack<T>::ArrayStack(int initialCapicity)
{
	if (initialCapicity < 1)
		throw "initialCapicity must be >0";
	array_length_ = initialCapicity;
	stack_ = new T[array_length_];
	stack_top_ = -1;
}

template <class T>
void ArrayStack<T>::push(const T& theElement)
{
	if (stack_top_ + 1 == array_length_)
	{
		change_array_length(stack_, array_length_, 2 * array_length_);
		array_length_ *= 2;
	}
	stack_[++stack_top_] = theElement;
}