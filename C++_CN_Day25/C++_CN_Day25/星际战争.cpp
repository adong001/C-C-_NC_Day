#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

 pow(int k)

{

	if (k == 0)

	{

		Matrix ans(h_size(), h_size());

		for (int i = 0; i != ans.h_size(); ++i)

			ans[i][i] = 1;
		return ans;

	}

	if (k == 2)return (*this)*(*this);

	if (k % 2)return pow(k - 1)*(*this);

	return pow(k / 2).pow(2);
}

int main()
{
	int num,tmp;
	vector<int> v;
	while (cin >> num)
	{
		while (cin >> tmp)
		{
			v.push_back(tmp);
		}

	}
    system("pause");
    return 0;
}