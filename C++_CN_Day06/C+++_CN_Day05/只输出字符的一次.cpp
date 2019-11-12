#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;

void DeleteSameString2()//只能查找字母
{
	int B_word = 0;
	int L_word = 0;
	string src;
	string tmp;
	getline(cin, src);
	if (src.empty())
	{
		return;
	}
	for (auto& ch : src)
	{
		if ('a' <= ch&&ch <= 'z')
		{
			if (((B_word>>(ch-'a')) & 1) == 0)//记录的那一位为0，则说明之前未出现过
			{
				tmp += ch;
			}
			B_word |= (1 << (ch - 'a'));
		}
		else if ('A' <= ch&&ch <= 'Z')
		{
			if (((L_word >> (ch - 'A')) & 1) == 0)//记录的那一位为0，则说明之前未出现过
			{
				tmp += ch;
			}
			L_word |= (1 << (ch - 'A'));
		}
	}
	cout << tmp << endl;
}

void DeleteSameString()
{
	string src;
	char hx[256] = {};
	getline(cin, src);

	if (src.empty())
	{
		return;
	}
	for (int i = 0; i < src.size(); i++)
	{
		if (hx[src[i]] == 0)
		{
			hx[src[i]] = 1;
			cout<<src[i];
		}
	}
	cout<< endl;
}

int main3()
{
	//DeleteSameString();
	DeleteSameString2();
	system("pause");
	return 0;
}

