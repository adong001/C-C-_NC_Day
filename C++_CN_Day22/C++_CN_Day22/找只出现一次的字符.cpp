#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;

int main2()
{
	string s;
	char hs[256] = { 0 };
	bool flag = false;
	while (cin >> s)
	{
		for (auto& ch : s)
		{
			hs[ch]++;
		}
		for (auto& ch : s)
		{
			if (hs[ch] == 1)
			{
				cout << ch << endl;
				flag = true;
				break;
			}
		}
		if (flag == false)
		{
			cout << -1 << endl;
		}
	}
    system("pause");
    return 0;
}