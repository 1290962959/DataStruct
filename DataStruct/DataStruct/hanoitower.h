#pragma once
#include <iostream>
#include <new>
#include <iterator>

#include "arraystack.h"

ArrayStack<int> tower[4];

void move_and_show(int, int, int, int);

void towers_of_hanoi(int n)
{
	for (int d = n; d > 0; --d)
		tower[1].push(d);

	move_and_show(n, 1, 2, 3);
}

void move_and_show(int n, int x, int y, int z)
{
	std::cout << "move from " << x << " to " << z << " by " << y << std::endl;
	if (n > 0)
	{
		move_and_show(n - 1, x, z, y);
		int d = tower[x].top();
		tower[x].pop();
		tower[y].push(d);
		tower[1].output();
		tower[2].output();
		tower[3].output();
		move_and_show(n - 1, z, y, x);
	}
}