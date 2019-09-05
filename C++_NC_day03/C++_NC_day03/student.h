#pragma once
#include<iostream>
using namespace std;
#include<cstdio>
#include<cstdlib>
struct student{
	char Name[32];
	bool Sex;
	short Class;
	int Age;	
};

void InputData(student *stu);
int Count(student * stu, int n, char * name);
int Count(student * stu, int n, int Age);
int Count(student * stu, int n, short Class);
int Count(student * stu, int n, bool Sex);

//void FindCount(student *stu,int n,int(*count)(student*,int ) = Count1)//º¯ÊıÈ±Ê¡
void Test2();
void Test1();