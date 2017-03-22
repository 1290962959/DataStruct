// DataStruct.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"


#include <iostream>
#include <list>
#include <new>
#include <iterator>



using namespace std;

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




int main()
{//��Ҫ���ʹ��using namespace std , std��ĺ����ܿ������Լ�����������ظ�
	
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

	//test_tower();//�ݹ���ó���10�ξͻ����ջ���������

	//test_shendu_jiecheng();
	//test_maze();
	//test_array_queue();
	
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