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
		//��������
	int rows() const { return rows_; }
		//��������
	int columns() const { return columns_; }
		//����()����ѧӦ��һ��
	T& operator()(int theRows, int theColumns) const;
		//���ظ�ֵ��
	Matrix<T>& operator=(const Matrix<T>& theMatrix);
		//����һԪ+��
	//Matrix<T> operator+() const;  //unary + һԪ
		//���ض�Ժ+��
	Matrix<T> operator+(const Matrix<T>& theMatrix) const;
		//����һԪ-��
	//Matrix<T> operator-() const; //unary -
		//���ض�Ԫ-��
	//Matrix<T> operator-(const Matrix<T>& theMatrix) const;
		//����*ʵ�־���ĳ˷�
	Matrix<T> operator*(const Matrix<T>& theMatrix) const;
		//����+=
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
	{//���ܸ����Լ�
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
{//�ȿ��Է���ֵ��Ҳ���Զ�������޸�
		//�ж��������ȷ��
	if (theRows<1 || theRows>rows_ || theColumns<1 || theColumns>columns_)
		throw "index error, wrong (x,y)";
	return element_[(theRows - 1)*columns_ + theColumns - 1];
}

template<class T>
Matrix<T> Matrix<T>::operator+(const Matrix<T>& theMatrix) const
{
		//�ж��Ǿ�����ͬ�������ľ���
	if (rows_ != theMatrix.rows_ || columns_ != theMatrix.columns_)
		throw "not match matrix";

		//����һ����Ž���ľ���
	Matrix<T> result(rows_, columns_);
	for (int i = 0; i < rows_*columns_; ++i)
		result.element_[i] = element_[i] + theMatrix.element_[i];

	return result;
}

template<class T>
Matrix<T> Matrix<T>::operator*(const Matrix<T>& theMatrix) const
{
		//�������Ƿ��������
	if (columns_ != theMatrix.rows_)
		throw "match error";

	Matrix<T> result(rows_, theMatrix.columns_);

	for (int i = 1; i <= rows_; ++i)
	{
		for (int j = 1; j <= theMatrix.columns_; ++j)
		{
			T sum=element_[(i-1)*rows_]*theMatrix.element_[j-1];  //�����ﲻ��Ҫ��sum�ĳ�ʼֵ���п��ǣ����Զ���ֵ���뷨�ǳ���
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