#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
//每月赚的钱，第0个是闰年二月的
int DayofMonth[] = { 29, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int MonenyofMonth[] = { 29, 62, 56, 31, 60, 31, 60, 31, 31, 60, 31, 60, 31 };
#define LEAPMONEY  505 //闰年一年赚的钱
#define UNLEAPMONEY 532 //非闰年

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
		if (bmonth <= 2)//处理开始年的1,2月
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
			for (int i = bmonth; i < emonth; ++i)//加开始年以后的整数月份
			{
				Money += MonenyofMonth[i];
			}
			Money += DayofMonth[emonth] % 2 ? (MonenyofMonth[emonth] - eday) : (MonenyofMonth[emonth] - eday) * 2;
		}
		else//加中间隔得年份
		{
			for (int i = bmonth; i <= 12; ++i)//加开始年以后的整数月份
			{
				Money += MonenyofMonth[i];
			}

			for (int i = byear + 1; i < eyear; ++i)
			{
				Money += (IsLeap(i) ? LEAPMONEY : UNLEAPMONEY);
			}


			IsL = IsLeap(eyear);//处理结尾年
			if (emonth>2)
			{
				Money += DayofMonth[emonth] % 2 ? (MonenyofMonth[emonth] - eday) : (MonenyofMonth[emonth] - eday) * 2;
				for (int i = emonth - 1; i > 2; --i)
				{
					Money += DayofMonth[i];
				}
			}
			else//处理结尾年的1,2月
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