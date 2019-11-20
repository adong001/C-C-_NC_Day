#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;
#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;

int main1()
{
	string src;
	bool flag = false;
	char hs[256] = { 0 };
	while (cin >> src)
	{
		for (auto& ch : src)
		{
			hs[ch]++;
		}
		for (auto& ch : src)
		{
			if (hs[ch] == 1)
			{
				flag = true;
				cout << ch << endl;
				break;
			}
		}
		if (!flag)
		{
			cout << -1 << endl;
		}
	}
	return 0;
}
