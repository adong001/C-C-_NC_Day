#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
//给定两个二进制字符串，返回他们的和（用二进制表示）。
//输入为非空字符串且只包含数字 1 和 0。
//
//示例 1 :
//输入 : a = "11", b = "1"
//输出 : "100"

//示例 2 :
//输入 : a = "1010", b = "1011"
//输出 : "10101"

class Solution {
public:
	string addBinary(string a, string b)
	{
		char tmp = 0;//进位
		int i, j;
		string ret, ch;
		for (i = a.size() - 1, j = b.size() - 1; i >= 0 && j >= 0; i--, j--)
		{
			if ((a[i] - '0') + (b[j] - '0') + tmp == 0)
			{
				tmp = 0;
				ret.push_back('0');
			}
			else if ((a[i] - '0') + (b[j] - '0') + tmp == 1)
			{
				tmp = 0;
				ret.push_back('1');
			}
			else if ((a[i] - '0') + (b[j] - '0') + tmp == 2)
			{
				tmp = 1;
				ret.push_back('0');
			}
			else
			{
				tmp = 1;
				ret.push_back('1');
			}
		}
		if (i >= 0)//a未算完
		{
			ch.insert(ch.begin(), a.begin(), a.begin() + i + 1);
		}
		else//b未算完
		{
			ch.insert(ch.begin(), b.begin(), b.begin() + i + 1);
		}
		for (i = ch.size() - 1; i >= 0; i--)
		{
			if ((ch[i] - '0') + tmp == 0)
			{
				ret.push_back('0');
				tmp = 0;
			}
			else if ((ch[i] - '0') + tmp == 1)
			{
				ret.push_back('1');
				tmp = 0;
			}
			else
			{
				ret.push_back('0');
				tmp = 1;
			}
		}
		if (tmp == 1)
		{
			ret.push_back('1');
		}
		reverse(ret.begin(), ret.end());
		return ret;
	}
};
int main()
{
	Solution s;
	s.addBinary("111", "1");
	system("pause");
	return 0;
}