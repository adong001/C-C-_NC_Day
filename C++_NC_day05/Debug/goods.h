#pragma once
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
//����ĳ�ϰ���Ҫһ���ܿ��ټ��㶩���۸�ĳ�������������һ���ࣺ
//1�����������Ҫԭ�ۺ�������ԭ�۴�һ�������ж������ɣ����ж������飩��������Ҫ��ʼ����
//2���ϰ�᲻���ڵ����۸񣬵����ķ�ʽ��ͨ������һ���۸�ϵ�������ϵ������ԭ�ۼ�Ϊ���ռ۸�
//����ۿۻ�Ӱ�쵽���в�Ʒ��������Ƴ�һ���������ϰ����ɸ㶨��һ�С�
class Goods
{
private:
	static double s_discount;//�ۿ�
	static int s_kinds;//��Ʒ����
	static Goods *s_point;//��һ����Ա�ĵ�ַ
	char m_name[20];//��Ʒ����
	double m_price;//����
	int m_amount;//����
public:	
	static void Purchase(Goods *);//����
	static void ShowGoods(Goods *);//��ʾ������Ʒ��Ϣ
	static void PushGoods();//����
	void GoodsSet(char *name , double price, int amount);
	static Goods* ReturnAdr();
};
void BossMenu();

