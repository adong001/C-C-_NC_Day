#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
void reverse(std::string& s, int start, int end)
{
	while (start < end)
	{
		char tmp = s[start];
		s[start] = s[end];
		s[end] = tmp;
		start++;
		end--;
	};
}

int main()
{
	std::string s;
	while (std::getline(std::cin, s))
	{
		int len = s.size();
		int pos,i,j;
		std::string res;
		for (i = 0; i < len && !isalpha(s[i]); ++i);//跳过开头的空格
		for (; i < len; i++)
		{
			for (; i < len && !isalpha(s[i]); ++i);//跳过空格
			pos = i;
			for (; i < len && isalpha(s[i]); ++i);//找到单词末尾
			std::reverse(s.begin() + pos, s.begin() + i);
			//reverse(s, pos, i - 1);//翻转单词
			res.insert(res.begin()+ res.size(),s.begin() + pos, s.begin() + i);
			for (j = i; j < len && !isalpha(s[j]); ++j);//跳过空格
			if (j != len)
			{
				res += ' ';
			}
		}
		std::reverse(res.begin(), res.end());
		//reverse(res, 0, res.size()-1);
		std::cout << res << std::endl;
	}
    return 0;
}