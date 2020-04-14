#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<map>
#include<string>

int main()
{
	std::string A, B;
	bool flag = false;
	while (std::cin >> A >> B)
	{
		if (A.size() < B.size())
		{
			std::cout << "No" << std::endl;
		}
		
		else
		{
			std::map<char, int> ma;
			std::map<char, int> mb;
			for (auto& e : A)
			{
				if (ma.insert(std::pair<char, int>(e, 1)).second == false)
				{
					ma[e]++;
				}
			}

			for (auto& e : B)
			{
				if (mb.insert(std::pair<char, int>(e, 1)).second == false)
				{
					mb[e]++;
				}
			}
			for (auto& e : mb)
			{
				if ((ma.find(e.first) != ma.end()) && (ma[e.first] >= mb[e.first]))
				{
					continue;
				}
				else
				{
					flag = true;
					break;
				}
			}
			if (flag)
			{
				std::cout << "No" << std::endl;
			}
			else
			{
				std::cout << "Yes" << std::endl;
			}
		}
	}
    return 0;
}