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
//void Sort(int *ar, int size)//ð��
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
//void InsertSort(int *ar, int size)//ֱ�Ӳ�������
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
//void ShellSort(int *ar, int size)//ϣ������
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
//void MergeSort(int *ar, int size)//�鲢����
//{
//	int *tmp = (int *)malloc(sizeof(int)*size);
//	DealMergeSort(ar, tmp, 0, size - 1);
//	free(tmp);
//}
//
//void DealMergeSort(int *ar, int *tmp, int start, int end)//�鲢������Ҫ�����µĿռ䣬��һ����������װ����
//{
//	if (start >= end)//ÿ��ֻʣһ��Ԫ�أ��ֽ����
//	{
//		return;
//	}
//	int mid = (start + end) / 2;
//	DealMergeSort(ar, tmp, start, mid);//�ݹ鴦����������
//	DealMergeSort(ar, tmp, mid+1, end);
//	int a = start;//�����Ԫ��
//	int b = mid + 1;//�ұ���Ԫ��
//	int c = start;
//	while (a <= mid && b <= end)//��ֹa,bԽ��
//	{
//		if (ar[a] < ar[b])//˭��ֵС��ֵ��tmp
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
//	for (; a <= mid; a++, c++)//�϶�����һ���ȸ�ֵ�����������һ������ȫ����ֵ��tmp
//	{
//		tmp[c] = ar[a];
//	}
//	for (; b <= end; b++, c++)
//	{
//		tmp[c] = ar[b];
//	}
//	for (int i = start; i <= end; i++)//�����¿ռ��������Ԫ�ػظ���ar,�������
//	{
//		ar[i] = tmp[i];
//	}
//}
//
//int HoareSort(int *ar, int start, int end)//hoare��
//{
//	int a = start + 1, b = end - 2;
//	int mid = (start + end) / 2;
//	if (ar[start] > ar[mid])//ð��ʹstart mid end ����
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
//	if (end - start <= 2)//�������������źã�ֱ������
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
