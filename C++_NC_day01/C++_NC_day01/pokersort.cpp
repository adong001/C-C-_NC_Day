#include"pokersort.h"

void InputPoker(Poker *pk, int size)
{
	scanf("%c%d", &pk[size].type, &pk[size].point);
	pk[size].type -= 'a';
	if (pk[size].type == 4)
	{
		pk[size].point += 13;
	}
	while (getchar() != '\n');
}

void OutputPoker(Poker *pk)
{
	char *type[5] = { "黑桃", "红桃", "梅花", "方片", "" };
	char *point[16] = { "", "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "小王", "大王" };
	printf("%s%s  ", type[pk->type], point[pk->point]);
}
bool CmpPokerPoint1(Poker a, Poker b)//只按点数从小到大排
{
	return (a.point < b.point);
}

bool CmpPokerPoint2(Poker a, Poker b)//只按点数从大到小排
{
	return (a.point > b.point);
}

bool CmpPoker1(Poker a, Poker b)//先按点数从小到大排，再按花色从黑桃排到方块
{
	return (a.point < b.point) || ((a.point == b.point && a.type < b.type));
}

bool CmpPoker2(Poker a, Poker b)//先按点数从大到小排，再按花色从黑桃排到方块
{
	return (a.point > b.point) || ((a.point == b.point && a.type < b.type));
}

bool CmpPoker3(Poker a, Poker b)//斗地主模式排序
{
	if (a.point <= 2)//改变A和2的点数，大于K
	{
		a.point += 13;
	}
	if (a.point>2)//改变3--K的点数，3为最小点数
	{
		a.point -= 2;
	}
	return (a.point < b.point);//再按点数从小到大排序
}

void InsertSort(Poker *pk, int size, bool(*cmp)(Poker, Poker))
//直接插入排序,使用缺省函数,如不传入参数，按默认按照只按点数从小到排序。
{
	int i, j;
	Poker tmp;
	for (i = 1; i < size; i++)
	{
		tmp = pk[i];
		for (j = i; j > 0 && cmp(tmp, pk[j-1]); j--)
		{
			pk[j] = pk[j - 1];
		}
		pk[j] = tmp;
	}
}


void PokerTest()
{
	Poker *p = nullptr;
	int i = 0;
	int flag = 1;
	int choice;
	cout << "继续输入请按1，输入结束请按0:\n";
	while (flag)
	{
		cin >> choice;
		getchar();
		switch (choice)
		{
		  case 1:
		  {
			 p = (Poker*)realloc(p,sizeof(Poker)*(i+1));
			 InputPoker(p, i);
			 InsertSort(p, i + 1,CmpPoker3);
			 i++;
			 break;
		  }
		  case 0:
		  {
			  flag = 0; 
			  break;
	      }
		}
	}
	for (int j = 0; j < i; j++)
	{
		OutputPoker(p + j);
	}
	free(p);
}