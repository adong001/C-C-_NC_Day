#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>

long ErrorEmail(int n)
{
	if (n < 2)
	{
		return 0;
	}
	else if (n == 2)
	{
		return 1;
	}
	else
	{
		return n - 1 * (ErrorEmail(n - 1) + ErrorEmail(n - 2));
	}
}

int main1()
{
	int n;
	while (std::cin >> n)
	{
		std::cout << ErrorEmail(n) << std::endl;
	}
    return 0;
}