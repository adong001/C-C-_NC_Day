#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

int func(int a, int b)
{
	if (a == b)
	{
		return a;
	}
	else
	{
		return ((a + b) / 2);
	}
}


int main22()
{
	//int a = 4, b = 5, c = 6;
	/*int i = 0;
	int a[] = { 1, 2, 3, 4 };
	int* p = a;
	for (; i < 4; i++)
	{
		a[i] = *p++;
	}*/
	//cout << a[2];

	//printf("%d\n", func(2 * a, func(b, c)));
    system("pause");
    return 0;
}