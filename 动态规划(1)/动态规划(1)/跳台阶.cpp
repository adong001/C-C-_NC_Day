#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

int jumpFloor(int number)
{
	int i, sum = 0;
	if (number <= 1)
	{
		return 1;
	}
	for (i = 2; i > 0; i--)
	{
		number--;
		if (number < 0)
		{
			break;
		}
		sum += jumpFloor(number);
	}
	return sum;
}
int main3()
{
	system("pause");
	return 0;
}