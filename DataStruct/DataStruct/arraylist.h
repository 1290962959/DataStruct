#pragma once
#include <new>
#include <iostream>
#include <sstream>
#include <iterator>
#include <Windows.h>//min()


#include "illegalParameterValue.h"

//ArrayList派生于LinearList
#include "linearlist.h"

//动态数组的实现
template<class T>
void change_array_length(T* a, int oldLength, int newLength)
{
	if (newLength < 0)
		throw illegalParameterValue("new length must be > 0");
	T* temp = new T[newLength];
	int number = min(oldLength, newLength);
	copy(a, a + number, temp);
	delete []a;
	a = temp;
}

template<class T>
class ArrayList : public LinearList<T> {
public:
			//构造函数、拷贝构造函数与析构函数

	ArrayList(int initialCapacity);
	ArrayList(const ArrayList<T>& anotherArrayList);
	~ArrayList() { delete[]element; }   //若花括号内为空则加分号，否则不加

	bool empty() const { return list_size == 0; }
	int size() const { return list_size; }
	T& get(int theIndex) const;
	int index_of(const T& theElement) const;
	void erase(int theIndex);
	void insert(int theIndex, const T& theElement);
	void output(ostream& out) const;

	int capacity() const { return array_length; }
protected:
			//若索引无效则抛出异常
	void check_index(int theIndex) const;

	T* element;
	int array_length;
	int list_size;
};

template<class T>
ArrayList<T>::ArrayList(int initialCapacity)
{
	if (initialCapacity < 1)
	{
	/*	ostringstream s;
		s << "Initial capacity = " << initialCapacity << "must be > 0 ";*/
		//throw illegalParameterValue(s.str());
		throw "initit capacity should >0";
	}
	array_length = initialCapacity;
	element = new T[array_length];
	list_size = 0;
}

template<class T>
ArrayList<T>::ArrayList(const ArrayList& anotherArrayList)
{
	array_length = anotherArrayList.array_length;
	list_size = anotherArrayList.list_size;
	element = new T[array_length];
	copy(anotherArrayList.element,anotherArrayList.element+list_size,element);
}

template<class T>
void ArrayList<T>::check_index(int theIndex) const
{
	if (theIndex < 0 || theIndex >= list_size)
	{
		/*ostringstream s;
		s << "index = " << theIndex << "size = " << list_size;*/
		//throw illegalParameterValue(s.str());
		throw "index illegal";
	}
}

template<class T>
T& ArrayList<T>::get(int theIndex) const
{
	check_index(theIndex);
	return element[theIndex];
}

template<class T>
int ArrayList<T>::index_of(const T& theElement) const
{
	int theIndex = (int)(find(element, element + list_size, theElement) - element);//若果没找到  theIndex的值是等于list_size

	if (theIndex == list_size)
		return -1;
	else
		return theIndex;
}


template<class T>
void ArrayList<T>::erase(int theIndex)
{
	check_index(theIndex);

	copy(element + theIndex + 1, element + list_size, element + theIndex);

	element[--list_size].~T(); //这里是第一次使用这样的析构函数
	
	//以下方法应该也可以实现

	/************************
	T* p=&element[--list_size];
	delete p;
	*************************/
}

template<class T>
void ArrayList<T>::insert(int theIndex, const T& theElement)
{
	if (theIndex<0 || theIndex>list_size)
	{
		ostringstream s;
		s << "index = " << theIndex << "size = " << theElement;
		//throw illegalParameterValue(s.str());
		throw "index error";
	}

	if (list_size == array_length)
	{
		change_array_length<T>(element, array_length, array_length * 2);
		array_length *= 2;
	}
	//元素向右移一位
	copy_backward(element+theIndex,element+list_size,element+list_size+1);

	element[theIndex] = theElement;
	++list_size;
}

template<class T>
void ArrayList<T>::output(ostream& out) const
{
	copy(element, element+list_size, ostream_iterator<T>(cout, " "));
	out << std::endl;
}