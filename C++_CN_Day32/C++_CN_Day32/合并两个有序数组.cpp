#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;
//给定两个有序整数数组 nums1 和 nums2，将 nums2 合并到 nums1 中，使得 num1 成为一个有序数组。

//说明 :
//初始化 nums1 和 nums2 的元素数量分别为 m 和 n。
//你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。
//
//示例 :
//输入 :
//	nums1 = [1, 2, 3, 0, 0, 0], m = 3
//	nums2 = [2, 5, 6], n = 3
//输出 :
//	[1, 2, 2, 3, 5, 6]

class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
	{
		vector<int> tmp;
		int i, j;
		for (i = 0, j = 0; i < m || j < n;)
		{
			if (n == 0)
			{
				return;
			}
			if (i < m && (j == n || nums1[i] < nums2[j]))
			{
				tmp.push_back(nums1[i]);
				i++;
			}
			else if(j < n)
			{
				tmp.push_back(nums2[j]);
				j++;
			}
		}
		tmp.swap(nums1);
	}
};
int main()
{
	vector<int> n1 = {2,0};
	vector<int> n2 = {1};
	Solution s;
	s.merge(n1, 1, n2, 1);
    system("pause");
    return 0;
}