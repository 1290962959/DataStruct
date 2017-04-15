// DataStruct.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"


#include <iostream>
#include <list>
#include <new>
#include <iterator>
#include <string>
#include <time.h>
#include <Windows.h>  
using namespace std;
using std::string;
long long jiecheng(int n);



//�����׳������ͷ�ļ�
#include "illegalParameterValue.h"

#include "permutations.h"
//permutations�������Ĳ��Ժ���
void test_permutations()
{
	int int_list[4] = { 1,2,3,4 };
	permutations<int>(int_list, 0, 3);
}

#include "group_sort.h"
//�������򷽷��Ĳ��Գ���
void test_group_sort()
{
	int a[5] = { 2,5,7,3,1 };
	int r[5];
	group_rank<int>(a, 5, r);
	rearrange<int>(a, 5, r);
	for (int i = 0; i < 5; ++i)
		cout << a[i];
	cout << endl;
}

#include "selection_sort.h"
//ѡ�����򷨵Ĳ��Գ���
void test_selection_sort()
{
	int a[6] = {6,5,8,4,3,1};
	selection_sort<int>(a, 6);
	copy(a, a + 6, ostream_iterator<int>(std::cout, " "));//���������+5��ֻ��ʾǰ�������
	std::cout << std::endl;
}

#include "bubble_sort.h"
//ð������Ĳ��Գ���
void test_bubble_sort()
{
	int a[6] = { 6,5,8,4,3,1 };
	bubble_sort<int>(a,6);
	copy(a, a + 6, ostream_iterator<int>(std::cout, " "));//���������+5��ֻ��ʾǰ�������
	std::cout << std::endl;
}

#include "insert_sort.h"
//����������Գ���
void test_insert_sort()
{
	int a[6] = { 6,5,8,4,3,1 };
	insert_sort<int>(a, 6);
	copy(a, a + 6, ostream_iterator<int>(std::cout, " "));//���������+5��ֻ��ʾǰ�������
	std::cout << std::endl;
}

#include "linearlist.h"
#include "arraylist.h"
//array list�Ĳ��Ժ���
void test_array_list()
{
	//ArrayList<int> al(10);
	//al.insert(0, 1);
	//al.insert(1,6);
	//if (!al.empty())
	//	cout << "not empty" << endl;
	//cout << al.index_of(1) << endl;
	//al.output(cout);
	//al.get(3);
	//throw "why";
	LinearList<int>* ll = new ArrayList<int>(10);
	ll->insert(0, 1);
	if (!ll->empty())
		cout << "not empty " << ll->size() << endl;
	ll->output(cout);
	cout << ll->get(0) << endl;
	ll->erase(0);
	if (ll->empty())
		cout << "empty" << endl;
	
}

#include "chainlist.h"
//����Ĳ��Գ���
void test_chain_list()
{
	ChainList<int> test_chain(10);
	test_chain.insert(0,0);
	if (!test_chain.empty())
	{
		cout << "not empty" << endl;
		test_chain.output(cout);
	}
	test_chain.insert(1, 1);
	test_chain.insert(2, 2);

	test_chain.output(cout);
	test_chain.erase(1);
	test_chain.output(cout);
	cout << test_chain.index_of(0) << endl;
}

#include "binsort.h"
//��������Ĳ��Գ���
void test_bin_sort()
{
	ChainList<StudentRecord>* newChain=new ChainList<StudentRecord>;
	
	newChain->insert(0, StudentRecord(3, "A"));
	newChain->insert(1,StudentRecord(1,"B"));
	newChain->insert(2, StudentRecord(0, "C"));
	newChain->insert(3, StudentRecord(5, "D"));

	newChain->output(cout);
	bin_sort(*newChain, 5);
	newChain->output(cout);
}

#include "matrix.h"
//����Ĳ��Գ���
void test_matrix()
{
	Matrix<int> matrix1(3,3);
	matrix1(1, 1) = 1;
	matrix1(1, 2) = 2;
	matrix1(1, 3) = 3;
	matrix1(2, 1) = 4;
	matrix1(2, 2) = 5;
	matrix1(2, 3) = 6;
	matrix1(3, 1) = 7;
	matrix1(3, 2) = 8;
	matrix1(3, 3) = 9;
	matrix1.output();
	Matrix<int> matrix2(3, 3);
	matrix2(1, 1) = 1;
	matrix2(1, 2) = 2;
	matrix2(1, 3) = 3;
	matrix2(2, 1) = 4;
	matrix2(2, 2) = 5;
	matrix2(2, 3) = 6;
	matrix2(3, 1) = 7;
	matrix2(3, 2) = 8;
	matrix2(3, 3) = 9;
	matrix2.output();
	matrix1 = matrix2;
	matrix1.output();
	cout << matrix1(3, 3) << endl;
		//���Գ˷�
	/*matrix1 = matrix1*matrix2;
	matrix1.output();*/
		//���Լӷ�
	matrix1 = matrix1 + matrix2;
	matrix1.output();
}

#include "arraystack.h"
//����ջ��Ĳ��Գ���
void test_array_stack()
{
	ArrayStack<int> as1(10);
	if (as1.empty())
	{
		as1.push(1);
		as1.push(2);
	}
	cout << as1.size() << endl;
	as1.pop();
	cout << as1.size() << endl;
	cout<<as1.top()<<endl;
}

