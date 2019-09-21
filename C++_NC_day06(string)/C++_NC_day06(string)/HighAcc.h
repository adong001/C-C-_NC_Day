#pragma once
#include<iostream>
#include<cstring>
#include<string>
using namespace std;
#define NUMSIZE 10000

class HighAcc
{
private:
	char m_data[NUMSIZE];
	int m_size;
public:
	HighAcc() :
		m_size(1)
	{
		memset(m_data, 0, NUMSIZE);
	}
	HighAcc(string& s);
	HighAcc operator *(HighAcc& H);
	HighAcc operator +(HighAcc& H);
	/*void DealData();*/
	//friend ostream& operator <<(ostream& os, HighAcc& H);
	//friend istream& operator >>(istream& is, HighAcc& H);
	operator string();
};