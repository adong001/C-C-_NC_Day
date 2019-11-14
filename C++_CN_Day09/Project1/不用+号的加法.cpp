#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

class UnusualAdd {
public:
	int addAB(int A, int B)
	{
		return(A - (-B));
	}
};
int main1()
{
	UnusualAdd Test;
	cout << Test.addAB(1, 9) << endl;
    system("pause");
    return 0;
}