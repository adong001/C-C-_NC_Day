//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
// class B0//基类BO声明
//
// { 
// public:
//	 //外部接口
//	 virtual void display()//虚成员函数 
//	 {    cout<<"B0::display0"<<endl;} 
// };
// class B1:public B0//公有派生 
// { public:   
//	 void display() 
//	 {
//		 cout<<"B1::display0"<<endl; 
//	 }
// }; 
// class D1: public B1//公有派生 
// {
// public:    
//	 void display(){ cout<<"D1::display0"<<endl; 
//	 } 
// }; 
// 
// void fun(B0 ptr)//普通函数
// {   
//	 ptr.display(); 
// }
//
// int main()//主函数 
// {   
//	 B0 b0;//声明基类对象和指针   
//	 B1 b1;//声明派生类对象    
//	 D1 d1;//声明派生类对象  
//	 fun(b0);//调用基类B0函数成员
//	 fun(b1);//调用派生类B1函数成员   
//	 fun(d1);//调用派生类D1函数成员 
//	 system("pause");
//	 return 0;
// }
