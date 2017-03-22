#pragma once

#include <stack>
using namespace std; 
/**
  8 * \brief 求n的阶乘
  9 * \para
  10 * \return
  11 * \note result = n! 递归实现
  12 */
int Fact(long n)
{
	if (0>n)
		return -1;
	if (0 == n)
		return 1;
	else
	{
	return (n* Fact(n - 1));
	}
}

/**
   26 * \brief 求n的阶乘
   27 * \para
   28 * \return
   29 * \note result = n! 循环实现
   30 */
int FactLoop(long n)
{
 // (步骤1)
	struct SnapShotStruct // 快照结构体局部声明 
	{
		long inputN;      // 会改变的参数
	  // 没有局部变量
		int stage;        // 阶段变量用于快照跟踪
	};
// (步骤2)
	int returnVal;        // 用于保存当前调用返回值  

// (步骤3)
	stack<SnapShotStruct> snapshotStack;

// (步骤4)
	SnapShotStruct currentSnapshot;
	currentSnapshot.inputN = n;
	currentSnapshot.stage = 0; // 阶段变量初始化

	snapshotStack.push(currentSnapshot);

	// (步骤5)
	while (!snapshotStack.empty())
	{
		currentSnapshot = snapshotStack.top();
		snapshotStack.pop();
		switch (currentSnapshot.stage)
		{
			// (步骤7)
			case 0:
				if (0>currentSnapshot.inputN)
				{
						// (步骤8 & 步骤9)
					returnVal = -1;
					continue;
				}
				if (0 == currentSnapshot.inputN)
				{
					 // (步骤8 & 步骤9)
					returnVal = 1;
					continue;
				}
				else
				{
					 // (步骤10)
					 // 返回 ( n* Fact(n-1)); 分为2步： 
					// (第一步调用自身，第二步用返回值乘以当前n值)
					 // 这里我们拍下快照.
						currentSnapshot.stage = 1; // 当前的快照表示正在被处理，并等待自身调用结果返回，所以赋值为1 
				        snapshotStack.push(currentSnapshot);
	              // 创建一个新的快照，用于调用自身
					SnapShotStruct newSnapshot;
					newSnapshot.inputN = currentSnapshot.inputN - 1; // 初始化参数 
					newSnapshot.stage = 0;                         // 从头开始执行自身，所以赋值stage==0 

					snapshotStack.push(newSnapshot);
					continue;
					}
					break;
					// (步骤7)
					case 1:
						// (步骤8)
						returnVal = currentSnapshot.inputN * returnVal;
						 // (步骤9)
						continue;
						break;
						}
				}

			// (步骤2)
			return returnVal;
}
