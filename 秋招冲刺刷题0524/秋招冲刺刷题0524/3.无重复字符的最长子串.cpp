#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<map>
#include<set>
using namespace std;
//给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
//
//示例 1 :
//输入 : "abcabcbb"
//输出 : 3
//解释 : 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
//
//示例 2 :
//输入 : "bbbbb"
//输出 : 1
//解释 : 因为无重复字符的最长子串是 "b"，所以其长度为 1。
//
//示例 3 :
//输入 : "pwwkew"
//输出 : 3
//解释 : 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
//请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
class Solution 
{
public:
	int lengthOfLongestSubstring(string s) 
	{
		int max = 0,tmp;
		int Size = s.size();
		if (Size == 0 || Size == 1)
		{
			return Size;
		}
		map<char, int> mc;
		for (int start = 0, end = 0; end < Size;end++)
		{
			short flag = 1;
			for (; end < Size; end++)
			{
				if (mc.count(s[end]) && mc[s[end]] >= start || end + 1 == Size && end++)
				{
					flag = 0;
					break;
				}
				mc[s[end]] = end;
			}
			max = max > end - start + flag ? max : end - start + flag;
			start = !flag ? mc[s[end]] + 1 : end ;
			mc[s[end]] = end;
		}
		return max;
	}
};

int main1()
{
	Solution s;
	cout << s.lengthOfLongestSubstring("aab") << endl;
	cout << s.lengthOfLongestSubstring("abcdbaf") << endl;
	cout << s.lengthOfLongestSubstring("dedf") << endl;
    return 0;
}