#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;


class Finder {
public:

	int BinaryFind(vector<int>& A, int x)
	{
		//���ݣ�5, 6, 1, 2, 3, 4,(5, 6)  //�����5��6������ģ�ֻ������ת��ʱʹ�ã�������ֵʱģsize�õ���ʵ����
		//���꣺0, 1��2��3, 4��5,(6��7)
		int pos = FindMutantPos(A);
		int size = A.size();
		int right = pos + size - 1;//right = 7
		int left = pos;            //left = 1  //�൱���ڶ��ֲ���
		int mid; 
		while (left<= right)
		{
			mid = (left  + right) / 2;
			if (A[mid % size] == x)//���ʱ��ģ�ķ����ҵ�ʵ�ʵ�����  1,2,3,4,ģsize�����Լ���ʵ�����꣬5,6ģsize�͵õ���0��1����ʵ����
			{  
				return mid % size;
			}
			else if (A[mid % size] > x)
			{
				right = mid - 1;
			}
			else
			{
				left = mid + 1;
			}
		}
		return -1;
	}


	int FindMutantPos(vector<int>& A)//���������ͻ��㣬����{5��6, 1, 2, 3, 4}ͻ���Ϊ1������1������2
	{
		int size = A.size();
		int left = 0;
		int right = size - 1;
		int mid = (left + right) / 2;
		while (mid != right && mid != left)
		{
			if (A[mid] > A[left])
			{
				left = mid;
			}
			else
			{
				right = mid;
			}
			mid = (left + right) / 2;
		}
		return (mid == size-1) ? 0 : mid + 1;
	}

	int FindElement(vector<int> A, int x)
	{
		if (A.empty())
		{
			return -1;
		}
		return BinaryFind(A, x);
	}

};
int main2()
{//  6 9 11 45 1 4
	Finder test;
	vector<int> v = { 5, 6, 1, 2, 3, 4 };
	cout<<test.FindElement(v, 6)<<endl;
    system("pause");
    return 0;
}