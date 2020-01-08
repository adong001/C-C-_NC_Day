#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;
//给定一个仅包含大小写字母和空格 ' ' 的字符串，返回其最后一个单词的长度。
//如果不存在最后一个单词，请返回 0 。
//说明：一个单词是指由字母组成，但不包含任何空格的字符串。

//示例 :
//输入 : "Hello World"
//输出 : 5

class Solution {
public:
	int lengthOfLastWord(string s)
	{
		int len = 0;
		int i;
		for (i = s.size() - 1; s[i] == ' '&& i >= 0; i--);//去掉串尾的空格
		if (i < 0)//越界直接直接return
		{
			return 0;
		}
		for (; i >= 0 && s[i] != ' '; i--, len++);//记录最后一个单词的长度
		return len;//返回最后一个单词的长度
	}
};

int main3()
{
	Solution s;
	s.lengthOfLastWord("d");
    system("pause");
    return 0;
}