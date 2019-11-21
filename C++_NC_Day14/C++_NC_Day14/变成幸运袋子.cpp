#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

//一个袋子里面有编号不同的球，存在相同编号的球，
//使得袋子里面的所有球的号码和大于所有号码之积，这个袋子就是幸运袋子
//通过移除袋子中的球使其成为幸运袋子，可以移除0个到n-1个
//输入 球的个数 和 所有球的编号
//输出 可以产生幸运袋子的个数

bool IsLuck(vector<int>& v)
{
	int sum = 0;
	int mul = 1;
	for (auto& vs : v)
	{
		sum += vs;
		mul *= vs;
	}
	if (sum > mul)
	{
		return true;
	}
	return false;
}

int FindLuck(vector<int>& v)
{
	static int count = 0;
	int n = v.size();
	if (n < 2)//只剩一个时，返回0,
	{
		return 0;
	}
	for (int i = 0; i < n; i++)//删除个数
	{
		vector<int> tmp ;
		for (int j = 0; j < n - i; j++)//循环删除的次数就是删除的个数5
		{
			for (int k = j; k < )
			{
				tmp.push_back(v[k]);
			}
		}
		if (IsLuck(v))
		{
			count++;
		}
	}
}

int main()
{
	vector<int> v;
	int n;
	cin >> n;

	if (n < 2)
	{
		return 0;
	}

	v.resize(n);

	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	cout << FindLuck(v) << endl;
    system("pause");
    return 0;
}