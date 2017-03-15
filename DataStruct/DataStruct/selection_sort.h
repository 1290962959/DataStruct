#pragma once
/*
���ܣ�
	1��ʵ��ѡ��������㷨
	2����������ֵ����a[n-1]�����������µ����ֵ����a[n-2]����������
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
	for (int size = n; size > 1; --size)
	{
		int j = index_of_max<T>(a, size);
		std::swap(a[j], a[size - 1]);
	}
}


//��ʱֹͣ��ѡ������,���һ����־��