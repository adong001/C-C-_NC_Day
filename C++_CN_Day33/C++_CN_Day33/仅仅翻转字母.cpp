#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
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
		int i;
		char ch;
		int size = S.size();
		for (i = 0; i <= size / 2; i++)
		{
			ch = S[i];
			S[i] = S[size - i - 1];
			S[size - i - 1] = ch;
		}
		return S;
	}
};

int main4()
{
    system("pause");
    return 0;
}