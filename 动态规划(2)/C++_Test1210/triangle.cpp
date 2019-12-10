#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//给出一个三角形，计算从三角形顶部到底部的最小路径和，每一步都可以移动到下面一行相邻的数字，
//例如，给出的三角形如下：
//[↵[2], ↵[3, 4], ↵[6, 5, 7], ↵[4, 1, 8, 3]↵]
//最小的从顶部到底部的路径和是2 + 3 + 5 + 1 = 11。
//注意：
//
//如果你能只用O（N）的额外的空间来完成这项工作的话，就可以得到附加分，其中N是三角形中的行总数。
//
//Given a triangle, find the minimum path sum from top to bottom.Each step you may move to adjacent numbers on the row below.
//For example, given the following triangle
//[↵[2], ↵[3, 4], ↵[6, 5, 7], ↵[4, 1, 8, 3]↵]↵
//
//The minimum path sum from top to bottom is11(i.e., 2 + 3 + 5 + 1 = 11).
//Note:
//Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.
class Solution {
public:
	int minimumTotal(vector<vector<int> > &triangle)
	{
		for (int i = triangle.size() - 2; i >= 0; i--)
		{
			for (int j = 0; j <= i; j++)
			{
				triangle[i][j] = min(triangle[i + 1][j], triangle[i + 1][j + 1]) + triangle[i][j];
			}
		}
		return triangle[0][0];
	}
};
int main2()
{
	while (1)
	{
		printf("hhhh\n");
	}
    system("pause");
    return 0;
}