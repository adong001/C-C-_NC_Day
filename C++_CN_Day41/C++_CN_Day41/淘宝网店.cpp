#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
//ÿ��׬��Ǯ����0����������µ�
int DayofMonth[] = { 29, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int MonenyofMonth[] = { 29, 62, 56, 31, 60, 31, 60, 31, 31, 60, 31, 60, 31 };
#define LEAPMONEY  505 //����һ��׬��Ǯ
#define UNLEAPMONEY 532 //������

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
		if (bmonth <= 2)//����ʼ���1,2��
		{
			if (bmonth == 1)
			{
				Money += (DayofMonth[bmonth] - bday + 1) * 2;
				Money += IsL ? MonenyofMonth[0] : MonenyofMonth[2];
				bmonth += 2;
			}
			else
			{
				Money += IsL ? (DayofMonth[0] - bday) : (DayofMonth[2] - bday) * 2;
				bmonth += 1;
			}
		}

		if (eyear - byear == 0)
		{
			for (int i = bmonth; i < emonth; ++i)//�ӿ�ʼ���Ժ�������·�
			{
				Money += MonenyofMonth[i];
			}
			Money += DayofMonth[emonth] % 2 ? (MonenyofMonth[emonth] - eday) : (MonenyofMonth[emonth] - eday) * 2;
		}
		else//���м�������
		{
			for (int i = bmonth; i <= 12; ++i)//�ӿ�ʼ���Ժ�������·�
			{
				Money += MonenyofMonth[i];
			}

			for (int i = byear + 1; i < eyear; ++i)
			{
				Money += (IsLeap(i) ? LEAPMONEY : UNLEAPMONEY);
			}


			IsL = IsLeap(eyear);//�����β��
			if (emonth>2)
			{
				Money += DayofMonth[emonth] % 2 ? (MonenyofMonth[emonth] - eday) : (MonenyofMonth[emonth] - eday) * 2;
				for (int i = emonth - 1; i > 2; --i)
				{
					Money += DayofMonth[i];
				}
			}
			else//�����β���1,2��
			{
				if (emonth == 1)
				{
					Money += eday * 2;
					emonth--;
				}
				else
				{
					Money += eday >= 29 ? eday : eday * 2;
					Money += MonenyofMonth[1];
					bmonth -= 2;
				}
			}
		}
		std::cout << Money << std::endl;
	}
	return 0;
}