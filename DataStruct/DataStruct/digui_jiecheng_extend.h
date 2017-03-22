#pragma once

#include <stack>
using namespace std; 
/**
  8 * \brief ��n�Ľ׳�
  9 * \para
  10 * \return
  11 * \note result = n! �ݹ�ʵ��
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
   26 * \brief ��n�Ľ׳�
   27 * \para
   28 * \return
   29 * \note result = n! ѭ��ʵ��
   30 */
int FactLoop(long n)
{
 // (����1)
	struct SnapShotStruct // ���սṹ��ֲ����� 
	{
		long inputN;      // ��ı�Ĳ���
	  // û�оֲ�����
		int stage;        // �׶α������ڿ��ո���
	};
// (����2)
	int returnVal;        // ���ڱ��浱ǰ���÷���ֵ  

// (����3)
	stack<SnapShotStruct> snapshotStack;

// (����4)
	SnapShotStruct currentSnapshot;
	currentSnapshot.inputN = n;
	currentSnapshot.stage = 0; // �׶α�����ʼ��

	snapshotStack.push(currentSnapshot);

	// (����5)
	while (!snapshotStack.empty())
	{
		currentSnapshot = snapshotStack.top();
		snapshotStack.pop();
		switch (currentSnapshot.stage)
		{
			// (����7)
			case 0:
				if (0>currentSnapshot.inputN)
				{
						// (����8 & ����9)
					returnVal = -1;
					continue;
				}
				if (0 == currentSnapshot.inputN)
				{
					 // (����8 & ����9)
					returnVal = 1;
					continue;
				}
				else
				{
					 // (����10)
					 // ���� ( n* Fact(n-1)); ��Ϊ2���� 
					// (��һ�����������ڶ����÷���ֵ���Ե�ǰnֵ)
					 // �����������¿���.
						currentSnapshot.stage = 1; // ��ǰ�Ŀ��ձ�ʾ���ڱ��������ȴ�������ý�����أ����Ը�ֵΪ1 
				        snapshotStack.push(currentSnapshot);
	              // ����һ���µĿ��գ����ڵ�������
					SnapShotStruct newSnapshot;
					newSnapshot.inputN = currentSnapshot.inputN - 1; // ��ʼ������ 
					newSnapshot.stage = 0;                         // ��ͷ��ʼִ���������Ը�ֵstage==0 

					snapshotStack.push(newSnapshot);
					continue;
					}
					break;
					// (����7)
					case 1:
						// (����8)
						returnVal = currentSnapshot.inputN * returnVal;
						 // (����9)
						continue;
						break;
						}
				}

			// (����2)
			return returnVal;
}
