#pragma once
#include <iostream>
#include <new>
#include <iterator>
#include "arraystack.h"

struct Position
{
	friend ostream& operator<<(ostream& out, const Position& pos);//������Ϊ��Ԫ����

	int row_;
	int col_;

};

ostream& operator<<(ostream& out, const Position& pos)
{
	out << pos.row_ << " " << pos.col_ << " " << endl;
	return out;
}

ArrayStack<Position>* path = new ArrayStack<Position>;

bool find_path()
{
	
	Position offset[4];
	offset[0].row_ = 0; offset[0].col_ = 1;			//��
	offset[1].row_ = 1; offset[1].col_ = 0;			//��
	offset[2].row_ = 0; offset[2].col_ = -1;		//��
	offset[3].row_ = -1; offset[3].col_ = 0;		//��

	int maze[5][5] = { { 0,1,1,1,1 },{ 1,0,0,0,1 },{ 1,0,0,0,1 },{ 1,0,0,0,1 },{ 1,1,1,1,0 } };		//��ʼ���Թ�

	Position here;
	here.row_ = 1;
	here.col_ = 1;
	maze[1][1] = 1;
	int option = 0;		//��һ��
	int lastOption = 3;

	while (here.row_ != 3 || here.col_ != 3)
	{
		int r, c;
		while (option <= lastOption)
		{
			r = here.row_ + offset[option].row_;
			c = here.col_ + offset[option].col_;
			if (maze[r][c] == 0) break;
			++option;
		}
		if (option <= lastOption)		//�п���ѡ��ĵط�  
		{
			path->push(here);
			here.row_ = r;
			here.col_ = c;
			maze[r][c] = 1;
			option = 0;
		}
		else
		{
												//û�п���ѡ��ĵط������Ӧ�����˻�Ȼ��������
		}
		{
			if (path->empty())
				return false;
			Position next = path->top();
			path->pop();
			if (next.row_ == here.row_)
				option = 2 + next.row_ - here.row_;
			here = next;
		}
	}
	return true;
}