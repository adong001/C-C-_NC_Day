#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;

int main2()
{
	string src;
	while (cin >> src)
	{
		int num = 0;
		for (auto& ch : src)
		{
			num += ch - '0';
		}
		while (num / 10)
		{
			int tmp = 0;
			while (num)
			{
				tmp += num % 10;
				num /= 10;
			}
			num = tmp;
		}
		cout << num<<endl;
	}
    system("pause");
    return 0;
}