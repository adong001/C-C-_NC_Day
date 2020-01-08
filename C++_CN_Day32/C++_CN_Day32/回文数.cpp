#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<algorithm>
using namespace std;
//判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。
//
//示例 1:
//输入 : 121
//输出 : true

//示例 2 :
//输入 : -121
//输出 : false
//解释 : 从左向右读, 为 - 121 。 从右向左读, 为 121 - 。因此它不是一个回文数。

//示例 3 :
//输入 : 10
//输出 : false
//解释 : 从右向左读, 为 01 。因此它不是一个回文数。

class Solution {
public:
	bool isPalindrome(int x)
	{
		if (x < 0)//负数全部排除
		{
			return false;
		}
		else if (0 <= x && x < 10)//1位数都是
		{
			return true;
		}
		else
		{
			string src, dest;
			while (x)//先将数字转换为字符
			{
				src += x % 10;
				x /= 10;
			}
			dest = src;//记录原字符
			reverse(src.begin(), src.end());//将其反转
			if (dest == src)//若源字符串和反转串不一致就不是回文串
			{
				return true;
			}
			return false;
		}
	}
};

int main2()
{
	Solution s;
	s.isPalindrome(1221);
    system("pause");
    return 0;
}