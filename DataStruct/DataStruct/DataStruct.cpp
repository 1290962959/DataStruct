// DataStruct.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"


#include <iostream>
#include <list>
#include <new>

#include "permutations.h"
#include "group_sort.h"

//permutations�������Ĳ��Ժ���
void test_permutations()
{
	int int_list[4] = { 1,2,3,4 };
	permutations<int>(int_list, 0, 3);
}

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
int main()
{
	//test_permutations();
	//test_group_sort();
	return 0;
}
