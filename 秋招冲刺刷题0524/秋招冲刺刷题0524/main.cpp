#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

int main()
{
	short a = 0xff00;
	char* b = (char*)&a;
	if (*b == 0xff)
	{
		cout << "���" << endl;
	}
	else
	{
		cout << "С��" << endl;
	}
	union un
	{
		char a;
		short b;
	};
	un u;
	u.b = 0xff00;
	
	if (u.a == 0xff)
	{
		cout << "���" << endl;
	}
	else
	{
		cout << "С��" << endl;
	}
    return 0;
}