#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
//给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。
//你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。

//示例 :
//给定 nums = [2, 7, 11, 15], target = 9
//因为 nums[0] + nums[1] = 2 + 7 = 9
//所以返回[0, 1]


class Solution 
{
public:
	vector<int> twoSum(vector<int>& nums, int target)
	{
		unordered_map<int,int> m;//unordered_map查找时间复杂度O(1)
		int Size = nums.size();
		for (int i = 0; i < Size; i++)
		{
			if (m.count(target - nums[i]))
			{
				return{ m[target - nums[i]],i  };
			}
			else
			{
				m[nums[i]] = i;
			}
		}
		return{ -1, -1 };
	}
};
int main1()
{
	Solution s;
	vector<int> v = { 2, 7, 1 };
	for (auto& e : s.twoSum(v, 9))
	{
		cout << e << endl;
	}
    return 0;
}