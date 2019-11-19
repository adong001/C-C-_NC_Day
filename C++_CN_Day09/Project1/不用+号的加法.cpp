#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

class UnusualAdd {
public:
	/*int addAB(int A, int B)
	{
		return(A - (-B));
	}*/

	int addAB(int A, int B)
	{
		if (B == 0)
		{
			return A;
		}

		int sum = 0, carry = 0;
		{    // 1+1=0  1+0=1 0+1=1  0+0=0 这就是两个数任意一位相加的情况   
			sum = (A^B);//1.记录两个数的异或值，它代表两个数的那一位不相同，就不用进位，0+0虽然不用进位，但和还是0，不用考虑。 
			carry = (A&B) << 1;//记录两个数按位与的值，他代表两个数需要进位的位数，将1左移这些位
			return addAB(sum, carry);//进位和不不进位相加递归直到进位为0
		}
	}

};
int main()
{
	UnusualAdd Test;
	cout << Test.addAB(1, 9) << endl;
    system("pause");
    return 0;
}