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
		for (i = 0; i < len && !isalpha(s[i]); ++i);//������ͷ�Ŀո�
		for (; i < len; i++)
		{
			for (; i < len && !isalpha(s[i]); ++i);//�����ո�
			pos = i;
			for (; i < len && isalpha(s[i]); ++i);//�ҵ�����ĩβ
			std::reverse(s.begin() + pos, s.begin() + i);
			//reverse(s, pos, i - 1);//��ת����
			res.insert(res.begin()+ res.size(),s.begin() + pos, s.begin() + i);
			for (j = i; j < len && !isalpha(s[j]); ++j);//�����ո�
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