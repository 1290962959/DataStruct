#pragma once

/****************************
	Filename: tree.h

	Description:ģ�������ṩ�ӿ��Լ������ķ�����

	Author: hanbin

	Time: 17.03.23
******************************/



#include <iostream>
#include <new>
#include <iterator>
#include <stack>


#include "queue.h"



template<class T>
struct BinaryTreeNode
{
	T element_;
	BinaryTreeNode<T>* left_child_;			//������
	BinaryTreeNode<T>*	right_child_;			//������

		//���캯��    ��ֵ�������Ҫ��T������������?
	BinaryTreeNode() { left_child_ = right_child_ = nullptr; }
	BinaryTreeNode(const T& theElement) { element_ = theElement; left_child_ = right_child_ = nullptr; }
	BinaryTreeNode(const T& theElement, BinaryTreeNode<T>* theLeftChild, BinaryTreeNode<T>* theRightChild)
	{
		element_=theElement;	//������ֱ�Ӹ�ֵ�� ���ﲻ��;û������
		left_child_ = theLeftChild;
		right_child_ = theRightChild;
	}
};

template<class T>
class BinaryTree
{
public:
	virtual ~BinaryTree() { }
		//��Ϊ�շ���true
	virtual bool empty() const = 0;
		//��������Ԫ�ظ���
	virtual int size() const = 0;
		//�������
	virtual void pre_order(void(*) (T*)) = 0;		//void* ����ָ���κ����ݵ�Ԫ,������ void(*)(T*)ָ���Ƿ���ֵΪvoid ��������T*�ĺ���
		//�������
	virtual void in_order(void(*)(T*)) = 0;
		//�������
	virtual void post_order(void(*)(T*)) = 0;
		//�������
	virtual void level_order(void(*)(T*)) = 0;
};

template<class E>
class LinkBinaryTree : public BinaryTree<BinaryTreeNode<E> > 
{
public:
	LinkBinaryTree() { root_ = nullptr; tree_size_ = 0; }
	~LinkBinaryTree() { }
	 void test()
	{
		std::cout << "linkbinarytree test" << std::endl;
		std::cout << test_ << std::endl;
	}
	bool empty() const { return tree_size_ == 0; }
	int size() const { return tree_size_; }
	int height(BinaryTreeNode<E>* t) const;
		//������չ��������ǰ�����(����#)������������
	void create_binary_tree(BinaryTreeNode<E>* t);
	void create()
	{
		create_binary_tree(root_);
	}
	void make_tree(const E& theElement, LinkBinaryTree<E>& leftTree, LinkBinaryTree<E>& rightTree)
	{
		root_ = new BinaryTreeNode<E>(theElement, leftTree.root_, rightTree.root_);
		tree_size_ = leftTree.tree_size_ + rightTree.tree_size_ + 1;
	}

	void pre_order(void(*theVisit)(BinaryTreeNode<E>*))
	{
		visit = theVisit;
		pre_order(root_);
	}
	void pre_order_unrecursion(void(*theVisit)(BinaryTreeNode<E>*))
	{
		visit = theVisit;
		pre_order_unrecursion(root_);
	}
	void in_order(void(*theVisit)(BinaryTreeNode<E>*))
	{
		visit = theVisit;
		in_order(root_);
	}
	void in_order_unrecursion(void(*theVisit)(BinaryTreeNode<E>*))
	{
		visit = theVisit;
		in_order_unrecursion(root_);
	}
	void post_order(void(*theVisit)(BinaryTreeNode<E>*))
	{
		visit = theVisit;
		post_order(root_);
	}
	void post_order_unrecursion(void(*theVisit)(BinaryTreeNode<E>*))
	{
		visit = theVisit;
		post_order_unrecursion(root_);
	}
	void level_order(void(*theVisit)(BinaryTreeNode<E>*))
	{
		visit = theVisit;
		level_order(root_);
	}
	void erase()
	{
		post_order(dispose);
		root_ = nullptr;
		tree_size_ = 0;
	}
	void pre_order_output()
	{
		pre_order(output);
		std::cout << std::endl;
	}
	void pre_order_unrecursion_output()
	{
		pre_order_unrecursion(output);
		std::cout << std::endl;
	}
	void in_order_output()
	{
		in_order(output);
		std::cout << std::endl;
	}
	void in_order_uncursion_output()
	{
		in_order_unrecursion(output);
		std::cout << std::endl;
	}
	void post_order_output()
	{
		post_order(output);
		std::cout << std::endl;
	}
	void post_order_unrecursion_output()
	{
		post_order_unrecursion(output);
		std::cout << std::endl;
	}
	void level_order_output()
	{
		level_order(output);
		std::cout << std::endl;
	}
	void visit_func(BinaryTreeNode<E>* t)
	{
		std::cout << t->element_ << " ";
	}
	void height_output()
	{
		std::cout << height(root_) << std::endl;
	}
protected:
	BinaryTreeNode<E>* root_;
	int tree_size_;
	static void(*visit)(BinaryTreeNode<E>*);          //ֻ��ָ��
	static void pre_order(BinaryTreeNode<E>* t);	//��ͨ��Ա�����Ĳ����Ǻ���ָ�룬����̬�����Ĳ�����BinaryTreeNode
	static void pre_order_unrecursion(BinaryTreeNode<E>* t);
	static void in_order(BinaryTreeNode<E>* t);
	static void in_order_unrecursion(BinaryTreeNode<E>* t);
	static void post_order(BinaryTreeNode<E>* t);
	static void post_order_unrecursion(BinaryTreeNode<E>* t);
	static void level_order(BinaryTreeNode<E>* t);
	static void dispose(BinaryTreeNode<E>* t);
	static void output(BinaryTreeNode<E>* t);
	//static void visit_func(BinaryTreeNode<E>* t);
};

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
template<class E>
void (*LinkBinaryTree<E>::visit)(BinaryTreeNode<E>*) = nullptr;

