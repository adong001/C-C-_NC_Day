#define _CRT_SECURE_NO_WARNINGS 1
#define SIZE(ar)  sizeof(ar)/sizeof(ar[0])
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//1.��������ʹ����ȫ����λ��ż��ǰ�档
////��Ŀ��
////����һ���������飬ʵ��һ��������
////�����������������ֵ�˳��ʹ�����������е�����λ�������ǰ�벿�֣�
////����ż��λ������ĺ�벿�֡�
////
//
//void Swap(int * p1, int * p2)
//{
//
//	int temp = *p1;
//	*p1 = *p2;
//	*p2 = temp;
//}
//void Sort_odd_even(int *ar, int n)
//{
//	int i = 0;
//	int j = n - 1;        
//	while (1)
//	{		
//		if (i >= j)
//		{
//			break;
//		}
//		if (ar[i] % 2 == 1)
//		{
//			i++;
//			continue;  //1 2 3 4 5
//		}
//		else
//		{
//			while (j >= i )
//			{
//				if (ar[j] % 2 == 1)
//				{
//					Swap(&ar[i], &ar[j]);
//					i++;
//					j--;
//					break;
//				}
//				else
//				{
//					j--;
//				}
//			}
//		}
//	}
//}
//void Print(int ar[], int n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		printf("%d ", ar[i]);
//	}
//	printf("\n");
//}
//int main()
//{
//	int ar[] = {1,2,3,4,5,6,7,8,9,10};
//	int n = SIZE(ar);
//	Print(ar, n);
//	Sort_odd_even(ar, n);
//	Print(ar, n);
//	system("pause");
//	return 0;
//}
//2.
////���Ͼ��� 
//��һ����ά����.
//�����ÿ�д������ǵ����ģ�ÿ�д��ϵ����ǵ�����.
//�������������в���һ�������Ƿ���ڡ�
//ʱ�临�Ӷ�С��O(N);
//
//���飺
//1 2 3
//2 3 4
//3 4 5
//
//
//1 3 4
//2 4 5
//4 5 6
//
//1 2 3
//4 5 6
//7 8 9

//
//int FindValue(int ar[3][4], int value, int row, int col)
//{
//	int i = 0;
//	int j = col - 1;
//	while (j >= 0 && i < row)
//	{
//		if (ar[i][j] < value) //˵����һ�ж���ValueС,������һ��
//		{
//			i++;
//		}
//		else if (ar[i][j] > value)//˵����һ�ж���ValueС, ����s��һ��
//		{
//			j--;
//		}
//		else   //�ҵ���
//		{
//			return 1;
//		}
//	}
//	return 0;  //û�ҵ�
//}
//int main()
//{
//	int ar[3][4] = { { 1, 3, 5, 7 },
//	                 { 3, 5, 7, 9 },
//	                 { 5, 7, 9, 11 } };
//	if (FindValue(ar, 11, 3, 4))
//	{
//		printf("�ҵ���\n");
//	}
//	else
//	{
//		printf("û�ҵ�\n");
//	}
//	system("pause");
//	return 0;
//}


