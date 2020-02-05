﻿#define _CRT_SECURE_NO_WARNINGS 1
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
		int tmp = 0;//进位
		int i = a.size() - 1, j = b.size() - 1;
		string ret;
		for (; i >= 0 || j >= 0 || tmp != 0; i--, j--)
		{
			tmp = (i >= 0 ? tmp + a[i] - '0' : tmp);
			tmp = (j >= 0 ? tmp + b[j] - '0': tmp);
			ret.push_back(tmp % 2 + '0');
			tmp >>= 1;
		}
		reverse(ret.begin(), ret.end());
		return ret;
	}
};
int main42()
{
	Solution s;
	cout<<s.addBinary("111", "1");
	system("pause");
	return 0;
}