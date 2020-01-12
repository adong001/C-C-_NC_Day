#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
//给定一个按非递减顺序排序的整数数组 A，
//返回每个数字的平方组成的新数组，要求也按非递减顺序排序。

//示例 1：
//输入：[-4, -1, 0, 3, 10]
//输出：[0, 1, 9, 16, 100]
//
//示例 2：
//输入：[-7, -3, 2, 3, 11]
//输出：[4, 9, 9, 49, 121]
//
//
//提示：
//1 <= A.length <= 10000
//- 10000 <= A[i] <= 10000
//A 已按非递减顺序排序。

class Solution {
public:
	vector<int> sortedSquares(vector<int>& A) 
	{
		for (auto& e : A)
		{
			e *= e;
		}
		sort(A.begin(), A.end());
		return A;
		/*int i = 0;
		int size = A.size();
		int start = 0, end = size - 1;
		vector<int> v(size);
		while (start <= end)
		{
		if (A[start] * A[start] >  A[end] * A[end])
		{
		v[size - i - 1] = A[start] * A[start];
		start++;
		}
		else
		{
		v[size - i - 1] = A[end] * A[end];
		end--;
		}
		i++;
		}
		return v;*/
	}
};

int main3()
{
	vector<int> v = { -7, -3, 2, 3, 11 };
	Solution s;
	s.sortedSquares(v);
    system("pause");
    return 0;
}