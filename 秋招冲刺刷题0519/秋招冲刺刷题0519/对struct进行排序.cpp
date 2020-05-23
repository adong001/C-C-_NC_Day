#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct Point
{
	int x;
	int y;
	bool operator <(const Point& p)
	{
		if (x > p.x)
		{
			return false;
		}
		else if (x == p.x)
		{
			if (y < p.y)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		return true;
	}
};


int main1()
{
	int n;
	while (cin >> n)
	{
		int x = 0, y = 0;
		vector<Point> vec;
		Point p;
		for (int i = 0; i < n; i++)
		{
			cin >> p.x >> p.y;
			vec.push_back(p);
		}

		sort(vec.begin(), vec.end());
		for (auto iter = vec.begin(); iter != vec.end(); iter++)
		{
			cout << iter->x << " " << iter->y << endl;
		}
	}
    return 0;
}