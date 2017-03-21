#pragma once

#include <iostream>
#include <new>
#include <iterator>

#include "stack.h"
#include "chainlist.h"

template<class T>
class LinkStack : public Stack<T>
{
public://在class中如果不指定public的属性，会被默认设置为private
	LinkStack(int initialCapacity = 10)
	{
		stack_top_ = nullptr;
		stack_size_ = 0;
	}
	~LinkStack()
	{
		while (stack_top_ != nullptr)
		{
			ChainNode<T>* nextNode = stack_top_->next_;
			delete stack_top_;
			stack_top_ = nextNode;
		}
	}

	bool empty() const { return stack_size_ == 0; }
	int size() const { return stack_size_; }
	T& top()
	{
		if (stack_size_ == 0)
			throw "stack empty";
		return stack_top_->element_;
	}
	void pop()
	{
		if (stack_size_ == 0)
			throw "stack empty";
		ChainNode<T>* nextNode = stack_top_->next_;
		delete stack_top_;
		stack_top_ = nextNode;
		--stack_size_;
	}
	void push(const T& theElement)
	{
		stack_top_ = new ChainNode<T>(theElement, stack_top_);
		stack_size_++;
	}

private:
	ChainNode<T>* stack_top_;
	int stack_size_;
};