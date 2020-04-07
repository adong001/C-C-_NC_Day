#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<vector>
#include<cmath>

int main1()
{
	std::string s1, s2;
	int n1, n2;
	while (std::cin >> s1 >> s2 >> n1 >> n2)
	{
		long long tmp = 0;
		std::vector<int> v(n2);
		s1.append(n2 - s1.size(), 'a' - 1);
		s2.append(n2 - s2.size(), 'z' + 1);
		for (int i = 0; i < n2; i++)
		{
			v[i] = s2[i] - s1[i];
		}
		for (int i = n1; i <= n2; i++)
		{
			for (int k = 0; k < i; k++)
			{
				tmp += v[k] * pow(26, i - k - 1);
			}
		}
		std::cout << tmp % 1000007 - 1<< std::endl;
	}
    return 0;
}