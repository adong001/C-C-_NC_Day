#define _CRT_SECURE_NO_WARNINGS 1
#define SIZEOF(a)  sizeof(a)/sizeof(a[0])
#include<stdio.h>
#include<stdlib.h>

//1. ������A�е����ݺ�����B�е����ݽ��н�����������һ����
//void Change(int ar1[], int ar2[], int n)
//{
//	int tmp;
//	for (int i = 0; i < n; ++i)
//	{
//		tmp = ar1[i];
//		ar1[i] = ar2[i];
//		ar2[i] = tmp;
//	}
//}
//void Print(int ar[], int n)
//{
//	for (int i = 0; i < n; ++i)
//	{
//		printf("%d ", ar[i]);
//	}
//	printf("\n");
//}
//int main()
//{
//	int ar1[] = { 1, 2, 3, 4, 5  };
//	int ar2[] = { 6, 7, 8, 9, 10 };
//	int n = SIZEOF(ar1);
//	Change(ar1, ar2, n);
//	Print(ar1, n);
//	Print(ar2, n);
//	system("pause");
//	return 0;
//}
//2. ����1 / 1 - 1 / 2 + 1 / 3 - 1 / 4 + 1 / 5 ���� + 1 / 99 - 1 / 100 ��ֵ��
//int main()
//{
//	int i;
//	float flag = 1 ;
//	float sum = 0;
//	for (i = 1; i <=100; ++i)
//	{
//		sum += (1.0 / i)*flag;
//		flag = -flag;
//	}
//	printf("sum=%f\n", sum); //ע�⣺���Ϊ%f;
//	system("pause");
//	return 0;
//}
//3. ��д������һ�� 1�� 100 �����������г��ֶ��ٴ�����9��
int main()
{
	int i;
	int count = 0;
	for (i = 1; i < 100; ++i)
	{
		if (i == 9 || i % 10 == 9|| i/10 == 9)
		{
			count++;
			if (i / 10 == 9 && i % 10 == 9 )
			{
				count++;
			}
		}
	}
	printf("count=%d\n", count);
    system("pause");
    return 0;
}