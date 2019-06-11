#define _CRT_SECURE_NO_WARNINGS 1
#define SIZEOF(a)  sizeof(a)/sizeof(a[0])
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
//1.在屏幕上输出以下图案：
//*
//***
//*****
//*******
//*********
//***********
//*************
//***********
//*********
//*******
//*****
//***
//*
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	for (int i = 1 ; i <= n; ++i)
//	{
//		for (int j = 1; j <= 2 * i - 1; ++j)
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//	for (int i = n-1; i >= 1; --i)
//	{
//		for (int j = 1; j <= 2 * i - 1; ++j)
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//	system("pause");
//	return 0;
//}
//
//2.求出0～999之间的所有“水仙花数”并输出。
//“水仙花数”是指一个三位数，其各位数字的立方和确好等于该数本身，
//如；153＝1＋5＋3 ? ，则153是一个“水仙花数”。
//int main()
//{
//	for (int i = 0; i < 1000; ++i)
//	{
//		int x = i / 100;
//		int y = i % 100 / 10;
//		int z = i % 100 % 10;
//		if (i == pow(x,3) +pow(y,3) +pow(z,3))
//		{
//			printf("%d ", i);
//		}
//	}
//  system("pause");
//  return 0;
//}

//3.
//求Sn = a + aa + aaa + aaaa + aaaaa的前5项之和，其中a是一个数字，
//例如：2 + 22 + 222 + 2222 + 22222
int main()
{
	int sum = 0;
	int n;
	int num;
	int tmp = 0,ret;
	scanf("%d%d", &num, &n);
	for (int i = 0; i < n; ++i)
	{
		ret = tmp*10+num; 
		tmp = ret;                
		sum += ret;               
	}
	printf("sum=%d", sum);
    system("pause");
    return 0;
}