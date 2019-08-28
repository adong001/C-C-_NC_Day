#include"student.h"
/*1、总结课堂知识，以这些基础语法的思维导图为核心，写一篇博客*/ 
//2、使用范围for，通过输入为一个数组赋值 Test1()
//3、有以下结构：
//
//struct student{
//char name[32];
//int age;
//int class;
//bool sex;
//};

//写出函数，用函数重载的方式编写程序，统计出一个以上述结构为基准的结构体数组中：
//1、名字为X的出现了多少次
//2、年龄为X的出现了多少次
//3、班级为X的出现了多少次
//4、性别的X的出现了多少次
//
//例如：名字为X的可以是这样的声明：
//int countName(student * src, int n, char * name);
//tip:可以考虑用缺省参数的方式，或者回调函数的方式实现。
int main()
{
	/*student std[10] ;
	InputStu(std);*/
	//int i = 10;
	//auto a = i;//C++11版本才有auto
	//cout << typeid(a).name() << endl;
	//if (strcmp(typeid(a).name(), "int"))
	//{
	//	cout << "asxadasda" << endl;
	//}
	Test2();
    system("pause");
    return 0;
}