template<class E>
int LinkBinaryTree<E>::height(BinaryTreeNode<E>* t) const
{
	if (t != nullptr)
		return 0;
	int h1 = height(t->left_child_);
	int h2 = height(t->right_child_);
	if (h1 > h2)
		return ++h1;
	else
		return ++h2;
}

template<class E>
void LinkBinaryTree<E>::create_binary_tree(BinaryTreeNode<E>* t)
{
	E ch;
	std::cout << "please input the elements: " << std::endl;
	std::cin >> ch;
	if (ch == 0)
		t = nullptr;
	else
	{
			t = new BinaryTreeNode<E>;
			t->element_ = ch;
			LinkBinaryTree<E>::create_binary_tree(t->left_child_);
			LinkBinaryTree<E>::create_binary_tree(t->right_child_);
	}
}

template<class E>
void LinkBinaryTree<E>::pre_order(BinaryTreeNode<E>* t)		//��̬��Ա�����Ķ��岻��Ҫ�ټ�static
{
	if (t != nullptr)
	{
		LinkBinaryTree<E>::visit(t);
		//std::cout << t->element_ << std::endl;
		pre_order(t->left_child_);
		pre_order(t->right_child_);
	}
}
template<class E>
void LinkBinaryTree<E>::pre_order_unrecursion(BinaryTreeNode<E>* t)
{
	std::stack<BinaryTreeNode<E>*> tree_node_stack;
	BinaryTreeNode<E>* current_root = new BinaryTreeNode<E>(t->element_, t->left_child_, t->right_child_);
	
	while (current_root !=nullptr || !tree_node_stack.empty())
	{
		tree_node_stack.push(current_root);
		LinkBinaryTree<E>::visit(current_root);
		current_root = current_root->left_child_;
		while (current_root == nullptr && !tree_node_stack.empty())
		{
			current_root = tree_node_stack.top();
			tree_node_stack.pop();
			current_root = current_root->right_child_;
		}
	}
	delete current_root;
}
template<class E>
void LinkBinaryTree<E>::in_order(BinaryTreeNode<E>* t)
{
	if (t != nullptr)
	{
		in_order(t->left_child_);
		LinkBinaryTree<E>::visit(t);
		//std::cout << t->element_ << std::endl;
		in_order(t->right_child_);
	}
}
template<class E>
void LinkBinaryTree<E>::in_order_unrecursion(BinaryTreeNode<E>* t)
{
	std::stack<BinaryTreeNode<E>*> tree_node_stack;
	BinaryTreeNode<E>* current_root = new BinaryTreeNode<E>(t->element_, t->left_child_, t->right_child_);
	while (current_root != nullptr || !tree_node_stack.empty())
	{
		while (current_root != nullptr)
		{
			tree_node_stack.push(current_root);
			current_root = current_root->left_child_;
		}
		if (!tree_node_stack.empty())
		{
			current_root = tree_node_stack.top();
			LinkBinaryTree<E>::visit(current_root);
			tree_node_stack.pop();
			current_root = current_root->right_child_;
		}
	}
	delete current_root;
}
template<class E>
void LinkBinaryTree<E>::post_order(BinaryTreeNode<E>* t)
{
	if (t != nullptr)
	{
		post_order(t->left_child_);
		post_order(t->right_child_);
		LinkBinaryTree<E>::visit(t);
		//std::cout << t->element_ << std::endl;
	}
}
template<class E>
void LinkBinaryTree<E>::post_order_unrecursion(BinaryTreeNode<E>* t)
{
	std::stack<BinaryTreeNode<E>*> tree_node_stack;
	BinaryTreeNode<E>* current_root = new BinaryTreeNode<E>(t->element_, t->left_child_, t->right_child_);
	BinaryTreeNode<E>* pre_root = nullptr;
	tree_node_stack.push(current_root);
	while (!tree_node_stack.empty())
	{
		current_root = tree_node_stack.top();
		if ((current_root->left_child_ == nullptr&&current_root->right_child_ == nullptr) ||
			(pre_root != nullptr && (pre_root == current_root->left_child_ || pre_root == current_root->right_child_)))
		{
			LinkBinaryTree<E>::visit(current_root);
			tree_node_stack.pop();
			pre_root = current_root;
		}
		else
		{
			if (current_root->right_child_ != nullptr)
				tree_node_stack.push(current_root->right_child_);
			if (current_root->left_child_ != nullptr)
				tree_node_stack.push(current_root->left_child_);
		}
	}
	delete current_root;
	delete pre_root;
}

template<class E>
void LinkBinaryTree<E>::level_order(BinaryTreeNode<E>* t)
{
	ArrayQueue<BinaryTreeNode<E>*> q;
	while (t != nullptr)
	{
		LinkBinaryTree<E>::visit(t);

		if (t->left_child_ != nullptr)
			q.push(t->left_child_);
		if (t->right_child_ != nullptr)
			q.push(t->right_child_);

		try
		{
			t = q.front();
		}
		catch (const char*)
		{
			return;
		}
		q.pop();
		//std::cout << std::endl;
	}
}
template<class E>
void LinkBinaryTree<E>::output(BinaryTreeNode<E>* t)
{
	std::cout << t->element_ << " ";
}

template<class E>
void LinkBinaryTree<E>::dispose(BinaryTreeNode<E>* t)
{
	//if(t!=nullptr)
		delete t;
}
