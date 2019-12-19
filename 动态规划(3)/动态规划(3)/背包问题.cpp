#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	int backPackII(int m, vector<int> A, vector<int> V)
	{
		vector<int> retval(m, 0);
		retval[0] = V[0];//背包放第n个商品后背包里面的价值，第一个商品作为索引
		int bagsize = m - A[0];//背包剩余大小

		for (int i = 1; i < A.size(); i++)
		{
			if (A[i] > m)//完全装不下，物品大小大于背包容量
			{
				break;
			}
			else
			{
				if (A[i] <= bagsize)//背包剩余大小能装下此物品
				{

				}

				else// 背包剩余大小能装不下此物品，将上一次的
				{

				}
			}
		}
	}
};
int main()
{
	system("pause");
	return 0;
}