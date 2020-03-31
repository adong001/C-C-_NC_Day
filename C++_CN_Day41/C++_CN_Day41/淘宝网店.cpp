#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
//ÿ��׬��Ǯ����0����������µ�
int DayofMonth[] = { 29, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int MonenyofMonth[] = { 29, 62, 28, 31, 60, 31, 60, 31, 62, 60, 62, 30, 62 };
#define LEAPMONEY  580 //����һ��׬��Ǯ
#define UNLEAPMONEY 579 //������

bool Prime(int month)
{
	if (month == 2 || month == 3 || month == 5 || month == 7 || month == 11)
	{	
		return true;
	}
	return false;
}

bool IsLeap(int year)
{
	return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}

int main()
{
	int byear, bmonth, bday, eyear, emonth, eday;
	while (std::cin >> byear >> bmonth >> bday >> eyear >> emonth >> eday)
	{
		int Money = 0;
		bool IsL = IsLeap(byear);
		if (byear == eyear && bmonth == emonth)//ͬ��ͬ��
		{
			Money += Prime(bmonth) ? (eday - bday + 1) : (eday - bday + 1) * 2;
		}

		else if (byear == eyear && bmonth != emonth)//ͬ�겻ͬ��
		{
			//��ʼ��
			Money += Prime(bmonth) ? (DayofMonth[bmonth] - bday + 1) : (DayofMonth[bmonth] - bday + 1) * 2;
			bmonth++;
			//�м���
			for (; bmonth < emonth; ++bmonth)
			{
				Money += MonenyofMonth[bmonth];
			}
			//������,
			Money += Prime(bmonth) ? eday : eday * 2.;
		}

		else //��ͬ�겻ͬ��
		{
			IsL = IsLeap(byear);
			//��ʼ��
			Money += Prime(bmonth) ? (DayofMonth[bmonth] - bday + 1) : (DayofMonth[bmonth] - bday + 1) * 2;
			if (bmonth <= 2)
			{
				Money += IsL ? 1 : 0;
			}
			bmonth++;
			//�м���
			for (; bmonth <= 12; ++bmonth)
			{
				Money += MonenyofMonth[bmonth];
			}

			//�м���
			for (int i = byear + 1; i < eyear; ++i)
			{
				Money += (IsLeap(i) ? LEAPMONEY : UNLEAPMONEY);
			}

			//������
			IsL = IsLeap(eyear);

			Money += Prime(emonth) ? eday : eday * 2;
			for (int i = emonth - 1; i > 0; --i)
			{
				Money += MonenyofMonth[i];
			}
		}
		std::cout << Money << std::endl;
	}
	return 0;
}