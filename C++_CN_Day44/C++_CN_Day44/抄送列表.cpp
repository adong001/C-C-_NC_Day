#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<vector>

int main()
{
	std::string src, det;
	std::getline(std::cin,src);
	std::getline(std::cin, det);
	std::vector<std::string> v;
	int k = 0;
	for (int i = 0; i < src.size();i++)
	{
		v.push_back(std::string());
		if (src[i] == '"')
		{
			i++;	
			while (src[i] != '"')
			{
				v[k] += src[i];
				i++;
			}
			i++;
			k++;
		}
		else
		{
			while (src[i] != ',')
			{
				v[k] += src[i];
				i++;
			}
			k++;
		}
	}
	if (find(v.begin(), v.end(), det) == v.end())
	{
		std::cout << "Important!" << std::endl;
	}
	else
	{
		std::cout << "Ignore!" << std::endl;
	}
	return 0;
}