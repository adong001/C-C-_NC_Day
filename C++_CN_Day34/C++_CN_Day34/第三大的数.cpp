#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
//����һ���ǿ����飬���ش������е������������������ڣ��򷵻���������������
//Ҫ���㷨ʱ�临�Ӷȱ�����O(n)��
//
//ʾ�� 1:
//���� : [3, 2, 1]
//��� : 1
//���� : ����������� 1.

//ʾ�� 2 :
//���� : [1, 2]
//��� : 2
//���� : ���������������, ���Է��������� 2 .

//ʾ�� 3 :
//���� : [2, 2, 3, 1]
//��� : 1
//���� : ע�⣬Ҫ�󷵻ص������������ָ��������Ψһ���ֵ�����
//		 ��������ֵΪ2���������Ƕ��ŵڶ���

class Solution {
public:
	int thirdMax(vector<int>& nums)
	{
		set<int> s(nums.begin(),nums.end());
		if (s.size() > 2)
		{
			auto ip = s.end();
			ip --;
			ip --;
			ip --;
			return *ip;
		}
		return *(--s.end());
	}
};
int main()
{
	vector<int> v = { 5,2,2 };
	Solution s;
	cout<<s.thirdMax(v);
    system("pause");
    return 0;
}