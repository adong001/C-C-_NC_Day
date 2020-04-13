#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<set>
#include<vector>
#include<string>

std::set<std::string> GetNumber(std::vector<std::string>& vs)
{
	int len = vs.size();
	std::set<std::string> vss;
	std::string table = "22233344455566677778889999";
	for (int i = 0; i < len;++i)
	{
		std::string res;
		for (int j = 0; j < vs[i].size();++j)
		{
			if (res.size() == 3)
			{
				res += '-';
			}
			if (vs[i][j] == '-')
			{
				if (res.size() == 4)
				{
					continue;
				}
			}

			else if ('A' <= vs[i][j] && vs[i][j] <= 'Z')//字母装换为相应的数字
			{
				res += table[vs[i][j] - 'A'];
			}
			else if ('0' <= vs[i][j] && vs[i][j] <= '9')//数字不变
			{
				res += vs[i][j];
			}
			
		}
		vss.insert(res);//将这个号码插入set，去重
	}
	return vss;
}

int main2()
{
	int n;
	while (std::cin >> n)
	{
		std::vector<std::string> vs(n);
		for (int i = 0; i < n; i++)
		{
			std::cin >> vs[i];

		}
		std::set<std::string> ss = GetNumber(vs);
		for (auto& e : ss)
		{
			std::cout << e << std::endl;
		}
		std::cout << std::endl;
	}
    return 0;
}