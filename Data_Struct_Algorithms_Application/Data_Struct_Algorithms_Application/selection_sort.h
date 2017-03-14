#pragma once
/*
功能：
	1、实现选择排序的算法
	2、挑出最大的值放在a[n-1]，再挑出余下的最大值放在a[n-2]，依次类推
*/

#include <new>
#include <iostream>

template<class T>
int index_of_max(T a[], int n)
{
	int index_of_max = 0;
	for (int i = 0; i < n; ++i)
		if (a[index_of_max] < a[i])
			return i;
	return index_of_max;
}

template<class T>
void selection_sort(T a[], int n)
{
	int indexOfMax = index_of_max<T>(a, n);

}