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
	char *type[5] = { "����", "����", "÷��", "��Ƭ", "" };
	char *point[16] = { "", "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "С��", "����" };
	printf("%s%s  ", type[pk->type], point[pk->point]);
}
bool CmpPokerPoint1(Poker a, Poker b)//ֻ��������С������
{
	return (a.point < b.point);
}

bool CmpPokerPoint2(Poker a, Poker b)//ֻ�������Ӵ�С��
{
	return (a.point > b.point);
}

bool CmpPoker1(Poker a, Poker b)//�Ȱ�������С�����ţ��ٰ���ɫ�Ӻ����ŵ�����
{
	return (a.point < b.point) || ((a.point == b.point && a.type < b.type));
}

bool CmpPoker2(Poker a, Poker b)//�Ȱ������Ӵ�С�ţ��ٰ���ɫ�Ӻ����ŵ�����
{
	return (a.point > b.point) || ((a.point == b.point && a.type < b.type));
}

bool CmpPoker3(Poker a, Poker b)//������ģʽ����
{
	if (a.point <= 2)//�ı�A��2�ĵ���������K
	{
		a.point += 13;
	}
	if (a.point>2)//�ı�3--K�ĵ�����3Ϊ��С����
	{
		a.point -= 2;
	}
	return (a.point < b.point);//�ٰ�������С��������
}

void InsertSort(Poker *pk, int size, bool(*cmp)(Poker, Poker))
//ֱ�Ӳ�������,ʹ��ȱʡ����,�粻�����������Ĭ�ϰ���ֻ��������С������
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
	cout << "���������밴1����������밴0:\n";
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