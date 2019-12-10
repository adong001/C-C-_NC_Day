#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;
//题目描述
//一个机器人在m×n大小的地图的左上角（起点，下图中的标记“start"的位置）。 
//机器人每次向下或向右移动。机器人要到达地图的右下角。（终点，下图中的标记“Finish"的位置）。 
//可以有多少种不同的路径从起点走到终点？
//上图是3×7大小的地图，有多少不同的路径？
//备注：m和n小于等于100
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