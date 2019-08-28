#pragma once
#include<iostream>
using namespace std;
#include<cstdio>
#include<cstdlib>
//
//写出函数，用函数重载的方式编写程序，统计出一个以上述结构为基准的结构体数组中：
//1、名字为X的出现了多少次
//2、年龄为X的出现了多少次
//3、班级为X的出现了多少次
//4、性别的X的出现了多少次
//
//例如：名字为X的可以是这样的声明：
//int countName(student * src, int n, char * name);
//tip:可以考虑用缺省参数的方式，或者回调函数的方式实现。

struct student{
	char Name[32];
	bool Sex;
	short Class;
	int Age;	
};

void InputData(student *stu);
int Count(student * src, int n, char * name);
int Count(student * src, int n, int Age);
int Count(student * src, int n, int Class);
int Count(student * src, int n, bool Sex);
void Test2();
void Test1();