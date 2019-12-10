#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;

int main2()
{
	string src;
	while (getline(cin ,src))
	{
		for (auto& ch : src)
		{
			if ('A' <= ch && ch <= 'E')
			{
				ch += 21;
			}
			else if ('E' < ch && ch <= 'Z')
			{
				ch -= 5;
			}
			else
			{
				//do nothing
			}
		}
		cout << src << endl;
	}
    system("pause");
    return 0;
}