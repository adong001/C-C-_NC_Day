#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

//在地下室里放着n种颜色的手套，手套分左右手，但是每种颜色的左右手手套个数不一定相同。
//A先生现在要出门，所以他要去地下室选手套。但是昏暗的灯光让他无法分辨手套的颜色，只能分辨出左右手。
//所以他会多拿一些手套，然后选出一双颜色相同的左右手手套。现在的问题是，他至少要拿多少只手套(左手加右手)，
//才能保证一定能选出一双颜色相同的手套。

//给定颜色种数n(1≤n≤13), 同时给定两个长度为n的数组left, right, 分别代表每种颜色左右手手套的数量。
//数据保证左右的手套总数均不超过26，且一定存在至少一种合法方案。

//测试样例：
//4, [0, 7, 1, 6], [1, 5, 0, 6]
//返回：10(解释：可以左手手套取2只，右手手套取8只)


//思路：(左右手的数据都是对应的)
// 1.若左右手套中至少有一个手套为0，则将其计算在内(左无拿右，右无拿左)
// 2.将左右手套中较小的值push进一个容器中
// 3.遍历完成后，将容器从小到大排序，除去第一个元素其他都拿走
// 4.再拿2个(一双)代表其它都拿过了的情况下，多拿一个那个没有拿的手套，保证所有的手套都能包含在内，从而、产生最小的手套数
class Gloves {
public:
	int findMinimum(int n, vector<int> left, vector<int> right)
	{
		int sum = 0;
		vector<int> tmp;
		for (int i = 0; i < n; i++)
		{
			if (left[i] * right[i] == 0)
			{
				sum += left[i] + right[i];
			}
			else
			{
				tmp.push_back(left[i]>right[i] ? right[i] : left[i]);
			}
		}

		sort(tmp.begin(), tmp.end());
		for (int i = 1; i < tmp.size();i++)
		{
			sum += tmp[i];
		}
		return sum + 2;
	}
};

int main()
{
    system("pause");
    return 0;
}