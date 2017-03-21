#pragma once

template<class  T>
class Stack
{
public:
	virtual ~Stack() { }
		//当栈为空时返回 true
	virtual bool empty() const = 0;
		//返回栈中元素个数
	virtual int size() const = 0;
		//返回栈顶元素的引用
	virtual T& top() = 0;
		//弹出栈顶元素
	virtual void pop() = 0;
		//将元素theElement压入栈
	virtual void push(const T& theElement) = 0;
};

