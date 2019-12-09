#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Gift {
public:
	int getValue(vector<int> gifts, int n) 
	{
		sort(gifts.begin(),gifts.end());
		int tmp = gifts[n / 2];
		if (count(gifts.begin(), gifts.end(), tmp)>(n/2))
		{
			return tmp;
		}
		return 0;
	}

};
int main2()
{
	vector<int> v = { 1, 2, 3, 2, 2 };
	Gift t;
	cout<<t.getValue(v, 5);
    system("pause");
    return 0;
}