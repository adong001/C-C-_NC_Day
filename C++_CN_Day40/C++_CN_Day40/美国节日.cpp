#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

int GetWeek(int year, int month, int day)//获得今天是星期几
{
	//吉姆拉尔森公式
	return (day + (2 * month) + ((3 * (month + 1)) / 5)
		+ year + (year / 4) - (year / 100)
		+ (year / 400)) % 7;
}

int GetDay(int year, int month, int num, int week)//返回某年某月的第num个week是这个月的几号
{
	int firstday = GetWeek(year, month, 1);

}

void print(int year)
{
	cout << year << "-" << endl;
}


int main()
{
    system("pause");
    return 0;
}