#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
//给定一个非空数组，返回此数组中第三大的数。如果不存在，则返回数组中最大的数。
//要求算法时间复杂度必须是O(n)。
//
//示例 1:
//输入 : [3, 2, 1]
//输出 : 1
//解释 : 第三大的数是 1.

//示例 2 :
//输入 : [1, 2]
//输出 : 2
//解释 : 第三大的数不存在, 所以返回最大的数 2 .

//示例 3 :
//输入 : [2, 2, 3, 1]
//输出 : 1
//解释 : 注意，要求返回第三大的数，是指第三大且唯一出现的数。
//		 存在两个值为2的数，它们都排第二。

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