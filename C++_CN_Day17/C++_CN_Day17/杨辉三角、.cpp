#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
链接：https://www.nowcoder.com/questionTerminal/8ef655edf42d4e08b44be4d777edbf43
来源：牛客网

//思路：1.找规律，发现，如果用数组表示的话，第1行的1并不是在最左边，而是在第n个元素位置（n代表行号）
//     2.第n行的元素的第一个和最后一个是要提前赋值为1.其他行的元素，除第一个外，按照公式
//      a[i][j]=a[i][j-1]+a[i][j]+a[i][j+1];
#include<iostream>
#include<vector>
using namespace std;
void printYH(int n)
{

	vector<vector<int> >a(n, vector<int>(2 * n - 1, 0));
	a[0][n - 1] = a[n - 1][0] = a[n - 1][2 * n - 2] = 1;
	if (n<2)
	{
		cout << "-1" << endl;
		return;
	}
	for (int i = 1; i<n; ++i)
	for (int j = 1; j<2 * n - 2; ++j)
		a[i][j] = a[i - 1][j] + a[i - 1][j - 1] + a[i - 1][j + 1];
	for (int i = 0; i<2 * n - 1; ++i)
	if (a[n - 1][i] != 0 && (a[n - 1][i] % 2 == 0))
	{
		cout << i + 1 << endl;
		return;
	}
	return;
}
int main()
{
	int n;
	while (cin >> n)
	{
		printYH(n);
	}
	return 0;
}
int main()
{
	system("pause");
	return 0;
}

链接：https://www.nowcoder.com/questionTerminal/8ef655edf42d4e08b44be4d777edbf43
来源：牛客网

第一种方法是看规律
#include<iostream>
using namespace std;
int main()
{
	int n;
	while (cin >> n){
		if (n <= 2)cout << "-1" << endl;
		else if (n % 2 == 1)cout << "2" << endl;
		else if (n % 4 == 0)cout << "3" << endl;
		else cout << "4" << endl;
	}
	return 0;
}
第二种方法是货真价实的干
#include<iostream>
using namespace std;
int main()
{
	int n;
	while (cin >> n){
		if (n <= 0)return 0;
		int i, j, k, Num = -1;
		int **a = new int *[n];
		for (i = 0; i<n; i++)
			a[i] = new int[2 * n - 1];
		for (j = 0; j<n; j++)
		for (k = 0; k<2 * n - 1; k++)
			a[j][k] = 0;
		a[0][n - 1] = 1;
		a[n - 1][0] = 1;
		a[n - 1][2 * n - 2] = 1;
		for (i = 1; i<n; i++)
		for (j = 1; j<2 * n - 2; j++)
			a[i][j] = a[i - 1][j - 1] +
			a[i - 1][j] + a[i - 1][j + 1];
		for (j = 0; j<2 * n - 1; j++)
		if (a[n - 1] != 0 && a[n - 1][j] % 2 == 0)
		{
			Num = j + 1;
			break;
		}
		cout << Num << endl;
	}
	return 0;
}