#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
	void oddInOddEvenInEven(vector<int>& arr, int len)
	{
		int i = 0, j = 1;
		//ÿ�������һ��Ԫ�رȽϣ����Ϊ��������������λ�Ͻ������±�+2,���Ϊż����ͬ��
		//��żλ�ϵ�����������
		while (i<len && j<len)
		{
			if (arr[len - 1] % 2 == 0)
			{
				swap(arr[len - 1], arr[i]);
				i += 2;
			}
			else
			{
				swap(arr[len - 1], arr[j]);
				j += 2;
			}
		}

	}
};