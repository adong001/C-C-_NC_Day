#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

int GetWeek(int year, int month, int day)//��ý��������ڼ�
{
	//��ķ����ɭ��ʽ
	return (day + (2 * month) + ((3 * (month + 1)) / 5)
		+ year + (year / 4) - (year / 100)
		+ (year / 400)) % 7;
}

int GetDay(int year, int month, int num, int week)//����ĳ��ĳ�µĵ�num��week������µļ���
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