#include"student.h"

void Test1()
{
	int ar[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	for (auto i : ar)
	{
		cout << i << " ";
	}
	cout << endl;
}


void InputData(student *stu,int size) //添加信息函数
{
	printf("请输入姓名：");
	cin >> stu[size].Name;
	//scanf("%49s", stu[size].Name);
	getchar();//先把\n吃了
	printf("请输入年龄：");
	cin >> stu[size].Age;
	//scanf("%d", &stu[size].Age);
	printf("请输入班级：");
	//scanf("%d", &stu[size].Class);
	cin >> stu[size].Class;
	printf("请输入性别(1/0)：");
	//scanf("%d", stu[size].Sex);
	cin>>stu[size].Sex;
}

int Count(student * src, int n, char * name)
{
	int i;
	int count = 0;
	for (i = 0; i < n; i++)
	{
		if (strcmp(src[i].Name, name)==0)
		{
			count++;
		}
	}
	return count;
}

int Count(student * src, int n, int Age)
{
	int i;
	int count = 0;
	for (i = 0; i < n; i++)
	{
		if (src[i].Age == Age)
		{
			count++;
		}
	}
	return count;
}

int Count(student * src, int n, short Class)
{
	int i;
	int count = 0;
	for (i = 0; i < n; i++)
	{
		if (src[i].Class == Class)
		{
			count++;
		}
	}
	return count;
}
int Count(student * src, int n, bool Sex)
{
	int i;
	int count = 0;
	for (i = 0; i < n; i++)
	{
		if (src[i].Sex == Sex)
		{
			count++;
		}
	}
	return count;
}

void Test2()
{
	student *stu = nullptr;
	int i = 0;
	int flag = 1;
	int choice;
	cout << "继续输入请按1，输入结束请按0:\n";
	while (flag)
	{
		cin >> choice;
		getchar();
		switch (choice)
		{
		case 1:
		{
				  stu = (student*)realloc(stu, sizeof(student)*(i + 1));
				  InputData(stu,i);
				  i++;
				  break;
		}
		case 0:
		{
				  flag = 0;
				  break;
		}
		}
	}
	int ret;
	char name[100];
	bool sex;
	short _class;
	int age;
	while (1)
	{
	cout << " 1、查名字为X的出现了多少次\n"
		"  2、查性别的X的出现了多少次\n"
		" 3、查班级为X的出现了多少次\n"
		" 4、查年龄为X的出现了多少次\n";
	cin >> ret;
	
		switch (ret)
		{
		case 1:{
				   cout << "请输入你要查找的人的姓名：";
				   cin >> name;
				   cout << "共查找到" << Count(stu, i, name) << "人\n";
				   break;
		}

		case 2:{
				   cout << "请输入你要查找的性别：";
				   cin >> sex;
				   cout << "共查找到" << Count(stu, i, sex) << "人\n";
				   break;
		}

		case 3:{
				   cout << "请输入你要查找的班级：";
				  cin>> _class;
				   cout << "共查找到" << Count(stu, i, _class) << "人\n";
				   break;
		}

		case 4:{
				   cout << "请输入你要查找人的年龄：";
				   cin>>age;
				   cout << "共查找到" << Count(stu, i, age) << "人\n";
				   break;
		}
		default:break;
		}
	}

	free(stu);
}