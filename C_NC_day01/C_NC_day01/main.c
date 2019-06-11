#define _CRT_SECURE_NO_WARNINGS 1
#define SIZEOF(a)  sizeof(a)/sizeof(a[0])
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//1. 打印100~200之间的素数
int main()
{
	int i, j;
	for (i = 100; i <= 200; ++i)
	{
		for (j = 2; j <= sqrt(i); ++j)
		{
			if (i%j == 0)
			{
				break;
			}
		}
		if (j > sqrt(i))
		{
			printf("%d ", i);
		}
	}
	system("pause");
	return 0;
}
//2. 输出乘法口诀表
int main()
{
	for (int i = 1; i <= 9; ++i)
	{
		for (int j = 1; j <= i; ++j)
		{
			printf("%d*%d=%2d ", i, j, i*j);
		}
		printf("\n");
	}
	system("pause");
	return 0;
}
	
//3. 判断1000年-- - 2000年之间的闰年

int main()
{
	int year;
	for (year = 1000; year <= 2000; ++year)
	{
		if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
		{
			printf("%d ", year);
		}
	}
	system("pause");
	return 0;
}