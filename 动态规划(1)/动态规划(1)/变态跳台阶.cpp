#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;


//一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。
//求该青蛙跳上一个n级的台阶总共有多少种跳法。
//跳1阶，剩下n-1阶, 剩下跳法是f(n-1)
//跳2阶，剩下n-2阶，剩下跳法是f(n-2)
//.......
//跳n阶，剩下n-n阶，剩下跳法是f(0)
//
//f(n) = f(n - 1) + f(n - 2) + .......f(0)
//f(n - 1) = f(n - 2) + f(n - 3) + .......f(0)
//.......
//-->动态方程：f(n) = 2 * f(n - 1);
//
//
//下面使用数学归纳法列举一下
//初值:f(1) = 1;
//	 f(2) = 2*f(1) = 2
//	 f(3) = 2 * f(2) = 4
//	 f(4) = 2 * f(3) = 8
//	 ........
//-->终极表达式:f(n) = 2^(n-1)

class Solution {
public:
	//方法一:
	int jumpFloorII(int number)
	{
		int fn = 1,fn_1;
		if (number <= 0)
		{
			return 0;
		}
		for (int i = 2; i <= number; i++)
		{
			fn_1 = fn;
			fn = 2 * fn_1;
		}
		return fn;
	}
	int jumpFloorII2(int number)
	{
		return 1 << (number - 1);
	}
};

int main2()
{
    system("pause");
    return 0;
}