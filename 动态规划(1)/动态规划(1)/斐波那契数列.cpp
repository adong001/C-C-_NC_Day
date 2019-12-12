#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//大家都知道斐波那契数列，现在要求输入一个整数n，
//请你输出斐波那契数列的第n项（从0开始，第0项为0）。
//n <= 39

class Solution 
{
public:
	int Fibonacci(int n) 
	{
		int fn = 1,fn_1 = 1, fn_2 = 1;
		if (n <= 0)
		{
			return 0;
		}
		if (n == 1 || n == 2)
		{
			return 1;
		}
		for (int i = 3; i <= n; i++)
		{
			fn_2 = fn_1;
			fn_1 = fn;
			fn = fn_1 + fn_2;
		}
		return fn;
	}
};

int main1()
{
	Solution t;
	cout << t.Fibonacci(5) << endl;
    system("pause");
    return 0;
}