// DataStruct.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"


#include <iostream>
#include <list>
#include <new>
#include <iterator>

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


using namespace std;
int main()
{
	//test_permutations();
	//test_group_sort();
	//test_selection_sort();
	//test_bubble_sort();
	
	return 0;
}
