#pragma once
#include<iostream>
using namespace std;
#include<cstdio>
#include<cstdlib>
//
//д���������ú������صķ�ʽ��д����ͳ�Ƴ�һ���������ṹΪ��׼�Ľṹ�������У�
//1������ΪX�ĳ����˶��ٴ�
//2������ΪX�ĳ����˶��ٴ�
//3���༶ΪX�ĳ����˶��ٴ�
//4���Ա��X�ĳ����˶��ٴ�
//
//���磺����ΪX�Ŀ�����������������
//int countName(student * src, int n, char * name);
//tip:���Կ�����ȱʡ�����ķ�ʽ�����߻ص������ķ�ʽʵ�֡�

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