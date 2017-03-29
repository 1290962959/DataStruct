#pragma once

/**********************************

Filename:		priorityqueue.h

Description:	����������ȼ�����ģ�壬�ṩ�û��ӿ�

Author:			hanbin

Time				17.03.23

***********************************/

#include <iostream>
#include <new>
#include <iterator>

#include "arraylist.h"
#include "tree.h"


template<class T>
class MaxPriorityQueue
{
public:
	virtual ~MaxPriorityQueue() { }
		//	Ϊ�շ���true
	virtual bool empty() const = 0;
		//�������ȼ�����Ԫ�ظ���
	virtual int size() const = 0;
		//�������ȼ�����Ԫ�ص�����
	virtual T& top() = 0;
		//ɾ�����ȼ����Ԫ��
	virtual void pop() = 0;
		//����Ԫ��theELement
	virtual void push(const T& theElement) = 0;
};



//�ô������ʵ��һ��������ȼ�����
template<class T>
class MaxHeap : public MaxPriorityQueue<T>
{
public:
	MaxHeap(int initicalCapacity = 10)
	{
		array_length_ = initicalCapacity;
		heap_ = new T[array_length_];
		heap_size_ = 0;
	}
	MaxHeap(const MaxHeap<T>& theHeap)
	{
		array_length_ = theHeap.array_length_;
		heap_ = new T[array_length_];
		heap_ = theHeap.heap_;
		heap_size_ = theHeap.heap_size_;
	}
	~MaxHeap() { }
		//��ʼ��һ���ǿմ����
	void initialize(T* theHeap, int theSize);
	bool empty() const { return heap_size_ == 0; }
	int size() const { return heap_size_; }
	T& top()
	{
		return heap_[1];
	}
	void pop();
	void push(const T& theElement);
private:
	T* heap_;
	int array_length_;
	int heap_size_;
};

template<class T>
void MaxHeap<T>::initialize(T* theHeap, int theSize)
{
	delete[] heap_;
	heap_ = theHeap;
	heap_size_ = theSize;

	for (int root = heap_size_ / 2; root >= 1; --root)
	{
		T rootElement = heap_[root];
		int child = 2 * root;
		while (child <= heap_size_)
		{
			if (child < heap_size_&&heap_[child] < heap_[child + 1])
				child++;
			if (rootElement >= heap_[child])
				break;
			heap_[child / 2] = heap_[child];
			child *= 2;
		}
		heap_[child / 2] = rootElement;
	}
}

template<class T>
void MaxHeap<T>::pop()
{
	if (heap_size_ == 0)
		throw "empty heap";
	heap_[1].~T();

	T lastElement = heap_[heap_size_--];

	int current_node = 1, child = 2;
	while (child <= heap_size_)
	{
		if (child < heap_size_&&heap_[child] < heap_[child + 1])
			child++;
		if (lastElement >= heap_[child])
			break;
		heap_[current_node] = heap_[child];
		current_node = child;
		child *= 2;
	}
	heap_[current_node] = lastElement;
}

template<class T>
void MaxHeap<T>::push(const T& theElement)
{
	if (heap_size_ == array_length_ - 1)
	{
		change_array_length<T>(heap_, array_length_, array_length_ * 2);
		array_length_ *= 2;
	}
	int current_node;
	current_node = heap_size_ + 1;
	
	while (current_node != 1 && theElement > heap_[current_node / 2])	//ʵ����heamp_[0]û�б�ʹ��
	{
		heap_[current_node] = heap_[current_node / 2];
		current_node /= 2;
	}
	heap_[current_node] = theElement;
}



/*
	��������ģ�壬�ṩ�ӿ�
*/
template<class T>
class MaxHBLT :  public LinkBinaryTree<std::pair<int,T> >,public MaxHBLT<T>
{
public:
	bool empty() const { return tree_size_ == 0; }
	int size() const { return tree_size_; }
	T& top()
	{
		if (empty())
			throw "empty";
		return root_->element_.second;
	}
	void pop();
	void push(const T& theElement);
	void initialize(T*, int);
	void meld(MaxHBLT<T>& theHblt)
	{
		meld(root_, theHblt.root_);
		tree_size_ += theHblt.tree_size_;
		theHblt.root_ = nullptr;
		theHblt.tree_size_ = 0;
	}
};

