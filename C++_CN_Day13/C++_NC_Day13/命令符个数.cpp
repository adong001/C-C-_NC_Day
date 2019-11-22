#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
	int sum = -1;
	int i = 0;
	string str("   ls \"s cd\" ds  ");
	vector<string> vs;

	//getline(cin, str);

	while(i < str.size())
	{

		if (str[i] == ' ')
		{
			while (str[i] == ' '&& i < str.size())//找到第一个非空格
			{
				i++;
			}
		}

		else if (str[i] == '"')
		{
			sum++;
			i++;
			vs.push_back(string());
			while (str[i] != '"'&& i < str.size())
			{
				vs[sum].push_back(str[i]);
				i++;
			}
			if (str[i - 1] == '"')
			{
				return -1;
			}
			i++;
		}

		else
		{
			sum++;
			vs.push_back(string());
			while (str[i] != ' '&& i < str.size())
			{
				vs[sum].push_back(str[i]);
				i++;
			}
			
		}
	}
	cout << sum + 1 << endl;
	for (auto& ch : vs)
	{
		cout << ch << endl;
	}
	system("pause");
	return 0;
}