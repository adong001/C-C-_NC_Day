#define _CRT_SECURE_NO_WARNINGS 1
#define SIZEOF(a)  sizeof(a)/sizeof(a[0])
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//1.实现一个函数，打印乘法口诀表，口诀表的行数和列数自己指定，
//输入9，输出9 * 9口诀表，输入12，输出12 * 12的乘法口诀表。

//void PrintMult(int n)
//{
//	for (int i = 1; i <= n; ++i)
//	{
//		for (int j = 1; j <= i; ++j)
//		{
//			printf("%2d*%d=%-3d ", i, j, i*j);
//		}
//		printf("\n");
//	}
//}
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	PrintMult(n);
//	system("pause");
//	return 0;
//}

//2.使用函数实现两个数的交换。
//
//void swap(int *x, int *y)
//{
//	int tmp = *x;
//	*x = *y;
//	*y = tmp;
//}
//int main()
//{
//	int x = 10;
//	int y = 20;
//	swap(&x, &y);
//	printf("x=%d y=%d\n", x, y);
//	system("pause");
//	return 0;
//}
//3.实现一个函数判断year是不是润年。
//int Is_leap(int year)
//{
//	return ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
//}
//int main()
//{
//	int year;
//	scanf("%d", &year);
//	if (Is_leap(year))
//	{
//		printf("是闰年\n");
//	}
//	else
//	{
//		printf("不是闰年\n");
//	}
//	system("pause");
//	return 0;
//}
//4.
//创建一个数组，
//实现函数init（）初始化数组、
//实现empty（）清空数组、
//实现reverse（）函数完成数组元素的逆置。
////要求：自己设计函数的参数，返回值。
//void Init(int ar[], int n)
//{
//	for (int i = 0; i < n; ++i)
//	{
//		ar[i] = 0;
//	}
//}
//void empty(int ar[], int n)
//{
//	for (int i = 0; i < n; ++i)
//	{
//		ar[i] = 0;
//	}
//}
//void reverse(int ar[], int n)
//{
//	for (int i = 0; i < n/2; ++i)
//	{
//		int tmp = ar[i];
//		ar[i] = ar[n - i - 1];
//		ar[n - i - 1] = ar[i];
//	}
//}
//
//int main()
//{
//	int ar[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//    system("pause");
//    return 0;
//}
//5.实现一个函数，判断一个数是不是素数。
//
//int Is_Prime(int n)
//{
//	int i;
//	if (n <= 1)
//	{
//		return 0;
//	}
//	for (i = 2; i <= sqrt(n); ++i)
//	{
//		if (n%i == 0)
//		{
//			return 0;
//		}
//	}
//	if (i > sqrt(n))
//	{
//		return 1;
//	}
//}
//int main()
//{
//	while (1)
//	{
//		int n;
//		scanf("%d",&n);
//		printf("%d\n", Is_Prime(n));
//
//	}
//    system("pause");
//    return 0;
//}