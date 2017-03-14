#pragma once


/*功能：
1、输出所有的数组内数据的排序方式
时间：
2017.03.14
作者：
韩彬
*/

#include <iterator>

using namespace std;

template<class Type>
void permutations(Type list[], int k, int m)
{
	if (k == m)
	{
		copy(list, list + m + 1, ostream_iterator<Type>(cout, " "));
		cout << endl;//<< list[0] << list[1] << list[2] << list[3] 
	}
	
	else
		for (int i = k; i <= m; i++)
		{
			swap(list[k], list[i]);
			permutations(list, k + 1, m);
			swap(list[k], list[i]);
		}
}