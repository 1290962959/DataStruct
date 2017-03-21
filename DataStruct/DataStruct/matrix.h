#pragma once
#include <iostream>
#include <new>
#include <iterator>

template<class T>
class Matrix
{
	//friend ostream& operator<<(ostream& out, const matrix<T>& theMatrix);
public:
	Matrix(int theRows = 0, int theColums = 0);
	Matrix(const Matrix<T>& theMatrix);
	~Matrix() { delete element_; }
		//返回行数
	int rows() const { return rows_; }
		//返回列数
	int columns() const { return columns_; }
		//重载()与数学应用一致
	T& operator()(int theRows, int theColumns) const;
		//重载赋值号
	Matrix<T>& operator=(const Matrix<T>& theMatrix);
		//重载一元+号
	//Matrix<T> operator+() const;  //unary + 一元
		//重载二院+号
	Matrix<T> operator+(const Matrix<T>& theMatrix) const;
		//重载一元-号
	//Matrix<T> operator-() const; //unary -
		//重载二元-号
	//Matrix<T> operator-(const Matrix<T>& theMatrix) const;
		//重载*实现矩阵的乘法
	Matrix<T> operator*(const Matrix<T>& theMatrix) const;
		//重载+=
	//Matrix<T>& operator+=(const T&);

	void output() const;
private:
	int rows_;
	int columns_;
	T* element_;
};

template<class T>
Matrix<T>::Matrix(int theRows, int theColumns)
{
	if (theRows < 0 || theColumns < 0)
		throw "rows and columns must be >=0";
	if ((theRows == 0 || theColumns == 0) && (theRows != 0 || theColumns != 0))
		throw "rows and columns be 0 not the same time is wrong";
	rows_ = theRows;
	columns_ = theColumns;
	element_ = new T[rows_*columns_];
}

template<class T>
Matrix<T>::Matrix(const Matrix<T>& theMatrix)
{
	rows_ = theMatrix.rows_;
	columns_ = theMatrix.columns_;
	element_ = new T[rows_*columns_];

	copy(theMatrix.element_, theMatrix.element_ + rows_*columns_, element_);
}

template<class T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T>& theMatrix)
{
	if (this != &theMatrix)   
	{//不能复制自己
		delete element_;
		rows_ = theMatrix.rows_;
		columns_ = theMatrix.columns_;
		element_ = new T[rows_*columns_];
		copy(theMatrix.element_, theMatrix.element_ + rows_*columns_, element_);
	}
	return *this;
}

template<class T>
T& Matrix<T>::operator()(int theRows, int theColumns) const
{//既可以返回值，也可以对其进行修改
		//判定坐标的正确性
	if (theRows<1 || theRows>rows_ || theColumns<1 || theColumns>columns_)
		throw "index error, wrong (x,y)";
	return element_[(theRows - 1)*columns_ + theColumns - 1];
}

template<class T>
Matrix<T> Matrix<T>::operator+(const Matrix<T>& theMatrix) const
{
		//判断是具有相同行列数的矩阵
	if (rows_ != theMatrix.rows_ || columns_ != theMatrix.columns_)
		throw "not match matrix";

		//生成一个存放结果的矩阵
	Matrix<T> result(rows_, columns_);
	for (int i = 0; i < rows_*columns_; ++i)
		result.element_[i] = element_[i] + theMatrix.element_[i];

	return result;
}

template<class T>
Matrix<T> Matrix<T>::operator*(const Matrix<T>& theMatrix) const
{
		//检测矩阵是否符合条件
	if (columns_ != theMatrix.rows_)
		throw "match error";

	Matrix<T> result(rows_, theMatrix.columns_);

	for (int i = 1; i <= rows_; ++i)
	{
		for (int j = 1; j <= theMatrix.columns_; ++j)
		{
			T sum=element_[(i-1)*rows_]*theMatrix.element_[j-1];  //在这里不需要对sum的初始值进行考虑，会自动赋值，想法非常好
			for (int k = 2; k <= columns_; ++k)
			{
				sum += element_[(i-1)*rows_+k-1]*theMatrix.element_[(k-1)*theMatrix.rows_+j-1];
				//theMatrix(i,k);
			}
			result(i,j) = sum;
		}
	}

	return result;
}

template<class T>
void Matrix<T>::output() const
{
	for (int i = 0; i < rows_; ++i)
	{
		for (int j = 0; j < columns_; ++j)
			std::cout << element_[i*rows_ + j] << " ";
		std::cout << std::endl;
	}
}