#pragma once

#include <iostream>
#include <new>

template<class T>
class LinearList {
public:
	virtual ~LinearList() { };
			//�����Ա�Ϊ��ʱ����true
	virtual bool empty() const = 0;
			//�������Ա��Ԫ�ظ���
	virtual int size() const = 0;
			//��������ΪtheIndex��Ԫ��
	virtual T& get(int theIndex) const = 0;
			//����Ԫ��theElement��һ�γ���ʱ������
	virtual int index_of(const T& theElement) const = 0;
			//ɾ������ΪtheIndex��Ԫ��
	virtual void erase(int theIndex) = 0;
			//��theElement���뵽����ΪtheIndex��λ����
	virtual void insert(int theIndex, const T& theElement) = 0;
			//�����Ա���������
	virtual void output(ostream& out) const = 0;
};