#pragma once
#include <iostream>

using namespace std;

void merge(int* a, int start, int mid, int end)
{
	int i = start, j = mid + 1, index = 0;
	int* temp = new int[end-start+1]();
	while (i <= mid&&j <= end)
	{
		if (a[i] <= a[j])
			temp[index++] = a[i++];
		else
			temp[index++] = a[j++];
	}
	while (i<=mid)
	{
		temp[index++] = a[i++];
	}
	while (j<=end)
	{
		temp[index++] = a[j++];
	}
	copy(temp, temp + end - start+1, a+start);
	//for (int k = 0; k <= index; ++k)
		//std::cout << temp[k] << " ";
	delete[] temp;
}
void merge_sort(int* a, int start, int end)
{
	int mid;
	if (start < end)
	{
		mid = (int)(end + start) / 2;
		merge_sort(a, start, mid);
		merge_sort(a, mid + 1, end);
		merge(a, start, mid, end);
	}
}