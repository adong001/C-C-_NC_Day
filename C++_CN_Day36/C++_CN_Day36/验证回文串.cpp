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
			if (isalnum(s[i] && isalnum(s[j])))//
			{
				if (s[i] == s[j] || s[i] - 32 == s[j] || s[i] + 32 == s[j])
				{
					i++;
					j--;
				}
				else if (!isalpha(s[i]) || !isalpha(s[j]))
				{
					if (!isalpha(s[i]))
					{
						i++;
					}
					if (!isalpha(s[j]))
					{
						j--;
					}
				}
			}
			else
			{
				return false;
			}
		}
		return true;
	}
};

int main()
{
	Solution s;
	cout<<s.isPalindrome("0P");
    system("pause");
    return 0;
}