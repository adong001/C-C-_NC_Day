#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
//�����������飬��дһ���������������ǵĽ�����
//
//ʾ�� 1:
//
//���� : nums1 = [1, 2, 2, 1], nums2 = [2, 2]
//��� : [2]
//
//ʾ�� 2 :
//
//���� : nums1 = [4, 9, 5], nums2 = [9, 4, 9, 8, 4]
//��� : [9, 4]
//
//˵�� :
//	  �������е�ÿ��Ԫ��һ����Ψһ�ġ�
//	  ���ǿ��Բ�������������˳��

class Solution {
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
	{
		vector<int> common;
		unordered_set<int> s1(nums1.begin(), nums1.end());
		unordered_set<int> s2(nums2.begin(), nums2.end());
		for (auto& e : s2)
		{
			if (!s1.insert(e).second)
			{
				common.push_back(e);
			}
		}
		return common;
	}
};
int main5()
{
    system("pause");
    return 0;
}