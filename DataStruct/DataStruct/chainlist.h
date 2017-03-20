#pragma once
#include <iostream>
#include <new>
#include <Windows.h>
#include <iterator>

#include "linearlist.h"


//表示链表的一个节点，包含数据域与指针域
template <class T>
struct ChainNode
{
	//数据成员
	T element_;

	//指向下一节点的指针
	ChainNode<T>* next_;

	//方法
	ChainNode() { }
	ChainNode(const T& theElement) { this->element_ = theElement; }
	ChainNode(const T& theElement, ChainNode<T>* theNext)
	{
		this->element_ = theElement;
		this->next_ = theNext;
	}
};

template <class T>
class ChainList : public LinearList<T> 
{
public:
	//ChainList() { }
	ChainList(int initialCapacity=10);//一般给个默认的值 这样的话一方面减少了不确定性，一方面省去了无参数的构造函数
	ChainList(const ChainList<T>& theChain);
	~ChainList();

	bool empty() const { return list_size_==0; }
	int size() const { return list_size_; }
	T& get(int theIndex) const;
	int index_of(const T& theElement) const;
	void erase(int theIndex);
	void insert(int theIndex,const T& theElement);
	void output(ostream& out) const;

protected:
	void check_index(int theIndex) const;

	ChainNode<T>* first_node_;
	int list_size_;
};

template <class T>
ChainList<T>::ChainList(int initialCapacity)
{
	if (initialCapacity < 1)
		throw "initial capacity should be more than 1";
	first_node_ = nullptr;
	list_size_ = 0;
}

template <class T>
ChainList<T>::ChainList(const ChainList<T>& theChain)
{
	list_size_ = theChain.list_size_;

	if (list_size_ == 0)
	{
		first_node_ = nullptr;
		return;
	}

	//深拷贝
	ChainNode<T>* sourceNode = theChain.first_node_;
	first_node_ = new ChainNode<T>(sourceNode->element_);
	sourceNode = sourceNode->next_;
	ChainNode<T>* targetNode = first_node_;
	while (sourceNode != nullptr)
	{
		targetNode->next_ = new ChainNode<T>(sourceNode->element_);
		sourceNode = sourceNode->next_;
		targetNode = targetNode->next_;
	}
	targetNode->next_ = nullptr;
}

template <class T>
ChainList<T>::~ChainList()
{
	while (first_node_ != nullptr)
	{
		ChainNode<T>* nextNode = first_node_->next_;
		//这样行不行
		/*
		ChainNode<T>* nextNode=nullptr;
		nextNode=first_node_->next_;
		*/
		delete first_node_;
		first_node_ = nextNode;
	}
}

template<class T>
void ChainList<T>::check_index(int theIndex) const
{
	if (theIndex<0 || theIndex>=list_size_)
		throw "index error!";
}

template<class T>
T& ChainList<T>::get(int theIndex) const
{
	check_index(theIndex);

	ChainNode<T>* currentNode = first_node_;
	for (int i = 0; i < theIndex; ++i)
	{
		currentNode = currentNode->next_;
	}
	return currentNode->element_;
}

template<class T>
int ChainList<T>::index_of(const T& theElement) const
{
	ChainNode<T>* currentNode = first_node_;
	int index = 0;
	while (currentNode != nullptr&&currentNode->element_ != theElement)
	{
		currentNode = currentNode->next_;
		++index;
	}

	if (currentNode == nullptr)
		return -1;
	else
		return index;
}

template<class T>
void ChainList<T>::erase(int theIndex)
{
	check_index(theIndex);

	ChainNode<T>* deleteNode = nullptr;
	if (theIndex == 0)
	{
		deleteNode = first_node_;
		first_node_ = first_node_->next_;
	}
	else
	{
		//取到前驱节点，如果取到本身的节点的话，delete了就不存在这个节点了 ，无法进行链接操作
		ChainNode<T>* currentNode = first_node_;
		for (int i = 0; i < theIndex-1; ++i)
			currentNode = currentNode->next_;
		deleteNode = currentNode->next_;
		currentNode->next_ = currentNode->next_->next_;
	}

	--list_size_;
	delete deleteNode;
}

template<class T>
void ChainList<T>::insert(int theIndex, const T& theElement)
{
	if (theIndex<0 || theIndex>list_size_)
		throw "insert index error!";
	if (theIndex == 0)
		first_node_ = new ChainNode<T>(theElement, first_node_);
	else
	{
		ChainNode<T>* currentNode = first_node_;
		for (int i = 0; i < theIndex - 1; ++i)
			currentNode = currentNode->next_;
		currentNode->next_ = new ChainNode<T>(theElement, currentNode->next_);
	}
	++list_size_;
}

template<class T>
void ChainList<T>::output(ostream& out) const
{
	for (ChainNode<T>* currentNode = first_node_; currentNode != nullptr; currentNode = currentNode->next_)
		out << currentNode->element_ << " ";
}

template<class T>
ostream& operator<<(ostream& out, const ChainList<T>& x)
{
	x.output(out);
	return out;
}