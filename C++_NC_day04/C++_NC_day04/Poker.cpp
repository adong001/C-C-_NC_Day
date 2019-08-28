#include"poker.h"

int ar[TYPE][POINT] = { 0 };
void Poker::InputPoker(Poker *pk, int type, int point)//���뻨ɫ�͵���
{
	pk->type = type;
	pk->point = point;
}

void Poker::OutputPoker(Poker *pk)//��ӡ�˿���
{
	char *type[TYPE] = { "����", "����", "÷��", "����", "" };
	char *point[POINT] = { "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "С��", "����" };
	printf("%s%s ", type[pk->type], point[pk->point]);
}


void Player::AddPoker(Player &pl)//��������
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
			if (type < TYPE - 1 && point >= POINT - 2)//������ַ������������С�������
			{
				continue;
			}

			if (type == TYPE - 1 && point < POINT - 2)//�������û�д�ɫ
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
void Player::ShowPoker(Player &pl)//չʾ����
{
	int i;
	for (i = 0; i < POKERNUM; i++)
	{

		pl.pk->OutputPoker(pl.pk + i);
	}
}

int Poker::ReturnType()//����˽�г�Ա
{
	return type;
}

int Poker::ReturnPoint()
{
	return point;
}


void Poker::ChangePoint(int Point)//�ı�˽�г�Աpoint
{
	point += Point;
}


bool CmpPokerPoint1(Poker a, Poker b)//ֻ��������С������
{
	return (a.ReturnPoint() < b.ReturnPoint());
}

bool CmpPokerPoint2(Poker a, Poker b)//ֻ�������Ӵ�С��
{
	return (a.ReturnPoint() > b.ReturnPoint());
}

bool CmpPokerPoint3(Poker a, Poker b)//������ģʽ����
{
	if (a.ReturnPoint() < 2)//�ı�A��2�ĵ���������K
	{
		a.ChangePoint(12);
	}
	else if (a.ReturnPoint() >= 2 && a.ReturnPoint() < 13)//�ı�3--K�ĵ�����3Ϊ��С����
	{
		a.ChangePoint(-2) ;
	}
	return (a.ReturnPoint() < b.ReturnPoint());//�ٰ�������С��������
}

void InsertSort(Poker *pk, int size, bool(*cmp)(Poker, Poker) )
//ֱ�Ӳ�������,ʹ��ȱʡ����,�粻�����������Ĭ�ϰ���ֻ��������С������
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


void DealPoker(Player pl[], int players)//�������˷���
{
	int i;
	for (i = 0; i < players; i++)
	{
		pl[i].AddPoker(pl[i]);
	}
	for (i = 0; i < players; i++)
	{
		cout << "player1��";
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