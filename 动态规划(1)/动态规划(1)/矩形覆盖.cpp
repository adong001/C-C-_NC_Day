#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//我们可以用2 * 1的小矩形横着或者竖着去覆盖更大的矩形。
//请问用n个2 * 1的小矩形无重叠地覆盖一个2 * n的大矩形，总共有多少种方法？

class Solution {
public:
	int rectCover(int number)
	{
		int fn = 1, fn_1 = 1, fn_2 = 1;
		if (number <= 0)
		{
			return 0;
		}
		if (number == 1)
		{
			return 1;
		}
		for (int i = 2; i <= number; i++)
		{
			fn_2 = fn_1;
			fn_1 = fn;
			fn = fn_1 + fn_2;
		}
		return fn;
	}
};
int main()
{
    system("pause");
    return 0;
}