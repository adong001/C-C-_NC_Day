#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

class BinInsert {
public:
	int binInsert(int n, int m, int j, int i)
	{
		/*if (j < 0 || i > 31 || j > i)
		{
		return n;
		}*/
		if (m == 0)
		{
			return n;
		}
		int tmp;
		for (tmp = j; tmp <= i; tmp++)
		{
			 n |= ((((m >> (tmp - j)) & 1))<< tmp);
		}
		return n;
	}
};

int main()
{
	BinInsert test;
	cout << test.binInsert(1024, 19, 2, 6) << endl;
	return 0;
}



