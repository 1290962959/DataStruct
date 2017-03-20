#pragma once
#include <iostream>
#include <new>
#include <iterator>

template<class T>
class Matrix
{
	friend ostream& operator<<(ostream& out, const matrix<T>& theMatrix);
public:
	Matrix(int theRows = 0, int theColums = 0);
	Matrix(const Matrix<T>& theMatrix);
	~Matrix() { delete element_; }
private:
	int rows_;
	int columns_;
	T* element_;
};