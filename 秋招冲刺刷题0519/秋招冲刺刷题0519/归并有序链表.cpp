#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<functional>
#include<queue>
using namespace std;

int main2()
{
	int k, n;
	while(cin >> k >> n)
	{
		priority_queue<int, vector<int>,greater<int>> qv;
		int tmp;
		for (int i = 0; i < k; i++)
		{
			for (int i = 0; i < n; i++)
			{
				cin >> tmp;
				qv.push(tmp);
			}

		}
		while (!qv.empty())
		{
			cout << qv.top() << " ";
			qv.pop();
		}
		/*vector<int> v1(n);
		vector<int> v2(m);
		vector<int> tmp;
		int i, j;
		for (i = 0; i < n; i++)
		{
			cin >> v1[i];
		}
		for (i = 0; i < m; i++)
		{
			cin >> v2[i];
		}
		int len = n < m ? n : m;
		for (i = 0,j = 0; i < n && j < m;)
		{
			if (v1[i] < v2[j])
			{
				tmp.push_back(v1[i]);
				i++;
			}
			else
			{
				tmp.push_back(v2[j]);
				j++;
			}
		}
		if (i >= n)
		{
			for (; j < m; j++)
			{
				tmp.push_back(v2[j]);
			}
		}
		if (j >= m)
		{
			for (; i < n; i++)
			{
				tmp.push_back(v1[i]);
			}
		}
		for (auto& e : tmp)
		{
			cout << e << " " << endl;
		}
		cout << endl;*/
	}
    return 0;
}