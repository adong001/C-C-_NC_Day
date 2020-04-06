#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
int main2()
{
	int n, count = 0, Max = 0;
	while (std::cin >> n)
	{
		int count = 0, Max = 0;
		std::string s1, s2;
		while (n--)
		{
			std::cin >> s1 >> s2;
			if (s2 == "connect")
			{
				count++;
			}
			else
			{
				count--;
			}
			if (Max < count)
			{
				Max++;
			}
		}
		std::cout << Max << std::endl;
	}
	return 0;
}