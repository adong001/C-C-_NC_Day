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


void InputData(student *stu,int size) //�����Ϣ����
{
	printf("������������");
	cin >> stu[size].Name;
	//scanf("%49s", stu[size].Name);
	getchar();//�Ȱ�\n����
	printf("���������䣺");
	cin >> stu[size].Age;
	//scanf("%d", &stu[size].Age);
	printf("������༶��");
	//scanf("%d", &stu[size].Class);
	cin >> stu[size].Class;
	printf("�������Ա�(1/0)��");
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
	cout << "���������밴1����������밴0:\n";
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
	cout << " 1��������ΪX�ĳ����˶��ٴ�\n"
		"  2�����Ա��X�ĳ����˶��ٴ�\n"
		" 3����༶ΪX�ĳ����˶��ٴ�\n"
		" 4��������ΪX�ĳ����˶��ٴ�\n";
	cin >> ret;
	
		switch (ret)
		{
		case 1:{
				   cout << "��������Ҫ���ҵ��˵�������";
				   cin >> name;
				   cout << "�����ҵ�" << Count(stu, i, name) << "��\n";
				   break;
		}

		case 2:{
				   cout << "��������Ҫ���ҵ��Ա�";
				   cin >> sex;
				   cout << "�����ҵ�" << Count(stu, i, sex) << "��\n";
				   break;
		}

		case 3:{
				   cout << "��������Ҫ���ҵİ༶��";
				  cin>> _class;
				   cout << "�����ҵ�" << Count(stu, i, _class) << "��\n";
				   break;
		}

		case 4:{
				   cout << "��������Ҫ�����˵����䣺";
				   cin>>age;
				   cout << "�����ҵ�" << Count(stu, i, age) << "��\n";
				   break;
		}
		default:break;
		}
	}

	free(stu);
}