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

