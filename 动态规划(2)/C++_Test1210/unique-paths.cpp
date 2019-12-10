#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;
//��Ŀ����
//һ����������m��n��С�ĵ�ͼ�����Ͻǣ���㣬��ͼ�еı�ǡ�start"��λ�ã��� 
//������ÿ�����»������ƶ���������Ҫ�����ͼ�����½ǡ����յ㣬��ͼ�еı�ǡ�Finish"��λ�ã��� 
//�����ж����ֲ�ͬ��·��������ߵ��յ㣿
//��ͼ��3��7��С�ĵ�ͼ���ж��ٲ�ͬ��·����
//��ע��m��nС�ڵ���100
//
//A robot is located at the top - left corner of a m x n grid(marked 'Start' in the diagram below).
//The robot can only move either down or right at any point in time.The robot is trying to reach the bottom - right corner of the grid(marked 'Finish' in the diagram below).
//How many possible unique paths are there ?
//
//Above is a 3 x 7 grid.How many possible unique paths are there ?
//Note : m and n will be at most 100.

class Solution
{
public:
	int uniquePaths(int m, int n)
	{
		vector<vector<int>> v(m, vector<int>(n, 1));
		for (int i = 1; i < m; i++)
		{
			for (int j = 1; j < n; j++)
			{
				v[i][j] = v[i - 1][j] + v[i][j - 1];
			}
		}
		return v[m - 1][n - 1];
	}


};
int main3()
{
	Solution b;
	b.uniquePaths(1, 1);
	system("pause");
	return 0;
}