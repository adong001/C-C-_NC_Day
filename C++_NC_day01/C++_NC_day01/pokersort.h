#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<iostream>
#include<cstdio>
using namespace std;
enum
{
	BLACK,//黑桃
	HEART,//红桃
	CLUBS,//梅花
	DIAMONDS//方片
};

struct Poker
{
	char type;
	int point;
};

void InputPoker(Poker *pk,int size);

void OutputPoker(Poker *pk);


bool CmpPokerPoint1(Poker a, Poker b);//只按点数从小到大排

bool CmpPokerPoint2(Poker a, Poker b);//只按点数从大到小排


bool CmpPoker1(Poker a, Poker b);//先按点数从小到大排，再按花色从黑桃排到方块


bool CmpPoker2(Poker a, Poker b);//先按点数从大到小排，再按花色从黑桃排到方块


bool CmpPoker3(Poker a, Poker b);//斗地主模式排序


void InsertSort(Poker *pk, int size, bool(*cmp)(Poker, Poker) = CmpPokerPoint1);
//直接插入排序,使用缺省函数,如不传入参数，按默认按照只按点数从小到排序。

void PokerTest();
