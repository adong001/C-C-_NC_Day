#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<iostream>
#include<cstdio>
using namespace std;
enum
{
	BLACK,//����
	HEART,//����
	CLUBS,//÷��
	DIAMONDS//��Ƭ
};

struct Poker
{
	char type;
	int point;
};

void InputPoker(Poker *pk,int size);

void OutputPoker(Poker *pk);


bool CmpPokerPoint1(Poker a, Poker b);//ֻ��������С������

bool CmpPokerPoint2(Poker a, Poker b);//ֻ�������Ӵ�С��


bool CmpPoker1(Poker a, Poker b);//�Ȱ�������С�����ţ��ٰ���ɫ�Ӻ����ŵ�����


bool CmpPoker2(Poker a, Poker b);//�Ȱ������Ӵ�С�ţ��ٰ���ɫ�Ӻ����ŵ�����


bool CmpPoker3(Poker a, Poker b);//������ģʽ����


void InsertSort(Poker *pk, int size, bool(*cmp)(Poker, Poker) = CmpPokerPoint1);
//ֱ�Ӳ�������,ʹ��ȱʡ����,�粻�����������Ĭ�ϰ���ֻ��������С������

void PokerTest();
