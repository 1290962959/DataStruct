#pragma once

#include <iostream>
#include <new>

template<class T>
class LinearList {
public:
	virtual ~LinearList() { };
			//当线性表为空时返回true
	virtual bool empty() const = 0;
			//返回线性表的元素个数
	virtual int size() const = 0;
			//返回索引为theIndex的元素
	virtual T& get(int theIndex) const = 0;
			//返回元素theElement第一次出现时的索引
	virtual int index_of(const T& theElement) const = 0;
			//删除索引为theIndex的元素
	virtual void erase(int theIndex) = 0;
			//把theElement插入到索引为theIndex的位置上
	virtual void insert(int theIndex, const T& theElement) = 0;
			//把线性表插入输出流
	virtual void output(ostream& out) const = 0;
};