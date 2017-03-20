// DataStruct.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"


#include <iostream>
#include <list>
#include <new>
#include <iterator>

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


using namespace std;

int main()
{
	//test_permutations();
	//test_group_sort();
	//test_selection_sort();
	//test_bubble_sort();
	//test_array_list();
	//test_chain_list();
	//test_bin_sort();
	return 0;
}
