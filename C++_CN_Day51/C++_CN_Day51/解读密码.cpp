#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>

int main1()
{
	std::string s;
	while (getline(std::cin, s))
	{
		std::string tmp;
		for (auto& e : s)
		{
			if ('0' <= e && e <= '9')
			{
				tmp += e;
			}
		}
		std::cout << tmp << std::endl;
	}
    return 0;
}