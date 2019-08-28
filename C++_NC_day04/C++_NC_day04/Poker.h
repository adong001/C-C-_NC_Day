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

//1、声明一个扑克牌类，拥有方法：传入花色和点数生成扑克牌、打印扑克牌。
//2、声明一个玩家类，每人拥有18张扑克牌。拥有方法：增加手牌（摸牌）、展示手牌，其中展示手牌要求降序排序展示。
//完成程序：
//1、随机生成18张扑克牌，当做一个玩家的手牌。
//2、用54张不同的扑克牌构成牌堆，发给3个玩家。

class Poker//扑克牌类
{
	int type;//花色
	int point;//点数
public:
	void InputPoker(Poker *pk, int type, int point);//传入花色和点数
	void OutputPoker(Poker *pk);//打印扑克牌
	int ReturnType();//得到私有成员的值
	int ReturnPoint();
	void hh();
	void ChangePoint(int Point);//改变私有成员的值
};


class Player//玩家类
{
	Poker pk[POKERNUM];//18张扑克牌
public:
	void AddPoker(Player &pl);//增加手牌
	void ShowPoker(Player &pl);//展示手牌
};

bool CmpPokerPoint1(Poker a, Poker b);//只按点数从小到大排

bool CmpPokerPoint2(Poker a, Poker b);//只按点数从大到小排

bool CmpPokerPoint3(Poker a, Poker b);//斗地主模式排序

void DealPoker(Player pl[], int players);//给三个人发牌

void InsertSort(Poker *pk, int size, bool(*cmp)(Poker, Poker) = CmpPokerPoint2);//排序
void PlayTest1();
void PlayTest2();
