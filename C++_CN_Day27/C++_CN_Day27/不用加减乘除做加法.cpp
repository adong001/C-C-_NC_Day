#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

class Solution {
public:
	int Add(int num1, int num2)
	{
		if (num2 == 0)
		{
			return num1;
		}
		int tmp, res;
		tmp = num1 ^ num2;//需要进位的位
		res = (num1 & num2)<<1;//不用进位的位
		return Add(tmp, res);
	}
};
int main()
{
	Solution t;
	cout << t.Add(1, 3) << endl;
    system("pause");
    return 0;
}