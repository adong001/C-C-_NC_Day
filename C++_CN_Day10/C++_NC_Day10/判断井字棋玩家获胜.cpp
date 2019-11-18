#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

class Board {
public:
	bool checkWon(vector<vector<int> > board)
	{
		if (board[0][0] == 1 && board[1][1] == 1 && board[2][2] == 1 ||
			board[0][2] == 1 && board[1][1] == 1 && board[2][0] == 1)
		{
			cout << "true" << endl;
			return true;
		}
		else
		{
			for (int i = 0; i < 3; i++)
			{
				if (board[i][0] == 1 && board[i][1] == 1 && board[i][2] == 1 ||
					board[0][i] == 1 && board[1][i] == 1 && board[2][i] == 1)
				{
					cout << "true" << endl;
					return true;
				}
			}
		
		}	
		cout << "false" << endl;
		return false;
}
	/*bool checkWon22(vector<vector<int> > a)
	{
		if (a[0][0] + a[1][1] + a[2][2] == 3) return true;
		if (a[0][2] + a[1][1] + a[2][0] == 3) return true;
		for (int i = 0; i < 3; i++){
			if (a[i][0] + a[i][1] + a[i][2] == 3) return true;
			if (a[0][i] + a[1][i] + a[2][i] == 3) return true;
		}
		return false;
	}*/
		
	};
	int main1()
	{
		Board test;
		vector<vector<int>> v;
		int ar[][3] = { -1, 1, -1, 0, 0, 1, 0, 0, 0 };
		for (int i = 0; i < 3; i++)
		{
			v.push_back(vector<int>());
			v[i].insert(v[i].begin(), ar[i], ar[i] + 3);
		}
		test.checkWon(v);
		system("pause");
		return 0;
	}