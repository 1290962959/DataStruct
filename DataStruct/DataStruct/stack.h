#pragma once

template<class  T>
class Stack
{
public:
	virtual ~Stack() { }
		//��ջΪ��ʱ���� true
	virtual bool empty() const = 0;
		//����ջ��Ԫ�ظ���
	virtual int size() const = 0;
		//����ջ��Ԫ�ص�����
	virtual T& top() = 0;
		//����ջ��Ԫ��
	virtual void pop() = 0;
		//��Ԫ��theElementѹ��ջ
	virtual void push(const T& theElement) = 0;
};

