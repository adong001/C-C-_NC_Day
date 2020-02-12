#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool flag;
bool judgePoint24(vector<int>& nums) {
	flag = false;
	sort(nums.begin(), nums.end());
	do
	{
		dfs(nums, 0, 3);
	} while (!flag && next_permutation(nums.begin(), nums.end()));
	return flag;
}

vector<pair<int, int>> dfs(vector<int>& nums, int begin, int end){
	pair<int, int> tmp1(1, 1);
	pair<int, int> tmp2(1, 1);
	pair<int, int> tmp3(1, 1);
	pair<int, int> tmp4(1, 1);
	vector<pair<int, int>> res;
	if (begin >= end) return{ { nums[end], 1 } };
	for (int pos = begin; pos <= end - 1; ++pos)
	{
		auto v1 = dfs(nums, begin, pos);
		auto v2 = dfs(nums, pos + 1, end);
		for (auto i : v1){
			for (auto j : v2){
				if (i.second == j.second){
					tmp1.first = i.first + j.first;
					tmp2.first = i.first - j.first;
					tmp1.second = i.second;
					tmp2.second = i.second;
				}
				else
				{
					tmp1.first = i.first * j.second + j.first * i.second;
					tmp2.first = i.first * j.second - j.first * i.second;
					tmp1.second = i.second * j.second;
					tmp2.second = i.second * j.second;
				}

				tmp3.first = i.first * j.first;
				tmp3.second = i.second * j.second;

				res.push_back(tmp1);
				res.push_back(tmp2);
				res.push_back(tmp3);

				if (j.first > 0)
				{
					tmp4.first = i.first * j.second;
					tmp4.second = i.second * j.first;
					res.push_back(tmp4);
				}

				if (begin == 0 && end == 3)
				{
					if (tmp1.first % tmp1.second == 0 && tmp1.first / tmp1.second == 24) flag = true;
					if (tmp2.first % tmp2.second == 0 && tmp2.first / tmp2.second == 24) flag = true;
					if (tmp3.first % tmp3.second == 0 && tmp3.first / tmp3.second == 24) flag = true;
					if (tmp4.first % tmp4.second == 0 && tmp4.first / tmp4.second == 24) flag = true;
					if (flag) break;
				}
			}
		}
	}
	return res;
}

bool judgePoint24(vector<int>& nums) {
	flag = false;
	sort(nums.begin(), nums.end());
	do
	{
		dfs(nums, 0, 3);
	} while (!flag && next_permutation(nums.begin(), nums.end()));
	return flag;
}

int main()
{
	vector<int> v(4);
	while (cin >> v[0] >> v[1] >> v[2] >> v[3])
	{
		if (judgePoint24(v))
		{
			cout << "true" << endl;
		}
		else
		{
			cout << "false" << endl;
		}
	}
	return 0;
}