#define _CRT_SECURE_NO_WARNINGS 1
#define SIZEOF(a)  sizeof(a)/sizeof(a[0])
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//1.ʵ��һ����������ӡ�˷��ھ����ھ���������������Լ�ָ����
//����9�����9 * 9�ھ�������12�����12 * 12�ĳ˷��ھ���

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

//2.ʹ�ú���ʵ���������Ľ�����
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
//3.ʵ��һ�������ж�year�ǲ������ꡣ
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
//		printf("������\n");
//	}
//	else
//	{
//		printf("��������\n");
//	}
//	system("pause");
//	return 0;
//}
//4.
//����һ�����飬
//ʵ�ֺ���init������ʼ�����顢
//ʵ��empty����������顢
//ʵ��reverse���������������Ԫ�ص����á�
////Ҫ���Լ���ƺ����Ĳ���������ֵ��
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
//5.ʵ��һ���������ж�һ�����ǲ���������
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