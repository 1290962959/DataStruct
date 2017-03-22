#pragma once

#include <iostream>
#include <new>
#include <iterator>

template<class T>
struct BinaryTreeNode
{
	T element_;
	BinaryTreeNode<T>* left_child_,				//左子树
									right_child_;			//右子树

		//构造函数    赋值运算符需要在T类型中重载吗?
	BinaryTreeNode() { left_child_ = right_child_ = nullptr; }
	BinaryTreeNode(const T& theElement) : element_{ theElement } { left_child_ = right_child_ = nullptr; }
	BinaryTreeNode(const T& theElement, BinaryTreeNode<T>* theLeftChild, BinaryTreeNode<T>* theRightChild)
	{
		element_{ theElement };	//在这里直接赋值？ 这里不加;没问题吗？
		left_child_ = theLeftChild;
		right_child_ = theRightChild;
	}
};

