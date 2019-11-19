#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main1()
{
	int sum = 0, sign = 0;
	int i = 0;
	int flag = 0;
	string str;
	vector<string> tmp;
	getline(cin, str);

	while (str[i] == ' '&& i < str.size())//找到第一个非空格
	{
		i++;
	}

	for (; i < str.size(); i++)
	{
		if (str[i] == '"'&& sign == 0)
		{
			sign++;
		}

		else if (str[i] == '"'&& sign == 0)
		{
			sign--;
			sum++;
		}

		else if (str[i] != ' ')
		{
			continue;
		}

		else
		{
			while (str[i] == ' '&& i < str.size())
			{
				i++;
			}
			i--;
			sum++;
		}
	}
	cout << sum << endl;
	system("pause");
	return 0;
}