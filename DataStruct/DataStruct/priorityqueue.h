#pragma once

/**********************************

Filename:		priorityqueue.h

Description:	创建最大优先级队列模板，提供用户接口

Author:			hanbin

Time				17.03.23

***********************************/

#include <iostream>
#include <new>
#include <iterator>

template<class T>
class MaxPriorityQueue
{
public:
	virtual ~MaxPriorityQueue() { }
		//	为空返回true
	virtual bool empty() const = 0;
		//返回优先级队列元素个数
	virtual int size() const = 0;
		//返回优先级最大的元素的引用
	virtual T& top() = 0;
		//删除优先级最大元素
	virtual void pop() = 0;
		//插入元素theELement
	virtual void push(const T& theElement) = 0;
};

