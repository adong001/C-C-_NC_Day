#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<cstdio>
using namespace std;
//给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。
//示例 1:
//输入: 123
//输出: 321

// 示例 2:
//输入: -123
//输出: -321

//示例 3:
//输入: 120
//输出: 21
//注意:
//假设我们的环境只能存储得下 32 位的有符号整数，则其数值范围为 [−231,  231 − 1]。
//请根据这个假设，如果反转后整数溢出那么就返回 0。

class Solution {
public:
	int reverse(int x)
	{
		int res = 0;
		while (x)
		{
			if (res > INT_MAX / 10 || res < INT_MIN / 10)
			{
				return 0;
			}
			res = res * 10 + x % 10;
			x /= 10;
		}
		return res;
	}
};
void mysplit(const char* str, char* det[4], char flag)
{
	int len = strlen(str);
	for (int start = 0, end = 0, j = 0; end < len;)
	{
		//找到分割符的位置，end是第一个分隔符的坐标
		for (; str[end] != flag && end < len; end++);
		if (start < end)//从start到end的位置的字符拷贝给det串
		{
			strncat(det[j], str + start, end - start);
		}
		//遍历完中间所有分嗝符
		for (; end < len && str[end] == flag; end++);
		j++;//跟新目的串位置
		start = end;//跟新源串的起始位置，指向下一个非分隔符的位置
	}
}

int main2()
{
	Solution s;
	s.reverse(-10);

	//char* str = { "aaa&bbb&&cc&&d&" };
	//char s1[4] = { 0 };
	//char s2[4] = { 0 };
	//char s3[4] = { 0 };
	//char s4[4] = { 0 };
	//char *det[4] = { s1, s2, s3, s4 };//指针数组---指向四个数组的指针
	//mysplit(str, det, '&');
	//for (int i = 0; i < 4; i++)
	//{
	//	cout << det[i] << endl;
	//}
	return 0;
}