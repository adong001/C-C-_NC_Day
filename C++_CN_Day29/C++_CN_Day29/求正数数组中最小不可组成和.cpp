#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	/**
	*	���������е���С������ɺ�
	*	���룺��������arr
	*	���أ����������е���С������ɺ�
	*/
	int getFirstUnFormedNum(vector<int> arr, int len) 
	{
		int i,j;
		sort(arr.begin(), arr.end());
		for (i = 0; i < len; i++)
		{
			for (j = i; j < len; j++)//�ҵ���һ���������
			{
				if (arr[j] == arr[i])//���ҵ���ȵ�ֱ��return����
				{
					return arr[i];
				}
				else if (arr[j] > arr[i])//�ҵ���һ�����������ֹ���ѭ��
				{
					break;
				}
			}



		}
		if (i == len)//û�ҵ�
		{
			return arr[len-1] + 1;
		}
		
	}
};
int main3()
{
    system("pause");
    return 0;
}