#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//����һ�����������һ��Ŀ��ֵ�����������ҵ�Ŀ��ֵ�������������������Ŀ��ֵ�������������У�
//���������ᱻ��˳������λ�ã�����Լ������������ظ�Ԫ�ء�

//ʾ�� 1:
//���� : [1, 3, 5, 6], 5
//��� : 2

//ʾ��2 :
//���� : [1, 3, 5, 6], 2
//��� : 1

//ʾ�� 3 :
//���� : [1, 3, 5, 6], 7
//��� : 4

//ʾ�� 4 :
//���� : [1, 3, 5, 6], 0
//��� : 0

class Solution {
public:
	int searchInsert(vector<int>& nums, int target)
	{
		//1.��������
		/*for(int i = 0; i < nums.size(); i++)
		{
		if(nums[i] >= target)
		{
		return i;
		}
		}
		return nums.size();*/

		//2.���ֲ���
		/*int size = nums.size();
		int left = 0;
		int right = size - 1;
		int mid;
		while (left <= right)
		{
		mid = (right + left)/2;
		if(nums[mid] == target)
		{
		return mid;
		}
		else if (nums[mid] > target)
		{
		right = mid - 1;
		}
		else
		{
		left = mid + 1;
		}

		}

		if (left >= size)//������ֵ�������ֵ
		{
		return size;
		}

		else if (right < 0)//������ֵС����Сֵ
		{
		return 0;
		}

		else//������ֵ����nums֮��
		{
		return left;//�ҵ���һ��ǡ�ô�������ֵ������ǰ��,left>right��˵��left�����Ǹ�����λ��
		}  */

		//3.ö��
		if (target <= nums[0])
		{
			return 0;
		}

		if (target > nums.back())
		{
			return nums.size();
		}

		return (int)(lower_bound(nums.begin(), nums.end(), target) - nums.begin());
		//iterator upper_bound(begin(),end(),key)������map�е�һ������key�ĵ�����ָ��
		//iterator lower_bound(begin(),end(),key)������map�е�һ�����ڻ����key�ĵ�����ָ��

	}
};
int main()
{
	Solution s;
	vector<int> nums1 = { 1, 3, 5, 6 };
	cout << s.searchInsert(nums1, 5) << endl; // 2 1 4 0
	cout << s.searchInsert(nums1, 2) << endl;//
	cout << s.searchInsert(nums1, 7) << endl;
	cout << s.searchInsert(nums1, 0) << endl;
	system("pause");
	return 0;
}