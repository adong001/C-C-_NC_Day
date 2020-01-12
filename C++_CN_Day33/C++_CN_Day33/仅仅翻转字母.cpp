#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<cstring>
using namespace std;
//给定一个字符串 S，返回 “反转后的” 字符串，其中不是字母的字符都保留在原地，
//而所有字母的位置发生反转。

//示例 1：
//输入："ab-cd"
//输出："dc-ba"

//示例 2：
//输入："a-bC-dEf-ghIj"
//输出："j-Ih-gfE-dCba"

//示例 3：
//输入："Test1ng-Leet=code-Q!"
//输出："Qedo1ct-eeLg=ntse-T!"

//提示：
//S.length <= 100
//33 <= S[i].ASCIIcode <= 122
//S 中不包含 \ or "

class Solution {
public:
	string reverseOnlyLetters(string S)
	{
		string s = S;
		int i, j;
		char ch;
		for (i = 0, j = S.size() - 1; i < j;)
		{
			while (!isalpha(S[i])){ i++; }
			while (!isalpha(S[j])){ j--; }
			if (i < j)
			{
				ch = s[i];
				s[i] = s[j];
				s[j] = ch;
				i++;
				j--;
			}
		}
		return s;
	}
};

int main4()
{
	Solution s;
	cout << s.reverseOnlyLetters("a - bC - dEf - ghIj");
	system("pause");
	return 0;
}