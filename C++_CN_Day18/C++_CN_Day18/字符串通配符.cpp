#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<cstring>
using namespace std;

int main2()
{
	string src;
	string dest;
	while (getline(cin, src), getline(cin, dest))
	{
		int i,j;//i是src的下标,j是dest的下标
		for (i = 0,j = 0; j < dest.size() && i<src.size(); i++,j++)
		{//te?t*.*
		 //tett2sawW.xls
			if (src[i] == dest[j] || src[i] == '?')
			{
				continue;
			}
			else if (src[i] == '*' && i+1 < src.size())
			{
				for (; j < dest.size() && src[i + 1] != dest[j] && isalnum(dest[j]); j++);
				i++;
				if (src[i] != dest[j])
				{
					return false;
				}
				i--;
				j--;
			}
			else
			{
				return false;
			}
		}
		return true;
	}
    system("pause");
    return 0;
}



#include <iostream>
#include <string>
using namespace std;

bool match(const char* pattern, const char *str)
{
	if (*pattern == '\0' && *str == '\0')
		return true;
	if (*pattern == '\0' || *str == '\0')
		return false;

	if (*pattern == '?')
	{
		return match(pattern + 1, str + 1);
	}
	else if (*pattern == '*')
	{
		// 匹配0个1个或多个   *\0 和\0（匹配0个） *\0 和 x\0（匹配一个） *和x\0匹配多个
		return match(pattern + 1, str) || match(pattern + 1, str + 1) || match(pattern, str + 1);
	}
	else if (*pattern == *str)
	{
		return match(pattern + 1, str + 1);
	}

	return false;
}
int main(void)
{
	string pattern, str;
	while (cin >> pattern >> str)
	{
		bool ret = match(pattern.c_str(), str.c_str());
		if (ret)
			cout << "true" << endl;
		else
			cout << "false" << endl;
	}
	return 0;
}



#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str1, str2;

	while (cin >> str1 >> str2)
	{
		int i = 0, j = 0;
		int b = i - 1;

		int flag = 1;
		for (; j < str2.length(); j++)
		{
			if (str2[j] == str1[i] || str1[i] == '?')
			{
				i++;
				continue;
			}
			else if (str1[i] == '*')
			{
				i++;
				continue;
			}
			else if (b >= 0 && str1[b] == '*')
			{
				continue;
			}
			else
			{
				cout << "false" << endl;
				flag = 0;
				break;
			}
		}
		if (flag == 1)
			cout << "true" << endl;
	}
	return 0;
}