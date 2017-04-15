#pragma once
int once_sort(int* a, int start, int end)
{
	int i = start, j = end;
	int privot = a[i];
	while (i < j)
	{
		while (i<j&&a[j]>privot)
			--j;
		if (i < j)
			a[i++] = a[j];
		while (i < j&&a[i] >= privot)
			++i;
		if (i < j)
			a[j--] = a[i];

	}
	a[i] = privot;
	return i;
}

void fast_sort(int* a, int start, int end)
{
	if (start < end) {
		int Privot = once_sort(a, start, end);
		fast_sort(a, start, Privot - 1);
		fast_sort(a, Privot + 1, end);
	}
}