#include "linkstack.h"
//��ջ�Ĳ��Գ���
void test_link_stack()
{
	

	LinkStack<int> ls;
	if (ls.empty())
	{
		ls.push(3);
		ls.push(2);
	}
	cout << ls.size() << endl;
	ls.pop();
	
	cout << ls.size() << endl;
	cout << ls.top() << endl;

	
	
}

#include "hanoitower.h"
//��ŵ�����Գ���
void test_tower()
{
	towers_of_hanoi(3);
}

#include "digui_jiecheng_extend.h"
//������Ľ׳˲���   ʵ���ϲ�û��Ч��  ����ջ��ѭ���ķ�ʽ����ݹ�ջ���������
void test_shendu_jiecheng()
{
	cout << FactLoop(13) << endl;
}

#include "maze.h"
//�Թ��Ĳ��Գ���
void test_maze()
{
	if (find_path())
	{
		path->output();
	}
}

#include "queue.h"
void test_array_queue()
{
	ArrayQueue<int> aq(10);
	aq.push(1);
	if (aq.empty())
		cout << "empty" << endl;
	else
		aq.output();
	aq.push(2);
	aq.push(5);
	cout << aq.front() << endl;
	cout << aq.back() << endl;
	aq.output();
	aq.pop();
	cout << aq << endl;
}

#include "guibingsort.h"
void test_guibing()
{
	int a[10] = { 9,8,7,6,5,4,3,2,1,0 };
	merge_sort(a, 3, 8);
	for (int i = 0; i < 10; ++i)
		cout << a[i]<<" ";
	cout << endl;
}

#include "tree.h"
void test_tree()
{
	
	//LinkBinaryTree<int> tree1;
	//LinkBinaryTree<int> tree2;
	//LinkBinaryTree<int> tree3;
	//LinkBinaryTree<int> tree4;
	//LinkBinaryTree<int> tree5;
	//tree4.make_tree(4, tree5, tree5);
	//tree3.make_tree(3, tree4, tree5);
	//tree2.make_tree(2, tree4, tree5);
	//tree1.make_tree(1, tree2, tree3);
	//cout << tree1.size() << endl;
	//tree1.pre_order_output();
	//tree1.pre_order_unrecursion_output();
	//tree1.in_order_output();
	//tree1.in_order_uncursion_output();
	//tree1.post_order_output();
	//tree1.post_order_unrecursion_output();
	//tree1.level_order_output();
	//tree1.height_output();

	//LinkBinaryTree<int> tree8;
	//tree8.create();
	//tree8.pre_order_output();
	//tree8.in_order_uncursion_output();
	//tree8.post_order_output();
		//	erase�������������
	//tree1.erase();
}

//#pragma pack(4)

#include "priorityqueue.h"
void test_maxHeap()
{
	MaxHeap<int> mheap;
	int a[11] = {0,5,9,1,7,3,6,2,4,15,12 };
	mheap.initialize(a, 10);
	for(int i=0;i<10;++i)
	{
		cout << mheap.top(); 
		mheap.pop();			//������ʵ���Ѿ��Ƕ�������
	}
	
}

#include "searchtree.h"
void test_search_tree()
{
	BinarySearchTree<int, string> bst;
	bst.insert(pair<int, string>(5, "bin"));
	bst.insert(pair<int,string>(1, "hanbin"));
	bst.insert(pair<int, string>(2, "han"));
	bst.erase(1);
	cout << bst.size() << endl;
	cout << (*bst.find(2)).second << endl;
	bst.ascend();
}
#include "fastsort.h"
void test_fast_sort()
{
	int a[10] = { 9,8,7,6,5,4,3,2,1,0 };
	fast_sort(a, 0, 9);
	for (int k = 0; k < 10; ++k)
		cout << a[k] << " ";
	cout << endl;
}

int main()
{//��Ҫ���ʹ��using namespace std , std��ĺ����ܿ������Լ�����������ظ�
	//cout << test_static::a_ << endl;
	//test_permutations();
	//test_group_sort();
	//test_selection_sort();
	//test_bubble_sort();
	//test_array_list();
	//test_chain_list();
	//test_bin_sort();
	//test_matrix();
	//test_array_stack();

	//long long start, finish;
	//long long total;
	//start = GetTickCount();
	//for(int i=0;i<30000;++i)
	//test_link_stack();

	//finish = GetTickCount();
	//cout << start << endl;
	//cout << finish << endl;
	//cout << (double)(finish - start) / 3 << endl;
	//cout << jiecheng(12) << endl;

	//test_tower();//�ݹ���ó���10�ξͻ����ջ���������

	//test_shendu_jiecheng();
	//test_maze();
	//test_array_queue();
	
	//test_tree();

	//test_maxHeap();
	//system("PAUSE");

	//test_search_tree();
	//test_guibing();
	test_fast_sort();
	return 0;
}

//�ݹ�ķ���ʵ��n�Ľ׳�,���ǳ���ʮ�Ͳ���ô������
long long jiecheng(int n)
{
	if (n == 1)
		return 1;
	else
		return jiecheng(n - 1)*n;
}