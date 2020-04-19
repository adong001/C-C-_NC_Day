#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<algorithm>

struct Person
{
	int weight;
	int height;
};
bool cmp(const Person& p1, const Person& p2)
{
	if (p1.weight != p2.weight)
	{
		return p1.weight < p2.weight;//体重按从小到大排
	}
	else
	{
		return p1.height <= p2.height;//身高按从高到低
	}
}
std::istream & operator >> (std::istream &is, Person &p)
{
	is >> p.weight >> p.height;
	return is;
}

int main2()
{
	int N;
	while (std::cin >> N)
	{
		int count = 0;
		int num;
		std::vector<Person> vp(N);
		for (int i = 0; i < N; i++)
		{
			std::cin >>num >> vp[i];
		}
		sort(vp.begin(), vp.end(), cmp);//先按体重排个序

		std::vector<int> dp(N);//dp与对应vp对应的位置代表前面到当前位置罗汉塔的最大高度
		dp[0] = 1;//初始化第一个元素为1
		for (int i = 1; i < N; i++)
		{
			dp[i] = 1;//每次到达某个元素时塔最低高度为1
			for (int j = 0; j < i; j++)
			{
				//每次都从第一个元素找起，找到当前位置中使罗汉塔高度最高
				//若上一个元素vp[j]比当前元素vp[i]升高第高(从上往下算)，
				//且上一个元素所记录的最高高度+1(dp[j]+1)要大于当前元素的高度dp[i]
				if (vp[j].height <= vp[i].height && dp[j] + 1 > dp[i])
				{
					//如果满足，就跟新当前元素的最高高度
					dp[i] = dp[j] + 1;
				}
			}
		}
		int Max = dp[0];
		for (int i = 1; i < N; i++)//找出高度记录表中最大高度
		{
			Max = Max > dp[i] ? Max : dp[i];
		}

		std::cout << Max << std::endl;
	}
	return 0;
}