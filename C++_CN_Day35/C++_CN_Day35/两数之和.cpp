#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的
//那两个整数，并返回他们的数组下标。
//你可以假设每种输入只会对应一个答案。
//但是，你不能重复利用这个数组中同样的元素。
//
//示例 :
//给定 nums = [2, 7, 11, 15], target = 9
//因为 nums[0] + nums[1] = 2 + 7 = 9
//所以返回[0, 1]
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target)
	{
		//方法1:暴力搜索
		vector<int> res;
		int size = nums.size();
		int i, j;
		for (i = 0; i < size; i++)
		{
			auto tmp = find(nums.begin() + i + 1, nums.end(), target - nums[i]);
			if (tmp != nums.end())
			{
				res.push_back(i);
				res.push_back(tmp - nums.begin());
				break;
			}
		}
		return res;

	//方法2
	/*	unordered_map<int, int> m;
		int size = nums.size();
		for (int i = 0; i < size; i++)
		{
			if (m.count(target - nums[i]))
			{
				return{ i, m[target - nums[i]] };
			}
			m[nums[i]] = i;
		}
		return{ -1, -1 };*/
	}
};


int main1()
{
	vector<int> ar = { -11, -2, -3, -4, -5, };
	Solution s;
	s.twoSum(ar, -8);

	system("pause");
	return 0;
}