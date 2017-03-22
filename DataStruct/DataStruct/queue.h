#pragma once
#include <iostream>
#include <new>
#include <iterator>

#include "arraylist.h"

template<class T>
class Queue
{
public:
		//析构函数
	virtual ~Queue() {}
		//若队列为空，返回true
	virtual bool empty() const = 0;
		//返回队列的元素个数
	virtual int size() const = 0;
		//返回头元素的引用
	virtual T& front() = 0;
		//返回尾元素的引用
	virtual T& back() = 0;
		//删除首元素
	virtual void pop() = 0;
		//将元素theElement加入队尾
	virtual void push(const T& theElement) = 0;

};

//基于数组的循环队列的实现方法
template<class T>
class ArrayQueue : public Queue<T>
{
	friend ostream& operator<<(ostream& out, const ArrayQueue<T>& theArrayQueue);
public:
	ArrayQueue(int initialCapacity = 10);
	ArrayQueue(const ArrayQueue<T>& theArrayQueue);
	~ArrayQueue() { delete queue_; }

	bool empty() const { return queue_front_ == queue_back_; }
	int size() const;
	T& front() 
	{ 
		if (empty())
			throw "no element";
		else
			return queue_[(queue_front_+1)%array_length_];
	}
	T& back() 
	{
		if (empty())
			throw "no element";
		else
			return queue_[queue_back_];
	}
	void pop();
	void push(const T& theElement);

	void output()
	{
		for (int i = 0; i < size(); ++i)
		{
			std::cout << queue_[(queue_front_ +1+ i) % array_length_] << std::endl;
		}
	}

private:
	int queue_front_;
	int queue_back_;
	T* queue_;
	int array_length_;
};

template<class T>
ostream& operator<<(ostream& out, const ArrayQueue<T>& theArrayQueue)
{
	out << theArrayQueue.queue_[(theArrayQueue.queue_front_+ 1) % theArrayQueue.array_length_];
	return out;
}

template<class T>
ArrayQueue<T>::ArrayQueue(int initialCapacity)
{
	if (initialCapacity < 1)
		throw "initial capacity must be>0";
	queue_front_ = queue_back_ = 0;
	array_length_ = initialCapacity;
	queue_ = new T[array_length_];
}

template<class T>
ArrayQueue<T>::ArrayQueue(const ArrayQueue<T>& theArrayQueue)
{
	queue_front_ = theArrayQueue.queue_front_;
	queue_back_ = theArrayQueue.queue_back_;
	array_length_ = theArrayQueue.array_length_;
	queue_ = new T[array_length_];
	copy(theArrayQueue.queue_, theArrayQueuequeue_ + array_length_, queue_);
}

template<class T>
int ArrayQueue<T>::size() const
{
	if (queue_front_ < queue_back_)
		return (queue_back_ - queue_front_) % array_length_;
	if (queue_front_ == queue_back_)
		return 0;
	return array_length_ - (queue_back_ - queue_front_) % array_length_;
}

template<class T>
void ArrayQueue<T>::push(const T& theElement)
{
	if ((queue_back_ + 1) % array_length_ == queue_front_)
		change_array_length(queue_, array_length_, array_length_ * 2);
	queue_back_ = (queue_back_ + 1) % array_length_;
	queue_[queue_back_] = theElement;
}

template<class T>
void ArrayQueue<T>::pop()
{
	if (queue_front_ == queue_back_)
		throw "empty";
	queue_front_ = (queue_front_ + 1) % array_length_;
	queue_[queue_front_].~T();
}