#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	/**
	*	正数数组中的最小不可组成和
	*	输入：正数数组arr
	*	返回：正数数组中的最小不可组成和
	*/
	int getFirstUnFormedNum(vector<int> arr, int len) 
	{
		int i,j;
		sort(arr.begin(), arr.end());
		for (i = 0; i < len; i++)
		{
			for (j = i; j < len; j++)//找到第一个比它大的
			{
				if (arr[j] == arr[i])//若找到相等的直接return即可
				{
					return arr[i];
				}
				else if (arr[j] > arr[i])//找到第一个比它大的终止这层循环
				{
					break;
				}
			}



		}
		if (i == len)//没找到
		{
			return arr[len-1] + 1;
		}
		
	}
};
int main3()
{
    system("pause");
    return 0;
}