#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

bool IsLeap(int year)
{
	return ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0));
}

int OutDaysInYear()
{
	int year, month, day;
	int Days = 0;
	int ar[] = { 29, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	cin >> year;
	cin >> month;
	cin >> day;
	if (12 < month || month < 0 )
	{
		return -1;
	}

	if (day < 1 || day > ar[month] || (IsLeap(year) && month == 2 && day>29))
	{
		return -1;
	}
	int i;
	for (i = 1; i < month; i++)
	{
		Days += ar[i];
	}
	Days += day;

	if (IsLeap(year) && month > 2)
	{
		Days ++;
	}
	return Days;

}

int main1()
{
	cout << OutDaysInYear() << endl;
    system("pause");
    return 0;
}
