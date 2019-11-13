#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

int main1()
{
	///1 1 2 3 5 8 13---2---（15）--6---  21
	while(1)
	{
	int num;
	cin >> num;
	int fn_1 = 1, fn_2 = 1;
	int fn = fn_1 + fn_2;
	while (fn < num)//找到第一个大于num的斐波那契数
	{
		fn_2 = fn_1;
		fn_1 = fn;
		fn = fn_1 + fn_2;
	}
	//输出num离fn合fn_1最近的那个距离
	cout << ((fn - num) < (num - fn_1) ? (fn - num) : (num - fn_1)) << endl;

}system("pause");
}