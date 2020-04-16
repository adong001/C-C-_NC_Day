#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;
//题目描述
//有 n 个物品和一个大小为 m 的背包.给定数组 A 表示每个物品的大小和数组 V 表示每个物品的价值.
//问最多能装入背包的总价值是多大 ?

/*
状态：
F(i, j): 前i个物品放入大小为j的背包中所获得的最大价值
状态递推：对于第i个商品，有一种例外，装不下，两种选择，放或者不放
如果装不下：此时的价值与前i-1个的价值是一样的
F(i,j) = F(i-1,j)
如果可以装入：需要在两种选择中找最大的
F(i, j) = max{F(i-1,j), F(i-1, j - A[i]) + V[i]}
F(i-1,j): 表示不把第i个物品放入背包中， 所以它的价值就是前i-1个物品放入大小为j的背包的最大价值
F(i-1, j - A[i]) + V[i]：表示把第i个物品放入背包中，价值增加V[i],但是需要腾出j - A[i]的大小放
第i个商品
初始化：第0行和第0列都为0，表示没有装物品时的价值都为0
F(0,j) = F(i,0) = 0
返回值：F(n,m)
*/
class Solution {
public:
	int backPackI(int m, vector<int> A, vector<int> V)
	{
		if (A.empty() || V.empty() || m < 1) {
			return 0;
		}
		//多加一行一列，用于设置初始条件
		const int N = A.size() + 1;
		const int M = m + 1;
		vector<vector<int> > result;
		result.resize(N);
		//初始化所有位置为0，第一行和第一列都为0，初始条件
		for (int i = 0; i != N; ++i) {
			result[i].resize(M, 0);
		}
		for (int i = 1; i < N; ++i) {
			for (int j = 1; j != M; ++j) {
				//第i个商品在A中对应的索引为i-1: i从1开始
				//如果第i个商品大于j,说明放不下， 所以(i,j)的最大价值和(i-1,j)相同
				if (A[i - 1] > j) {
					result[i][j] = result[i - 1][j];
				}
				//如果可以装下，分两种情况，装或者不装
				//如果不装，则即为(i-1, j)
				//如果装，需要腾出放第i个物品大小的空间： j - A[i-1],装入之后的最大价值即为(i - 1, 
				j - A[i - 1]) + 第i个商品的价值V[i - 1]
					//最后在装与不装中选出最大的价值
				else {
					int newValue = result[i - 1][j - A[i - 1]] + V[i - 1];
					result[i][j] = max(newValue, result[i - 1][j]);
				}
			}
		}
		//返回装入前N个商品，物品大小为m的最大价值
		return result[N - 1][m];
	}

	/*
	优化算法：
	上面的算法在计算第i行元素时，只用到第i-1行的元素，所以二维的空间可以优化为一维空间
	但是如果是一维向量，需要从后向前计算，因为后面的元素更新需要依靠前面的元素未更新（模拟二维矩阵的上一行的
	值）的值
	*/


	int backPackII(int m, vector<int> A, vector<int> V) {
		if (A.empty() || V.empty() || m < 1) {
			return 0;
		}

		const int N = A.size();
		//多加一列，用于设置初始条件，因为第一件商品要用到前面的初始值
		const int M = m + 1;
		vector<int> result;
		//初始化所有位置为0，第一行都为0，初始条件
		result.resize(M, 0);
		//这里商品的索引位置不需要偏移，要和未优化的方法区分开
		//这里的i-1理解为上一行，或者未更新的一维数组值
		for (int i = 0; i != N; ++i) {
			for (int j = M - 1; j > 0; --j) {
				//如果第i个商品大于j,说明放不下， 所以(i,j)的最大价值和(i-1,j)相同
				if (A[i] > j) {
					result[j] = result[j];
				}
				//如果可以装下，分两种情况，装或者不装
				//如果不装，则即为(i-1, j)
				//如果装，需要腾出放第i个物品大小的空间： j - A[i],装入之后的最大价值即为(i - 1, j 
				-A[i - 1]) + 第i个商品的价值V[i]
					//最后在装与不装中选出最大的价值
				else {
					int newValue = result[j - A[i]] + V[i];
					result[j] = max(newValue, result[j]);
				}
			}
		}
		//返回装入前N个商品，物品大小为m的最大价值
		return result[m];
	}
};
//};
//		class Solution {
//		public:
//			int backPackII(int m, vector<int> A, vector<int> V)
//			{
//				vector<int> retval(m, 0);
//				retval[0] = V[0];//背包放第n个商品后背包里面的价值，第一个商品作为索引
//				int bagsize = m - A[0];//背包剩余大小
//
//				for (int i = 1; i < A.size(); i++)
//				{
//					if (A[i] > m)//完全装不下，物品大小大于背包容量
//					{
//						break;
//					}
//					else
//					{
//						if (A[i] <= bagsize)//背包剩余大小能装下此物品
//						{
//
//						}
//
//						else// 背包剩余大小能装不下此物品，将上一次的
//						{
//
//						}
//					}
//				}
//			}
//		};
int main()
{
	system("pause");
	return 0;
}