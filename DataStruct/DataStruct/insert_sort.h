#pragma once

template<class T>
void insert_sort(T a[], int n)
{
	for (int i = 1; i < n; ++i)
	{
		T t = a[i];
		int j;
		for (j = i - 1; j >= 0 && t < a[j]; --j)
			a[j + 1] = a[j];
		a[j + 1] = t;
	}
}