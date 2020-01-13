#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。
//最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。
//你可以假设除了整数 0 之外，这个整数不会以零开头。
//
//示例 1 :
//输入 : [1, 2, 3]
//输出 : [1, 2, 4]
//解释 : 输入数组表示数字 123。

//示例 2 :
//输入 : [4, 3, 2, 1]
//输出 : [4, 3, 2, 2]
//解释 : 输入数组表示数字 4321。

class Solution {
public:
	vector<int> plusOne(vector<int>& digits) 
	{
		int size = digits.size();
		if (++digits[size - 1] > 9)//最后一位进位才调整
		{
			for (int i = size - 1; i >= 0; i--)
			{
				if (digits[i] > 9)//第i位进位调整
				{
					digits[i] %= 10;//取个位
					if (i == 0)//到了最高位还有进位，那么就在最高位前面插一位，最大只能进1，例如999+1 ---1000
					{
						digits.insert(digits.begin(), 1);
					}
					else//因为只加1,所以有进位一定是1
					{
						digits[i - 1]++;
					}
					
				}
				else//有一位不进位后面的肯定不会进位，因为只加了1，进位最大为1
				{
					break;
				}
			}
		}
		return digits;
	}
};

int main3()
{
	vector<int> v = { 1, 2, 3 };
	Solution s;
	s.plusOne(v);
    system("pause");
    return 0;
}