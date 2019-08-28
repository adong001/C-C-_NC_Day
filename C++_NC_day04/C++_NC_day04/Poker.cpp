#include"poker.h"

int ar[TYPE][POINT] = { 0 };
void Poker::InputPoker(Poker *pk, int type, int point)//传入花色和点数
{
	pk->type = type;
	pk->point = point;
}

void Poker::OutputPoker(Poker *pk)//打印扑克牌
{
	char *type[TYPE] = { "黑桃", "红桃", "梅花", "方块", "" };
	char *point[POINT] = { "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "小王", "大王" };
	printf("%s%s ", type[pk->type], point[pk->point]);
}


void Player::AddPoker(Player &pl)//增加手牌
{
	srand((unsigned)time(NULL));
	int type = -1;
	int point = -1;
	for (int i = 0; i < POKERNUM; i++)
	{
		while (1)
		{
		
			type = rand() % TYPE;
			point = rand() % POINT;
			if (ar[type][point])
			{
				continue;
			}
			ar[type][point] = 1;
			if (type < TYPE - 1 && point >= POINT - 2)//避免出现方块大王，黑桃小王的情况
			{
				continue;
			}

			if (type == TYPE - 1 && point < POINT - 2)//避免出现没有打花色
			{
				continue;
			}

			pl.pk->InputPoker(pl.pk + i, type, point);
			//InsertSort(pl.pk, i + 1,CmpPokerPoint3);
			break;
		}
	}
	InsertSort(pl.pk, POKERNUM, CmpPokerPoint3);
}
void Player::ShowPoker(Player &pl)//展示手牌
{
	int i;
	for (i = 0; i < POKERNUM; i++)
	{

		pl.pk->OutputPoker(pl.pk + i);
	}
}

int Poker::ReturnType()//调用私有成员
{
	return type;
}

int Poker::ReturnPoint()
{
	return point;
}


void Poker::ChangePoint(int Point)//改变私有成员point
{
	point += Point;
}


bool CmpPokerPoint1(Poker a, Poker b)//只按点数从小到大排
{
	return (a.ReturnPoint() < b.ReturnPoint());
}

bool CmpPokerPoint2(Poker a, Poker b)//只按点数从大到小排
{
	return (a.ReturnPoint() > b.ReturnPoint());
}

bool CmpPokerPoint3(Poker a, Poker b)//斗地主模式排序
{
	if (a.ReturnPoint() < 2)//改变A和2的点数，大于K
	{
		a.ChangePoint(12);
	}
	else if (a.ReturnPoint() >= 2 && a.ReturnPoint() < 13)//改变3--K的点数，3为最小点数
	{
		a.ChangePoint(-2) ;
	}
	return (a.ReturnPoint() < b.ReturnPoint());//再按点数从小到大排序
}

void InsertSort(Poker *pk, int size, bool(*cmp)(Poker, Poker) )
//直接插入排序,使用缺省函数,如不传入参数，按默认按照只按点数从小到排序。
{
	int i, j;
	Poker tmp;
	for (i = 1; i < size; i++)
	{
		tmp = pk[i];
		for (j = i; j > 0 && cmp(tmp, pk[j - 1]); j--)
		{
			pk[j] = pk[j - 1];
		}
		pk[j] = tmp;
	}
}


void DealPoker(Player pl[], int players)//给三个人发牌
{
	int i;
	for (i = 0; i < players; i++)
	{
		pl[i].AddPoker(pl[i]);
	}
	for (i = 0; i < players; i++)
	{
		cout << "player1：";
		pl[i].ShowPoker(pl[i]);
		cout << endl;
	}
}

void PlayTest1()
{
	Player pl;
	pl.AddPoker(pl);
	pl.ShowPoker(pl);
}

void PlayTest2()
{

	Player pl[PLAYERS];
	DealPoker(pl, PLAYERS);
}