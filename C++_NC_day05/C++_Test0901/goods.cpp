#include"goods.h"

int Goods::s_kinds = 0;
double Goods::s_discount = 1;
Goods * Goods::s_point = NULL;

void Goods::GoodsSet(char *name,double price, int amount)
{
	strcpy_s(m_name, name);
	m_price = price * s_discount;
	m_amount = amount;
}

void Goods::PushGoods()//����
{
	Goods *goods = s_point;
	int choice;
	char tmp_name[20];
	double tmp_price;
	int tmp_amount;
	while(1)
	{
		cout << "\t\t\t\t����1������0�˳�\n";
		cin >> choice;
		if (choice == 0)
		{
			break;
		}
		
		goods = (Goods*)realloc(goods, sizeof(Goods)*(s_kinds + 1));
		s_point = goods;//realloc���ٿռ���ܻ�ı�ԭ���ĵ�ַ������ÿ�ζ���s_pointָ���һ������ĵ�ַ
		cout << "\t\t\t\t������Ʒ���ƣ�";
		cin >> tmp_name;
		cout << "\t\t\t\t������Ʒ�۸�";
		cin >> tmp_price;	
		cout << "\t\t\t\t������Ʒ������";
		cin >> tmp_amount;

		goods[s_kinds].GoodsSet(tmp_name, tmp_price , tmp_amount );
		s_kinds++;
	}
}

void Goods::Purchase(Goods *goods)//����
{
	double discount;
	cout << "t\t\t\t������Ҫ����ۿۣ�(8��-8,9.5��-9.5)";
	cin >> discount;
	s_discount = discount * 0.1;
	for (int i = 0; i < s_kinds; i++)
	{
		goods[i].m_price *= s_discount;
	}
}

void Goods::ShowGoods(Goods *goods)//��ʾ������Ʒ��Ϣ
{
	if (!goods)
	{
		cout << "\t\t\t\t��û����\n";
		return ;
	}
	int i;
	printf("\n\n\n\t\t\t\t\t\t����������Ʒ��Ϣ\n\n");
	printf("\t\t\t\t��Ʒ����\t   ����(Kg/Ԫ)\t\t���� \n\n");
	for (i = 0; i < s_kinds; i++)
	{
		printf("\t\t\t\t%-20s%-20f%-20d\n", goods[i].m_name, goods[i].m_price, goods[i].m_amount);
	}
	cout<<"\n\n\t\t\t\t����"<<s_kinds<<"����Ʒ\n";
}
Goods* Goods::ReturnAdr()
{
	return  s_point;
}

void BossMenu()
{
	int choice;
	while (1)
	{
		printf("\n\n\n\t\t\t\t��ӭ����������Ʒ����ϵͳ--BOSSģʽ\n\n\n\n");
		printf("\t\t\t\t1.����\n\n");
		printf("\t\t\t\t2.��ʾ������Ʒ��Ϣ\n\n");
		printf("\t\t\t\t3.�����\n\n");
		printf("\t\t\t\t4.�˳�\n\n");
		cin >> choice;
		system("cls");
		switch (choice)
		{
		case 1:Goods::PushGoods(); break;
		case 2:Goods::ShowGoods(Goods::ReturnAdr()); break;
		case 3:Goods::Purchase(Goods::ReturnAdr()); break;
		case 4: exit(0); break;
		default: printf("��������!!!"); break;
		}
	}
}

