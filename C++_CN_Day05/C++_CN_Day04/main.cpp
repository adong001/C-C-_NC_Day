//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
// class B0//����BO����
//
// { 
// public:
//	 //�ⲿ�ӿ�
//	 virtual void display()//���Ա���� 
//	 {    cout<<"B0::display0"<<endl;} 
// };
// class B1:public B0//�������� 
// { public:   
//	 void display() 
//	 {
//		 cout<<"B1::display0"<<endl; 
//	 }
// }; 
// class D1: public B1//�������� 
// {
// public:    
//	 void display(){ cout<<"D1::display0"<<endl; 
//	 } 
// }; 
// 
// void fun(B0 ptr)//��ͨ����
// {   
//	 ptr.display(); 
// }
//
// int main()//������ 
// {   
//	 B0 b0;//������������ָ��   
//	 B1 b1;//�������������    
//	 D1 d1;//�������������  
//	 fun(b0);//���û���B0������Ա
//	 fun(b1);//����������B1������Ա   
//	 fun(d1);//����������D1������Ա 
//	 system("pause");
//	 return 0;
// }
