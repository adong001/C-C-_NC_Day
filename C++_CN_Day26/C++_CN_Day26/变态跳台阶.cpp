#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;


class Solution {
public:
	int jumpFloorII(int number)
	{
		int sum = 0;
		if (number <= 1)
		{
			return 1;
		}
		else
		{
			while (number--)
			{
				sum += jumpFloorII(number);
			}
			return sum;
		}
	}
};

int main()
{

    system("pause");
    return 0;
}