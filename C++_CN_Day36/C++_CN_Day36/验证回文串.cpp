#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<cstring>
using namespace std;

//给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。
//说明：本题中，我们将空字符串定义为有效的回文串。
//
//示例 1:
//输入 : "A man, a plan, a canal: Panama"
//输出 : true

//示例 2 :
// 输入 : "race a car"
// 输出 : false


class Solution {
public:
	bool isPalindrome(string s) 
	{
		int i,j;
		for (i = 0, j = s.size() - 1; i < j;)
		{
			while (i < j && !isalnum(s[i])){ i++; }//去掉的不是数字和字母的字符
			while (j > i && !isalnum(s[j])){ j--; }
			if (j <= i)//去过后跳出就直接retrun
			{
				return true;
			}
			if (isdigit(s[i]) && isdigit(s[j]))//都是数字
			{
				if (s[i] == s[j])
				{
					i++;
					j--;
				}
				else
				{
					return false;
				}
			}
			else if(isalpha(s[i]) && isalpha(s[j]))//都是字母
			{
				//大写变小写、小写变大写: 字符 ^= 32;
				//大写变小写、小写变小写: 字符 |= 32;
				//小写变大写、大写变大写: 字符 &= -33;
				s[i] |= 32;//全变成小写
				s[j] |= 32;
				if (s[i] == s[j])
				{
					i++;
					j--;
				}
				else
				{
					return false;
				}
			}
			else//是字母和数字混合
			{
				return false;
			}
		}
		return true;
	}
};

int main1()
{
	Solution s;
	cout << s.isPalindrome("A man, a plan, a canal : Panama");
    system("pause");
    return 0;
}