#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>
using namespace std;
//给定一个整数数组，判断是否存在重复元素。
//如果任何值在数组中出现至少两次，函数返回 true。
//如果数组中每个元素都不相同，则返回 false。

//示例 1:
//输入 : [1, 2, 3, 1]
//输出 : true

//示例 2 :
//输入 : [1, 2, 3, 4]
//输出 : false

//示例 3 :
//输入 : [1, 1, 1, 3, 3, 4, 3, 2, 4, 2]
//输出 : true

class Solution {
public:
	bool containsDuplicate(vector<int>& nums)
	{

		/*方法1
		int i;
		int count = 0;
		if (nums.empty())
		{
			return false;
		}
		int size = nums.size();
		sort(nums.begin(), nums.end());
		int tmp = nums[0];
		for (i = 1; i < size; i++)
		{
			if (tmp == nums[i])//此位置和tmp记录的数据一致,说明存在一个数据至少出现了两次
			{
				return true;
			}
			else//开始记录新的元素
			{
				tmp = nums[i];
				count = 0;
			}
		}
		return false;
		*/
		//方法2
		unordered_set<int> uos;
		for (auto& e : nums)
		{
			if (!uos.insert(e).second)
			{
				return true;
			}
		}
		return false;
	}
};

int main1()
{
	Solution sl;
	vector<int> v = {3,1};
	vector<int> v1 = { 1, 2, 3, 4 };
	vector<int> v2 = { 1, 1, 1, 3, 3, 4, 3, 2, 4, 2 };
	cout<<sl.containsDuplicate(v) <<endl ;
	cout<<sl.containsDuplicate(v1)<<endl;
	cout<<sl.containsDuplicate(v2)<<endl;


	system("pause");
	return 0;
}