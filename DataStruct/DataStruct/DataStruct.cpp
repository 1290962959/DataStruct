// DataStruct.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


#include <iostream>
#include <list>
#include <new>
#include <iterator>



using namespace std;

long long jiecheng(int n);

//包含抛出错误的头文件
#include "illegalParameterValue.h"

#include "permutations.h"
//permutations排序函数的测试函数
void test_permutations()
{
	int int_list[4] = { 1,2,3,4 };
	permutations<int>(int_list, 0, 3);
}

#include "group_sort.h"
//数组排序方法的测试程序
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
//选择排序法的测试程序
void test_selection_sort()
{
	int a[6] = {6,5,8,4,3,1};
	selection_sort<int>(a, 6);
	copy(a, a + 6, ostream_iterator<int>(std::cout, " "));//如果这里是+5则只显示前五个？？
	std::cout << std::endl;
}

#include "bubble_sort.h"
//冒泡排序的测试程序
void test_bubble_sort()
{
	int a[6] = { 6,5,8,4,3,1 };
	bubble_sort<int>(a,6);
	copy(a, a + 6, ostream_iterator<int>(std::cout, " "));//如果这里是+5则只显示前五个？？
	std::cout << std::endl;
}

#include "insert_sort.h"
//插入排序测试程序
void test_insert_sort()
{
	int a[6] = { 6,5,8,4,3,1 };
	insert_sort<int>(a, 6);
	copy(a, a + 6, ostream_iterator<int>(std::cout, " "));//如果这里是+5则只显示前五个？？
	std::cout << std::endl;
}

#include "linearlist.h"
#include "arraylist.h"
//array list的测试函数
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
//链表的测试程序
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
//箱子排序的测试程序
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
//矩阵的测试程序
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
		//测试乘法
	/*matrix1 = matrix1*matrix2;
	matrix1.output();*/
		//测试加法
	matrix1 = matrix1 + matrix2;
	matrix1.output();
}

#include "arraystack.h"
//数组栈类的测试程序
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
//链栈的测试程序
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
//汉诺塔测试程序
void test_tower()
{
	towers_of_hanoi(3);
}

#include "digui_jiecheng_extend.h"
//防溢出的阶乘测试   实际上并没有效果  采用栈和循环的方式解决递归栈的溢出问题
void test_shendu_jiecheng()
{
	cout << FactLoop(13) << endl;
}

#include "maze.h"
//迷宫的测试程序
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




int main()
{//不要随便使用using namespace std , std里的函数很可能与自己定义的名字重复
	
	//test_permutations();
	//test_group_sort();
	//test_selection_sort();
	//test_bubble_sort();
	//test_array_list();
	//test_chain_list();
	//test_bin_sort();
	//test_matrix();
	//test_array_stack();
	//test_link_stack();

	//cout << jiecheng(13) << endl;

	//test_tower();//递归调用超过10次就会出现栈溢出的问题

	//test_shendu_jiecheng();
	//test_maze();
	//test_array_queue();
	
	return 0;
}

//递归的方法实现n的阶乘,但是超过十就不怎么好用了
long long jiecheng(int n)
{
	if (n == 1)
		return 1;
	else
		return jiecheng(n - 1)*n;
}