#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>

int main2()
{
	std::string s;
	while (std::cin >> s)
	{
		int i;
		int len = s.size();
		std::string res;
		for (i = 0; i < len && s[i] != '_'; i++)//获取首个单词
		{
			res += s[i];
		}
		for (; i < len; i++)
		{
			if (s[i] != '_')
			{
				if (s[i - 1] == '_')
				{
					res += (s[i] - 32);
				}
				else
				{
					res += s[i];
				}
			}
		}
		std::cout << res << std::endl;
	}
	return 0;
}