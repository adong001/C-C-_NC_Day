#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<vector>
using namespace std;

bool JudgePoker(vector<string>& player1, vector<string>& player2);
bool JudgeError(vector<string>& player1, vector<string>& player2);
void InputPoker()
{
	bool flag = true;
	string Poker;
	vector<string> player1, player2;

	while (getline(cin, Poker))
	{
		int i, j = 0;
		player1.push_back(string());
		for (i = 0; Poker[i] != '-'; i++)
		{
			if (Poker[i] == ' ')
			{
				j++;
				player1.push_back(string());
				continue;
			}
			player1[j].push_back(Poker[i]);
		}
		i++;
		j = 0;
		player2.push_back(string());
		for (; i < Poker.size(); i++)
		{
			if (Poker[i] == ' ')
			{
				j++;
				player2.push_back(string());
				continue;
			}

			player2[j].push_back(Poker[i]);
		}

		if (JudgeError(player1, player2))
		{
			cout << "ERROR" << endl;
		}

		else if (JudgePoker(player1, player2))
		{
			for (auto& ch : player1)
			{
				cout << ch << " ";
			}
			cout << endl;
		}

		else
		{
			for (auto& ch : player2)
			{
				cout << ch << " ";
			}
			cout << endl;
		}
	}
}

bool JudgeError(vector<string>& player1, vector<string>& player2)//true代表ERROR
{

	if (player1.size() == player2.size() || (player1[0] == "joker" && player1[1] == "JOKER") ||
		(player2[0] == "joker" && player2[1] == "JOKER") || (player1.size() == 4 || player2.size() == 4))
	{
		return false;
	}
	return true;
}

bool JudgePoker(vector<string>& player1, vector<string>& player2)
{
	string vs[] = { "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A", "2", "joker", "JOKER" };
	vector<string> p1(player1), p2(player2);

	if (player1.size() == 4 && player2.size() != 4 && player2[0] != "joker" || player2.size() != 4 && player1[0] != "joker" && player2.size() == 4)
	{
		if (player1.size() == 4)
		{
			return true;
		}
		return false;
	}
	//单，双，三，炸弹，顺子(这些情况都有可能出王炸，王炸只有两张，所以两个条件取或，
	//题目给出的牌一定合法，只要判断第一个数的大小即可)
	int pos1, pos2;
	for (int i = 0; i < 15; i++)
	{
		if (p1[0] == vs[i])
		{
			pos1 = i;
		}
		if (p2[0] == vs[i])
		{
			pos2 = i;
		}
	}
	return pos1 > pos2 ? true : false;
}



int main()
{
	InputPoker();
	system("pause");
	return 0;
}