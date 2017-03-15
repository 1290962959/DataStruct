#pragma once


template<class T>
void bubble_sort(T a[], int n)
{
	for(int i=n;i>1;--i)
		for (int j = 0; j < i - 1; ++j)
		{
			if (a[j] > a[j + 1])
				std::swap(a[j], a[j + 1]);
		}
}

//╪╟й╠мёж╧╣дц╟ещеепР