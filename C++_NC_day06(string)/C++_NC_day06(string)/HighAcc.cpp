#include"HighAcc.h"

HighAcc::HighAcc(string& s)
{
	m_size = s.size();
	string::reverse_iterator i;//������
	int j;
	memset(m_data, 0, NUMSIZE);//������ȫ����Ϊ0��
	for (j = 0, i = s.rbegin(); i != s.rend(); i++, j++)//�����һλ��ʼ�����ַ���
	{
		m_data[j] = *i - '0';//���ַ�����ת��Ϊ�����ֶ�ӦASCII�ı�ţ�
		//���磬�ַ���1��- ASCII���Ϊ1���ַ�SOH(start of headline)
	}
	/*for (auto &i = s.end(); i != s.begin(); i--, j++)
	{
	m_data[j] = *i - '0';
	}*/
}
HighAcc HighAcc::operator *(HighAcc& H)
{
	int tmp, i, j;
	HighAcc sum;
	if (m_size == 1 && m_data[0] == 0 ||
		H.m_size == 1 && H.m_data[0] == 0)//�κ��� * 0 = 0
	{
		return sum;
	}
	for (i = 0; i < m_size; i++)
	{
		for (j = 0; j < H.m_size; j++)
		{
			tmp = m_data[i] * H.m_data[j] + sum.m_data[i + j];
			sum.m_data[i + j] = tmp % 10;
			sum.m_data[i + j + 1] += tmp / 10;
		}
	}
	sum.m_size = m_size + H.m_size - !sum.m_data[m_size + H.m_size - 1];//��������ˣ�������Ϊ��������֮�ͻ�-1��
	//�����λ��Ϊ�棬�򳤶�-1��
	return sum;
}


HighAcc HighAcc::operator +(HighAcc& H)
{
	int tmp, i;
	HighAcc sum;
	/*if (m_size == 1 && m_data[0] == 0 ||
		H.m_size == 1 && H.m_data[0] == 0)
		{
		sum = H;
		}*/
	int MaxSize = m_size > H.m_size ? m_size : H.m_size;
	sum.m_size = MaxSize + 1;//nλ��+mλ��=n+m��n+m+1λ��������һλ����ֹ��λ��
	for (i = 0; i < MaxSize; i++)
	{
		tmp = m_data[i] + H.m_data[i] + sum.m_data[i];
		sum.m_data[i] = tmp % 10;
		sum.m_data[i + 1] = tmp / 10;
	}
	sum.m_size -= !sum.m_data[MaxSize];//�����λ��Ϊ�㣬���ü�ȥ
	return sum;
}

//void HighAcc::DealData()
//{
//	int i, j;
//	char tmp;
//	for (i = 0, j = m_size - 1; i < j; i++, j--)
//	{
//		tmp = m_data[i]-'\0';
//		m_data[i] = m_data[j]-'\0';
//		m_data[j] = tmp;
//	}
//}


//ostream& operator <<(ostream& os, HighAcc& H)
//{
//	int i;
//	for (i = H.m_size - 1; i > 0; i++)
//	{
//		os << H.m_data[i];
//	}
//	os << endl;
//	return os;
//}
//
//istream& operator >>(istream& is, HighAcc& H)
//{
//	char tmp[1024];
//	is >> tmp;
//	H.m_size = strlen(tmp);
//	H.m_data = new char[H.m_size];
//	strcpy(H.m_data, tmp);
//	return is;
//}


HighAcc::operator string()//stringǿ��ת��������
{
	int i;
	string s;
	for (i = m_size - 1; i >= 0; i--)
	{
		s.push_back(m_data[i] + '0');//push��string����ʱת��Ϊ�ַ���
	}
	return s;
}