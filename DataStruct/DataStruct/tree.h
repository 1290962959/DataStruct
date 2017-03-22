#pragma once

#include <iostream>
#include <new>
#include <iterator>

template<class T>
struct BinaryTreeNode
{
	T element_;
	BinaryTreeNode<T>* left_child_,				//������
									right_child_;			//������

		//���캯��    ��ֵ�������Ҫ��T������������?
	BinaryTreeNode() { left_child_ = right_child_ = nullptr; }
	BinaryTreeNode(const T& theElement) : element_{ theElement } { left_child_ = right_child_ = nullptr; }
	BinaryTreeNode(const T& theElement, BinaryTreeNode<T>* theLeftChild, BinaryTreeNode<T>* theRightChild)
	{
		element_{ theElement };	//������ֱ�Ӹ�ֵ�� ���ﲻ��;û������
		left_child_ = theLeftChild;
		right_child_ = theRightChild;
	}
};

