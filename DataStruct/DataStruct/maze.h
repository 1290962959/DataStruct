#pragma once
#include <iostream>
#include <new>
#include <iterator>
#include "arraystack.h"

struct Position
{
	friend ostream& operator<<(ostream& out, const Position& pos);//都声明为友元函数

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
	offset[0].row_ = 0; offset[0].col_ = 1;			//右
	offset[1].row_ = 1; offset[1].col_ = 0;			//下
	offset[2].row_ = 0; offset[2].col_ = -1;		//左
	offset[3].row_ = -1; offset[3].col_ = 0;		//上

	int maze[5][5] = { { 0,1,1,1,1 },{ 1,0,0,0,1 },{ 1,0,0,0,1 },{ 1,0,0,0,1 },{ 1,1,1,1,0 } };		//初始化迷宫

	Position here;
	here.row_ = 1;
	here.col_ = 1;
	maze[1][1] = 1;
	int option = 0;		//下一步
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
		if (option <= lastOption)		//有可以选择的地方  
		{
			path->push(here);
			here.row_ = r;
			here.col_ = c;
			maze[r][c] = 1;
			option = 0;
		}
		else
		{
												//没有可以选择的地方，理解应该是退回然后重新走
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