#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;
//����һ���Ǹ���������A������һ�����飬�ڸ������У�
//A������ż��Ԫ��֮�������������Ԫ�ء�
//����Է���������������κ�������Ϊ�𰸡�
//ʾ����
//���룺[3, 1, 2, 4]
//�����[2, 4, 3, 1]
//���[4, 2, 3, 1]��[2, 4, 1, 3] ��[4, 2, 1, 3] Ҳ�ᱻ���ܡ�
//
//��ʾ��
//1 <= A.length <= 5000
//0 <= A[i] <= 5000

class Solution {
public:
	vector<int> sortArrayByParity(vector<int>& A) 
	{
		vector<int> tmp(A.size());
		int i = 0, j = A.size() - 1;
		for (auto& e : A)
		{
			if (e % 2 == 0)
			{
				tmp[i] = e;
				i++;
			}
			else
			{
				tmp[j] = e;
				j--;
			}
		}
		return tmp;
	}
};
int main1()
{
    system("pause");
    return 0;
}