#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
���ӣ�https://www.nowcoder.com/questionTerminal/8ef655edf42d4e08b44be4d777edbf43
��Դ��ţ����

//˼·��1.�ҹ��ɣ����֣�����������ʾ�Ļ�����1�е�1������������ߣ������ڵ�n��Ԫ��λ�ã�n�����кţ�
//     2.��n�е�Ԫ�صĵ�һ�������һ����Ҫ��ǰ��ֵΪ1.�����е�Ԫ�أ�����һ���⣬���չ�ʽ
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

���ӣ�https://www.nowcoder.com/questionTerminal/8ef655edf42d4e08b44be4d777edbf43
��Դ��ţ����

��һ�ַ����ǿ�����
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
�ڶ��ַ����ǻ����ʵ�ĸ�
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