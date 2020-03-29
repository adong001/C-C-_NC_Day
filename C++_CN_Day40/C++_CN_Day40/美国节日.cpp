#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

int GetWeek(int year, int month, int day)//获得今天是星期几
{
	//吉姆拉尔森公式
	if (month == 1 || month == 2){
		month += 12;
		year -= 1;
	}

	int century = year / 100;
	year %= 100;
	int week = year + (year / 4) + (century / 4) - 2 * century +
		26 * (month + 1) / 10 + day - 1;

	week = (week % 7 + 7) % 7;
	if (week == 0){
		week = 7;
	}
	return week;
}

int GetDay(int year, int month, int num, int week)//返回某年某月的第num个week是这个月的几号
{
	int firstday = GetWeek(year, month, 1);
	return (1 + (num - 1) * 7 + (7 + week - firstday) % 7);
}

void Print_NewYear(int year)
{
	cout << year << "-01-01" << endl;
}

void Print_MarTin(int year)
{
	cout << year << "-01-" << GetDay(year,1,3,1)<< endl;
}

void Print_President(int year)
{
	cout << year << "-02-" << GetDay(year, 2, 3, 1) << endl;
}

void Print_Martry(int year)
{
	int week = GetWeek(year, 5, 31);//获取这月最后一天是星期几
	week = 31 - week + 1;
	cout << year << "-05-" << week << endl;
}

void Print_National(int year)
{
	cout << year << "-07-04" << endl;
}

void Print_Larbour(int year)
{
	cout << year << "-09-0"<< GetDay(year, 9, 1, 1) << endl;
}

void Print_Thanksgiving(int year)
{
	cout << year << "-11-" << GetDay(year, 11, 4, 4) << endl;
} 

void Print_Chrismas(int year)
{
	cout << year << "-12-25"<< endl;
}

int main()
{
	int year;
	while (cin >> year)
	{
		Print_NewYear(year);
		Print_MarTin(year);
		Print_President(year);
		Print_Martry(year);
		Print_National(year);
		Print_Larbour(year);
		Print_Thanksgiving(year);
		Print_Chrismas(year);
	}
    system("pause");
    return 0;
}