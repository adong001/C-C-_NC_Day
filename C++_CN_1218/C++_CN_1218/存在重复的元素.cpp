#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
//����һ���������飬�ж��Ƿ�����ظ�Ԫ�ء�
//����κ�ֵ�������г����������Σ��������� true��
//���������ÿ��Ԫ�ض�����ͬ���򷵻� false��
//
//ʾ�� 1:
//
//���� : [1, 2, 3, 1]
//��� : true
//
//ʾ�� 2 :
//
//���� : [1, 2, 3, 4]
//��� : false
//
//ʾ�� 3 :
//
//���� : [1, 1, 1, 3, 3, 4, 3, 2, 4, 2]
//��� : true
//

class Solution {
public:
	bool containsDuplicate(vector<int>& nums) 
	{
		unordered_set<int> s;
		for (auto& e : nums)
		{
			if (!s.insert(e).second)
			{
				return true;
			}
		}
		return false;
	}
};
int main6()
{
    system("pause");
    return 0;
}