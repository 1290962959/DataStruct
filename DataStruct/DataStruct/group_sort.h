#pragma once
#include <new>
#include <iostream>

//����������ݽ������򣬽������rank[]��
template<class T>
void group_rank(T group[], int n, int rank[])
{
	for (int i = 0; i < n; ++i)
		rank[i] = 0;
	for (int i = 1; i < n; ++i)
		for (int j = 0; j < i; ++j)
			if (group[j] <= group[i]) rank[i]++;
			else
				rank[j]++;
}


//ʵ���������ݵ���ȷ����
template<class T>
void rearrange(T a[], int n, int r[])
{
	T* u = new T[n];

	for (int i = 0; i < n; ++i)
		u[r[i]] = a[i];
	for (int i = 0; i < n; ++i)
		a[i] = u[i];
	delete []u;
}

