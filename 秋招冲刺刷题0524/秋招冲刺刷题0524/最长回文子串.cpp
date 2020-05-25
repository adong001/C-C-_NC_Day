#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;
//给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。
//
//示例 1：
//输入 : "babad"
//输出 : "bab"
//注意 : "aba" 也是一个有效答案。
//
//示例 2：
//输入 : "cbbd"
//输出 : "bb"

class Solution
{
public:
	bool IsPalindrom(string& s)
	{
		int end = s.size() - 1;
		for (int start = 0; start <= end; start++, end--)
		{
			if (s[start] != s[end])
			{
				return false;
			}
		}
		return true;
	}
	string longestPalindrome(string s)
	{
		int max = 0;

	}
};
int main2()
{
    return 0;
}