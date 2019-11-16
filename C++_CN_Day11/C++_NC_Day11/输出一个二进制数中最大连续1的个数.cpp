#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

int main()
{
	int num;
	int max = 0, tmp = 0;
	cin >> num;
	if(num)
	{
		for (int i = 0; i < 32; i++)
		{
			if ((num >> i) & 1)
			{
				tmp++;
				max = (tmp > max ? tmp : max);
			}
			else
			{
				tmp = 0;
			}
		}
	}
	cout << max << endl;
	system("pause");
	return 0;
}

//int main()
//{
//	int n = 0;
//	while (cin >> n)
//	{
//		int s = 0;
//		int count = 0;
//		while (n)
//		{
//			if (n & 1 == 1)
//			{
//				++s;             //当前连续位
//				count = s>count ? s : count;   //最大连续位
//			}
//			else
//				s = 0;
//			n = n >> 1;   //右移一位
//		}
//		cout << count << endl;
//	}
//	return 0;
//}
