#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，
//返回它将会被按顺序插入的位置，你可以假设数组中无重复元素。

//示例 1:
//输入 : [1, 3, 5, 6], 5
//输出 : 2

//示例2 :
//输入 : [1, 3, 5, 6], 2
//输出 : 1

//示例 3 :
//输入 : [1, 3, 5, 6], 7
//输出 : 4

//示例 4 :
//输入 : [1, 3, 5, 6], 0
//输出 : 0

class Solution {
public:
	int searchInsert(vector<int>& nums, int target)
	{
		//1.暴力搜索
		/*for(int i = 0; i < nums.size(); i++)
		{
		if(nums[i] >= target)
		{
		return i;
		}
		}
		return nums.size();*/

		//2.二分查找
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

		if (left >= size)//待查找值超过最大值
		{
		return size;
		}

		else if (right < 0)//待查找值小于最小值
		{
		return 0;
		}

		else//待查找值介于nums之中
		{
		return left;//找到第一个恰好大于他的值插在它前面,left>right后说明left就是那个待插位置
		}  */

		//3.枚举
		if (target <= nums[0])
		{
			return 0;
		}

		if (target > nums.back())
		{
			return nums.size();
		}

		return (int)(lower_bound(nums.begin(), nums.end(), target) - nums.begin());
		//iterator upper_bound(begin(),end(),key)：返回map中第一个大于key的迭代器指针
		//iterator lower_bound(begin(),end(),key)：返回map中第一个大于或等于key的迭代器指针

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