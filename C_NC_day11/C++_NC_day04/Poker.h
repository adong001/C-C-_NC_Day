#pragma once 
#include<iostream>
#include<time.h>
#include<cstdlib>
#include<cstdio>
using namespace std;
#define POKERNUM 18
#define TYPE 5
#define POINT 15
#define PLAYERS 54/POKERNUM

//1������һ���˿����࣬ӵ�з��������뻨ɫ�͵��������˿��ơ���ӡ�˿��ơ�
//2������һ������࣬ÿ��ӵ��18���˿��ơ�ӵ�з������������ƣ����ƣ���չʾ���ƣ�����չʾ����Ҫ��������չʾ��
//��ɳ���
//1���������18���˿��ƣ�����һ����ҵ����ơ�
//2����54�Ų�ͬ���˿��ƹ����ƶѣ�����3����ҡ�

class Poker//�˿�����
{
	int type;//��ɫ
	int point;//����
public:
	void InputPoker(Poker *pk, int type, int point);//���뻨ɫ�͵���
	void OutputPoker(Poker *pk);//��ӡ�˿���
	int ReturnType();//�õ�˽�г�Ա��ֵ
	int ReturnPoint();
	void hh();
	void ChangePoint(int Point);//�ı�˽�г�Ա��ֵ
};


class Player//�����
{
	Poker pk[POKERNUM];//18���˿���
public:
	void AddPoker(Player &pl);//��������
	void ShowPoker(Player &pl);//չʾ����
};

bool CmpPokerPoint1(Poker a, Poker b);//ֻ��������С������

bool CmpPokerPoint2(Poker a, Poker b);//ֻ�������Ӵ�С��

bool CmpPokerPoint3(Poker a, Poker b);//������ģʽ����

void DealPoker(Player pl[], int players);//�������˷���

void InsertSort(Poker *pk, int size, bool(*cmp)(Poker, Poker) = CmpPokerPoint2);//����
void PlayTest1();
void PlayTest2();
