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
		tmp = num1 ^ num2;//��Ҫ��λ��λ
		res = (num1 & num2)<<1;//���ý�λ��λ
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