
#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

void GetPathRecursion(vector<vector<int>> v, int row, int col, vector<int>& vres)
{

}
void GetPath(vector<vector<int>> v, int row, int col, vector<int>& vres)
{
	if (row == 0 && col == 0)//到达出口
	{
		vres.push_back(row);
		vres.push_back(col);
		return;
	}
	else if ()
	{

	}
}

int main()
{
	int row, col, tmp;
	vector<vector<int>> v;
	vector<int> vres;
	while (cin >> row >> col)
	{
		for (int i = 0; i < row; i++)
		{	
			v.push_back(vector<int>());
			for (int j = 0; j < col; j++)
			{
				cin >> tmp;
				v[i].push_back(tmp);
			}
		}
		GetPath(v, row,col,vres);
		for (int i = vres.size() - 1; i >= 0; i -= 2)
		{
			cout << "(" << vres[i - 1] << "," << vres[i] << ")" << endl;
		}
	}
	system("pause");
    return 0;
}