#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数。

//示例 1:
//输入 : [1, 2, 3, 4, 5, 6, 7] 和 k = 3
//输出 : [5, 6, 7, 1, 2, 3, 4]
//解释 :
//向右旋转 1 步 : [7, 1, 2, 3, 4, 5, 6]
//向右旋转 2 步 : [6, 7, 1, 2, 3, 4, 5]
//向右旋转 3 步 : [5, 6, 7, 1, 2, 3, 4]

//示例 2 :
//输入 : [-1, -100, 3, 99] 和 k = 2
//输出 : [3, 99, -1, -100]
//解释 :
//向右旋转 1 步 : [99, -1, -100, 3]
//向右旋转 2 步 : [3, 99, -1, -100]

//说明 :
//尽可能想出更多的解决方案，至少有三种不同的方法可以解决这个问题。
//要求使用空间复杂度为 O(1)的原地算法。

class Solution {
public:

	void rotate(vector<int>& nums, int k)
	{
		int i;
		int size = nums.size();
		k %= size;//防止旋转次数超过size就会重复旋转，最多旋转size次

		//交换三次
		/*reverse(nums.begin(), nums.begin() + nums.size() - k);
		reverse(nums.begin() + nums.size() - k, nums.end());
		reverse(nums.begin(), nums.end());*/
		vector<int> tmp(size, 0);

		for (i = 0; i < size; i++)
		{
			tmp[(i + k) % size] = nums[i];
		}

		tmp.swap(nums);
	}
};

int main2()
{
	vector<int>nums = { 1, 2, 3, 4, 5, 6, 7 };

	Solution s;
	s.rotate(nums, 3);

	system("pause");
	return 0;
}