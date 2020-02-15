#include"data.h"

Data::Data(int year, int month, int day, int N_Day)
{
	m_year = year;
	m_month = month;
	m_day = day;
	if (N_Day)
	{
		FindNData(m_year,m_month,m_day, N_Day);
		printf("��%d���Ϊ%d��%d��%d��\n", N_Day, m_year,m_month, m_day);
	}
}
void Data::FindNData(int &year, int &month, int &day, int N_Day)
{
	while (N_Day)//Ҫ��ת��������Ϊѭ���˳�����
	{
		int _MonthDay = MonthDay(year, month);//�õ���������µ�����
		if (N_Day <= (_MonthDay - day))//�ж�Ҫ��ת���������Ͻ���������Ƿ�������µ�������
		{
			day += N_Day;
			return;
		}
		else//����ʣ������������ת������
		{
			N_Day -= (_MonthDay - day);//����������-������գ��������¿�������������
			day = 0;//��������Ϊ0,����������¼Ӽ�
			month++;//����������month++

			if (month == 13)//��monthԽ��
			{
				year++;//�����µ�һ��
				month = 1;
			}
		}
	}
}

int MonthDay(int year, int month)
{
	int ArrMon[13] = { 29, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	//�������ȡ��һ��Ԫ�أ�ƽ��1-12���δӵڶ���Ԫ��ȡ
	if (IsLeap(year) && month == 2)//��Ϊ������Ϊ���£�
	{
		return ArrMon[0];
	}
	return ArrMon[month];
}

int IsLeap(int year)
{
	return ((year % 100 == 0 && year % 100 != 0) || year % 400 == 0);
}