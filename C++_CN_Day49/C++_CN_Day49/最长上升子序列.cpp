#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#define MAX(a,b) a>b?a:b

int main()
{
	int n;
	while (std::cin >> n)
	{
		int max = 0;
		std::vector<int> v1(n), v2(n,0);//v2用来记当前位置到后面最长上升子序列的大小
		for (int i = 0; i < n; i++)
		{
			std::cin >> v1[i];
			for (int j = i - 1; j >= 0; --j)
			{
				if (v1[i] > v1[j])
				//v1[i] >  v[j] ---保证当前位置(j)一定是到达(i)是上升子序列
				{
					v2[i] = MAX(v2[i], v2[j]+ 1);
					//当前位置(j)到达(i)的最长子序列
				}
			}
			max = MAX(max,v2[i]);//找到最长上升子序列
		}
		std::cout << max << std::endl;
	}
    return 0;
}