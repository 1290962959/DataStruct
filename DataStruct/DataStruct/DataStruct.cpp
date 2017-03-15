// DataStruct.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


#include <iostream>
#include <list>
#include <new>
#include <iterator>

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


using namespace std;
int main()
{
	//test_permutations();
	//test_group_sort();
	//test_selection_sort();
	//test_bubble_sort();
	
	return 0;
}
