#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;

int main1()
{
	string src, dest;
	char str[256] = {};
	string tmp;
	int i;
	while (getline(cin, src) && getline(cin, dest))
	{
		if (src.empty() || dest.empty())
		{
			return 0;
		}
		int len1 = src.size();
		int len2 = dest.size();
		for (auto& ch : dest)
		{
			str[ch]++;
		}
		for (auto& ch : src)
		{
			if (str[ch] == 0)
			{
				tmp += ch;
			}
		}
		cout << tmp << endl;
	}
	system("pause");
	return 0;
}