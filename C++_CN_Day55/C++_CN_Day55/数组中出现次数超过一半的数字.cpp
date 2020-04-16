#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

class Solution {
public:

	//方法一:动态规划，某个元素出现num就++，紧接着没出现就num--,判断num>0说明出现次数是当前最大的，num<=0,说明不是，tmp就要换值
	//时间复杂度：O(N)，空间复杂度：O(N)
	int MoreThanHalfNum_Solution(vector<int> numbers)
	{
		int len = numbers.size();
		int tmp = numbers[0];
		int num = 1;//每个元素默认次数为1
		for (int i = 1; i < len; i++)
		{
			//tmp记录当前位置之前出现最多的元素
			if (numbers[i] == tmp)//tmp和这个相同.就++
			{
				num++;
			}
			else//和tmp不一致
			{
				if (num > 0)//tmp之前记录的次数
				{
					num--;
				}
				else//tmp之前出现次数小于1次，重新给tmp赋值
				{
					tmp = numbers[i];
					num = 1;
				}
			}
		}
		num = count(numbers.begin(), numbers.end(), tmp);//最后tmp保存的数据就是当前出现次数最多的
		if (num > len / 2)//大于数组一般就返回
		{
			return tmp;
		}
		return 0;
	}

	//方法二:先排序，如果一个数超过数组的一半，那么排序后，他一定在数组中间
	//时间复杂度O(N*LogN) 空间复杂度O(1)
	int MoreThanHalfNum_Solution2(vector<int> numbers)
	{
		int num;
		int len = numbers.size() / 2;
		sort(numbers.begin(), numbers.end());
		num = count(numbers.begin(), numbers.end(), numbers[len]);
		return num > len ? numbers[len] : 0;
	}
	//方法三:通过map的key保存某个数据的值，val记录这个值出现的次数，若超过数组一般就返回
	//时间复杂度O(N) 空间复杂度O(N)
	int MoreThanHalfNum_Solution3(vector<int> numbers)
	{
		map<int, int> m;
		int count = 0;
		int len = numbers.size();
		for (int i = 0; i< len; i++)
		{
			count = ++m[numbers[i]];
			if (count > len / 2)
			{
				return numbers[i];
			}
		}
		return 0;
	}
};


int main1()
{
	vector<int> v = { 1, 2, 3, 2, 2, 2, 5, 4, 2 };
	Solution s;
	s.MoreThanHalfNum_Solution2(v);
	return 0;
}