#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//1. ���⣺���������� 
//ţţ��������������Ϊһ��������һ��������������, ��������������Ƿǵ������߷ǵݼ�����ġ�
//ţţ��һ ������Ϊn����������A, ��������һ�������ǰ�����A��Ϊ���ɶ�����������, 
//ţţ��֪�������ٿ��԰������ ���Ϊ��������������.
//
//��������ʾ, ţţ���԰�����A����Ϊ[1, 2, 3]��[2, 2, 1]��������������, ������Ҫ����Ϊ2������������, 
//������� 
//
//2.���������� ����ĵ�һ��Ϊһ��������n(1 �� n �� 10 ^ 5)
//�ڶ��а���n������A_i(1 �� A_i �� 10 ^ 9), ��ʾ����A��ÿ�����֡� 
//
//3.��������� ���һ��������ʾţţ���Խ�A���ٻ���Ϊ���ٶ����������� 
//
//4.ʾ��: 
//���� 6 1 2 3 2 2 1   --> 1 1 2 2 2 3
//��� 2

int NUINIU_sort()
{
	int i = 0;
	int count = 0;
	int n;
	vector<int> vres;
	cin >> n;
	vres.resize(n+1);
	for (int i = 0; i < n; i++)
	{
		cin >>vres[i] ;
	}
	while (i < n)
	{
		if (vres[i] < vres[i + 1])
		{
			while (i < n && vres[i] < vres[i + 1])
			{
				i++;
			}
			i++;
			count++;
		}
		else if(i < n && vres[i] == vres[i + 1])
		{
			i++;
		}

		else if (vres[i] > vres[i + 1])
		{
			while (i < n && vres[i] > vres[i + 1])
			{
				i++;
			}
			i++;
			count++;
		}
	}
	return count;
}

int main()
{
	cout << NUINIU_sort() << endl;
    system("pause");
    return 0;
}