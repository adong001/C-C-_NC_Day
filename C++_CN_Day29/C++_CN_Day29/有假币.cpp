//#define _CRT_SECURE_NO_WARNINGS 
//#include<iostream>
//#include<cmath>
//#include<cstdio>
//using namespace std;
//int main()
//{
//	double n = 3.12345;
//	{
//		cout << "对" << n << "向上取整：" << ceil(n) << endl; // 4
//		cout << "对" << n << "想下取整: " << floor(n) << endl;//3
//		printf("对%4.2lf向上取带两位小数点的小数：%4.2f\n", n, ceil(n));//4.00
//		printf("对%4.2lf向下取带两位小数点的小数：%4.2f\n", n, floor(n));//3.00
//	}
//	return 0;
//}


#include<iostream>
#include<cmath>
using namespace std;

////0  1  2  3  4  5  6  7  8  9  10  11 .......27  28  29....
////b  0  1  1  2  2  2  2  2  2  3   3  .......3   4   4 ....

//方法1：
int main4()
{
	int num;
	while (cin >> num)
	{
		if (num == 0)
		{
			break;
		}
		else
		{
			cout << (int)ceil(log(num) / log(3))<<endl;
			//log3(num),取出log以3为底num的对数，并对其向上取整,再转换为int，ceil函数返回值为double
		}
	}
	return 0;
}

//方法2：
int main22()
{
	long num;
	while (cin >> num)
	{
		int count = 0;
		if (num == 0)
		{
			break;
		}
		if (num == 1)
		{
			cout << 0 << endl;
		}
		else
		{
			for (long i = 1; i < num; i *= 3, ++count);
			cout << count << endl;
		}
	}
	system("pause");
	return 0;
}