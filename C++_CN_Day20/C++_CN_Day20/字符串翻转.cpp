#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>¡¢
#include<string>
using namespace std;

int main1()
{
	string src;
	while (cin >> src)
	{
		int size = src.size();
		for (int i = 0; i < size / 2; i++)
		{
			swap(src[i],src[size - i -1]);
		}
		cout << src;
	}
    system("pause");
    return 0;
}