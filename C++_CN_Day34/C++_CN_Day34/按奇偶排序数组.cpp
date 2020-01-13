#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;
//给定一个非负整数数组A，返回一个数组，在该数组中，
//A的所有偶数元素之后跟着所有奇数元素。
//你可以返回满足此条件的任何数组作为答案。
//示例：
//输入：[3, 1, 2, 4]
//输出：[2, 4, 3, 1]
//输出[4, 2, 3, 1]，[2, 4, 1, 3] 和[4, 2, 1, 3] 也会被接受。
//
//提示：
//1 <= A.length <= 5000
//0 <= A[i] <= 5000

class Solution {
public:
	vector<int> sortArrayByParity(vector<int>& A) 
	{
		vector<int> tmp(A.size());
		int i = 0, j = A.size() - 1;
		for (auto& e : A)
		{
			if (e % 2 == 0)
			{
				tmp[i] = e;
				i++;
			}
			else
			{
				tmp[j] = e;
				j--;
			}
		}
		return tmp;
	}
};
int main1()
{
    system("pause");
    return 0;
}