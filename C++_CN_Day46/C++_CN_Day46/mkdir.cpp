#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<set>
#include<string>
#include<algorithm>


int main()
{
	int n; 
	while (std::cin >> n)
	{
		std::set<std::string> ss;
		std::string s;
		for (int i = 0; i < n;i++)
		{
			std::cin >> s;
			ss.insert(s);
		} 
		for (auto& it = ss.begin(); it != ss.end();)
		{
			bool flag = true;
			for (auto& it2 = ss.begin(); it2 != ss.end();++it2)
			{
				if (it2->find(*it)!= std::string::npos && it != it2)
				{
					it = ss.erase(it);
					flag = false;
					break;
				}
			}
			flag ? ++it : it;
		}
		for (auto& e : ss)
		{
			std::cout <<"mkdir -p "<< e << std::endl;
		}
	}
    return 0;
}