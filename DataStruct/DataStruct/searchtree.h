#pragma once

#include "dictionary.h"
#include "tree.h"
using namespace std;

template<class K, class E>
class bsTree : public dictionary<K, E>
{
public:
	virtual void ascend() = 0;
	// output in ascending order of key
};

template<class K,class E>
class BinarySearchTree : public bsTree<K, E>,public LinkBinaryTree<pair<const K, E> >
{
public:
	bool empty() const { return tree_size_ == 0; }
	int size() const { return tree_size_; }
	pair<const K, E>* find(const K& theKey) const;
	void erase(const K& theKey);
	void insert(const pair<const K, E>& thePair);

	void ascend() { in_order_output(); }
};

template<class K,class E>
pair<const K, E>* BinarySearchTree<K, E>::find(const K& theKey) const
{
	BinaryTreeNode<pair<const K, E> >* p = root_;
	while (p != nullptr)
		if (theKey < p->element_.first)
			p = p->left_child_;
		else
			if (theKey > p->element_.first)
				p = p->right_child_;
			else
				return &p->element_;
	return nullptr;
}
template<class K,class E>
void BinarySearchTree<K, E>::erase(const K& theKey)
{
	BinaryTreeNode<pair<const K, E>>* p = root_, *pp = nullptr;
	while (p != nullptr&&p->element_.first != theKey)
	{
		pp = p;
		if (p->element_.first > theKey)
			p = p->left_child_;
		else
			p = p->right_child_;
	}
	if (p == nullptr)
		return;
	if (p->left_child_ != nullptr&&p->right_child_ != nullptr)
	{
		BinaryTreeNode<pair<const K, E>>* s = p->left_child_, *ps = p;
		while (s->right_child_ != nullptr)
		{
			ps = s;	//最大关键值的父节点
			s = s->right_child_;	//最大关键值
		}
		BinaryTreeNode<pair<const K, E>>* q = new BinaryTreeNode<pair<const K, E>>(s->element_, p->left_child_, p->right_child_);
		if (pp == nullptr)//父节点为空
			root_ = q;
		else if (p == pp->left_child_)
			pp->left_child_ = q;
		else
			pp->right_child_ = q;
		if (ps == p) pp = q;
		else pp = ps;
		delete p;
		p = s;
	}
	BinaryTreeNode<pair<const K, E>>* c;
	if (p->left_child_ != nullptr)
		c = p->left_child_;
	else
		c = p->right_child_;
	if (p == root_)
		root_ = c;
	else
	{
		if (p == pp->left_child_)
			pp->left_child_ = c;
		else
			pp->right_child_ = c;
	}
	--tree_size_;
	delete p;
}
template<class K,class E>
void BinarySearchTree<K, E>::insert(const pair<const K, E>& thePair)
{
	BinaryTreeNode<pair<const K, E>>* p = root_, *pp = nullptr;
	while (p != nullptr)
	{
		pp = p;
		if (p->element_.first > thePair.first)
			p = p->left_child_;
		else
			if (p->element_.first < thePair.first)
				p = p->right_child_;
			else
			{
				p->element_.second = thePair.second;
				return;
			}
	}
	BinaryTreeNode<pair<const K, E>>* newnode = new BinaryTreeNode<pair<const K, E>>(thePair);
	if (root_ != nullptr)
		if (thePair.first < pp->element_.first)
			pp->left_child_ = newnode;
		else
			pp->right_child_ = newnode;
	else
		root_ = newnode;
	++tree_size_;
}