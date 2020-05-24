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
		int max = 0, count;
		int Size = s.size();
		map<char, int> mc;
		for (int start = 0, end = 0; end < Size; end = start)
		{
			count = 0;
			mc.clear();
			bool flag = false;
			for (; end < Size; end++, count++)
			{
				if (mc.count(s[end]))
				{
					flag = true;
					break;
				}
				mc[s[end]] = end;
			}
			start = flag ? mc[s[end]] + 1 : end;
			max = max > count ? max : count;
		}
		return max;
	}
};

int lengthOfLongestSubstring(string s)
{
	int l = 0, r = l, _max = 0;
	set<char> sc;
	while (r != s.size())
	{
		if (sc.find(s[r]) == sc.end())//没找到
		{
			sc.insert(s[r++]);
			_max = _max > r - l ?_max :r - 1;
		}
		else sc.erase(s[l++]);
	}
	return _max;
}
int main1()
{
	Solution s;
	cout << s.lengthOfLongestSubstring("dvdf") << endl;
    return 0;
}