#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;
//
//实现函数 ToLowerCase()，该函数接收一个字符串参数 str，
//并将该字符串中的大写字母转换成小写字母，之后返回新的字符串。

//示例 1：
//输入 : "Hello"
//输出 : "hello"

//示例 2：
//输入 : "here"
//输出 : "here"

//示例 3：
//输入 : "LOVELY"
//输出 : "lovely"


class Solution {
public:
	string toLowerCase(string str) 
	{
		for (auto& ch : str)
		{
			if ('A' <= ch && ch <= 'Z')
			{
				ch += 32;
			}
		}
	/*大写变小写、小写变大写: 字符 ^= 32;

	大写变小写、小写变小写: 字符 |= 32;

	小写变大写、大写变大写: 字符 &= -33;*/
		return str;
	}
};

int main1()
{
	printf("%d %d\n", 'c', 'C');
    system("pause");
    return 0;
}