//#include"Sort.h"
//
//void Swap(int *a, int *b)
//{
//	int tmp = *a;
//	*a = *b;
//	*b = tmp;
//}
//
//void Print(int *ar, int n)
//{
//	for (auto i : ar)
//	{
//		cout << i;
//	}
//	cout << endl;
//}
//void Print(float *ar, int n)
//{
//	for (auto i : ar)
//	{
//		cout << i;
//	}
//	cout << endl;
//}
//
//void Sort(int *ar, int size)//冒泡
//{
//	int i, j, tmp;
//	for (i = 0; i < size - 1; i++)
//	{
//		for (j = 0; j < size - i - 1; j++)
//		{
//			if (ar[j]>ar[j + 1])
//			{
//				tmp = ar[j];
//				ar[j] = ar[j + 1];
//				ar[j + 1] = tmp;
//			}
//		}
//	}
//}
//
//void Sort(float *ar, int size)
//{
//	int i, j;
//	float tmp;
//	for (i = 0; i < size - 1; i++)
//	{
//		for (j = 0; j < size - i - 1; j++)
//		{
//			if (ar[j]>ar[j + 1])
//			{
//				tmp = ar[j];
//				ar[j] = ar[j + 1];
//				ar[j + 1] = tmp;
//			}
//		}
//	}
//}
//
//void Test1()
//{
//	int ar1[] = { 2, 3, 7, 1, 0, 4, 6, 8, 5, 9 };
//	float ar2[] = { 9.3, 7.67, 2.45, 1.90, 3.45, 8.98, 6.23, 4.5, 5.7 };
//	int n = sizeof(ar1) / sizeof(ar1[0]);
//	int m = sizeof(ar2) / sizeof(ar2[0]);
//	Sort(ar1, n);
//	Print(ar1, n);
//	Sort(ar2, m);
//	Print(ar2, m);
//}
//void InsertSort(int *ar, int size)//直接插入排序
//{
//	int i, j;
//	int tmp;
//	for (i = 1; i < size; i++)
//	{
//		tmp = ar[i];
//		for (j = i; j > 0 && tmp < ar[j-1]; j--)
//		{
//			ar[j] = ar[j - 1];
//		}
//		ar[j] = tmp;
//	}
//}
////
//void ShellSort(int *ar, int size)//希尔排序
//{
//	int gap, k, i, j, tmp;
//	for (gap = size / 2; gap > 0; gap /= 2)
//	{
//		for (k = 0; k < gap; k++)
//		{
//			for (i = gap + k; i < size; i += gap)
//			{
//				tmp = ar[i];
//				for (j = i; j > 0 && tmp < ar[j - gap]; j -= gap)
//				{
//					ar[j] = ar[j - gap];
//				}
//				ar[j] = tmp;
//			}
//		}
//	}
//}
////
//void MergeSort(int *ar, int size)//归并排序
//{
//	int *tmp = (int *)malloc(sizeof(int)*size);
//	DealMergeSort(ar, tmp, 0, size - 1);
//	free(tmp);
//}
//
//void DealMergeSort(int *ar, int *tmp, int start, int end)//归并排序需要开辟新的空间，做一个处理函数封装起来
//{
//	if (start >= end)//每组只剩一个元素，分解结束
//	{
//		return;
//	}
//	int mid = (start + end) / 2;
//	DealMergeSort(ar, tmp, start, mid);//递归处理左右子树
//	DealMergeSort(ar, tmp, mid+1, end);
//	int a = start;//左边首元素
//	int b = mid + 1;//右边首元素
//	int c = start;
//	while (a <= mid && b <= end)//防止a,b越界
//	{
//		if (ar[a] < ar[b])//谁的值小赋值给tmp
//		{
//			tmp[c] = ar[a];
//			a++;
//			c++;
//		}
//		else
//		{
//			tmp[c] = ar[b];
//			b++;
//			c++;
//		}
//	}
//	for (; a <= mid; a++, c++)//肯定会有一个先赋值结束，则把另一个依次全部赋值给tmp
//	{
//		tmp[c] = ar[a];
//	}
//	for (; b <= end; b++, c++)
//	{
//		tmp[c] = ar[b];
//	}
//	for (int i = start; i <= end; i++)//最后把新空间里的有序元素回赋给ar,排序结束
//	{
//		ar[i] = tmp[i];
//	}
//}
//
//int HoareSort(int *ar, int start, int end)//hoare法
//{
//	int a = start + 1, b = end - 2;
//	int mid = (start + end) / 2;
//	if (ar[start] > ar[mid])//冒泡使start mid end 有序
//	{
//		Swap(&ar[start], &ar[mid]);
//	}
//	if (ar[mid] > ar[end])
//	{
//		Swap(&ar[mid], &ar[end]);
//	}
//	if (ar[start] > ar[mid])
//	{
//		Swap(&ar[start], &ar[mid]);
//	}
//	if (end - start <= 2)//三个数以内已排好，直接跳出
//	{
//		return mid;
//	}
//	Swap(&ar[mid], &ar[end - 1]);
//	while (a < b)
//	{
//
//		while (a < end - 1 && ar[a] < ar[end - 1])
//		{
//			a++;
//		}
//		while (b > 1 && ar[b] > ar[end - 1])
//		{
//			b--;
//		}
//		if (a == b && (a == 1 || b == end - 1))
//		{
//			break;
//		}
//		if (a < b)
//		{
//			Swap(&ar[a], &ar[b]);
//		}
//
//	}
//	Swap(&ar[a], &ar[end - 1]);
//	return a;
//}
//
//
//
//void DealQuickSort(int *ar, int start, int end)
//{
//	int mid;
//	if (start < end)
//	{
//		mid = HoareSort(ar, start, end);
//		DealQuickSort(ar, start, mid - 1);
//		DealQuickSort(ar, mid + 1, end);
//	}
//}
//
//void QuickSort(int *ar, int size)
//{
//	DealQuickSort(ar, 0, size - 1);
//}
//
//void Sort2(int *ar, int size, int flag = 0)
//{
//	switch (flag)
//	{
//	case 0:InsertSort(ar, size); break;
//	case 1:ShellSort(ar, size); break;
//	case 2:MergeSort(ar, size); break;
//	case 3:QuickSort(ar, size); break;
//	default:break;
//	}
//}
//
//void Test2()
//{
//	int ar[] = { 2, 3, 7, 1, 0, 4, 6, 8, 5, 9 };
//	int n = sizeof(ar) / sizeof(ar[0]);
//	Sort2(ar, n,3);
//	Print(ar, n);
//}
//
