#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;


//��1,2,3...n�ĵ��������飬�������㷨������Ҫʹʱ�临�Ӷ�ΪO(n),
//�ռ临�Ӷ�ΪO(1),ʹ�ý���������ֻ��һ�ν���������
void sort(int*ar, int n)
{
	int tmp,i;
	for (i = 0; i < n; i++)
	{
		while (ar[i] != i + 1)//˳��һ����ar[i] = i+1,
		{
			tmp = ar[ar[i]-1];//�����Ȼ�ar[ar[i]-1]������ar[i]һ����ar[ar[i]-1]��ֵ�͸��ű���
			ar[ar[i]-1] = ar[i];
			ar[i] = tmp;
		}
	}
}

int main3()
{
	int ar[] = { 10, 4, 8, 1, 3, 9, 2, 7, 6, 5 };
	sort(ar, 10);
	for (auto& i : ar)
	{
		cout << i << " ";
	}
	cout << endl;
    system("pause");
    return 0;
}