#define _CRT_SECURE_NO_WARNINGS 1
#define SIZEOF(a)  sizeof(a)/sizeof(a[0])
#include<stdio.h>
#include<stdlib.h>

//1.递归和非递归分别实现求第n个斐波那契数。
int fib(int n)
{
	int ret;
	while (n > 2)
	{
		ret = fib(n - 1) + fib(n - 2);
	}
	return 1;
}
int main()
{
	printf("%d\n", fib(3));
	system("pause");
	return 0;
}
//
//2.编写一个函数实现n^k，使用递归实现
//int main()
//{
//    system("pause");
//    return 0;
//}
//
//3. 写一个递归函数DigitSum(n)，输入一个非负整数，返回组成它的数字之和，
//例如，调用DigitSum(1729)，则应该返回1 + 7 + 2 + 9，它的和是19
//
//int main()
//{
//    system("pause");
//    return 0;
//}
//4. 编写一个函数 reverse_string(char * string)（递归实现）
//实现：将参数字符串中的字符反向排列。
//要求：不能使用C函数库中的字符串操作函数。
//
//int main()
//{
//    system("pause");
//    return 0;
//}
//5.递归和非递归分别实现strlen
//int main()
//{
//    system("pause");
//    return 0;
//}
//6.递归和非递归分别实现求n的阶乘
//int main()
//{
//    system("pause");
//    return 0;
//}
//7.递归方式实现打印一个整数的每一位
//int main()
//{
//    system("pause");
//    return 0;
//}