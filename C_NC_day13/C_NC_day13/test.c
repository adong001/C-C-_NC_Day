#define _CRT_SECURE_NO_WARNINGS 1
#define SIZE(ar)  sizeof(ar)/sizeof(ar[0])
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//1.调整数组使奇数全部都位于偶数前面。
////题目：
////输入一个整数数组，实现一个函数，
////来调整该数组中数字的顺序使得数组中所有的奇数位于数组的前半部分，
////所有偶数位于数组的后半部分。
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
////杨氏矩阵 
//有一个二维数组.
//数组的每行从左到右是递增的，每列从上到下是递增的.
//在这样的数组中查找一个数字是否存在。
//时间复杂度小于O(N);
//
//数组：
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
//		if (ar[i][j] < value) //说明这一行都比Value小,跳到下一行
//		{
//			i++;
//		}
//		else if (ar[i][j] > value)//说明这一行都比Value小, 跳到s上一列
//		{
//			j--;
//		}
//		else   //找到了
//		{
//			return 1;
//		}
//	}
//	return 0;  //没找到
//}
//int main()
//{
//	int ar[3][4] = { { 1, 3, 5, 7 },
//	                 { 3, 5, 7, 9 },
//	                 { 5, 7, 9, 11 } };
//	if (FindValue(ar, 11, 3, 4))
//	{
//		printf("找到了\n");
//	}
//	else
//	{
//		printf("没找到\n");
//	}
//	system("pause");
//	return 0;
//}


