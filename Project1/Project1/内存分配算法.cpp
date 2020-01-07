#include"�ڴ�����㷨.h"

int Partition::PartitionNum = 0;
int PCB::PCBNum = 0;
Partition* partition;
PCB* pcb;
int MIN;


void ReadData()//��������
{
	ifstream readData;
	readData.open("data.txt");

	readData >> Partition::PartitionNum;//�����������
	partition = new Partition[Partition::PartitionNum];//���ռ�

	for (int i = 0; i < Partition::PartitionNum; i++)//���������ʼ��ַ
	{
		readData >> partition[i].m_PartitionId;
		partition[i].m_BlockId = partition[i].m_PartitionId;
	}
	for (int i = 0; i < Partition::PartitionNum; i++)//���������С
	{
		readData >> partition[i].m_PartitionSize;
	}

	//readData >> PCB::PCBNum;//�����������
	//pcb = new PCB[PCB::PCBNum];

	//for (int i = 0; i < PCB::PCBNum; i++)//�����������
	//{
	//	readData >> pcb[i].m_PidName;
	//}

	//for (int i = 0; i < PCB::PCBNum; i++)//������̴�С
	//{
	//	readData >> pcb[i].m_PidSize;
	//}
	//readData.close();
}

void FirstFit()//�״���Ӧ�㷨
{
	bool flag = false;
	int i, j;
	string choose;
	ReadData();
	//cout << "����MIN:";
	//cin >> MIN;
	//Display_PCB();
	do
	{
		Display_Partition();
		pcb = (PCB*)realloc(pcb, sizeof(PCB)*(PCB::PCBNum + 1));
		cout << "����������ƣ�";
		cin >> pcb[PCB::PCBNum - 1].m_PidName;
		cout << "������̴�С:";
		cin >> pcb[PCB::PCBNum - 1].m_PidSize;

		i = PCB::PCBNum - 1;

		for (j = 0; j < Partition::PartitionNum; j++)
		{
			if (pcb[i].m_PidSize <= partition[j].m_PartitionSize)
			{
				partition[j].m_PartitionSize -= pcb[i].m_PidSize;
				partition[j].m_BlockId += partition[j].m_PartitionSize;
				if (partition[j].m_PartitionSize <= MIN)
				{
					partition[j].m_PartitionSize = 0;
				}
				flag = true;
				break;
			}
		}
		if (flag)
		{
			flag = false;
			cout << "����" << pcb[i].m_PidName << "���䵽����" << partition[j].m_PartitionId << endl;
		}
		else
		{
			cout << "����" << pcb[i].m_PidName << "����ʧ�ܣ�" << endl;
		}
		Display1();
		cout << "�������䰴Y" << endl;
		cin >> choose;

	} while (choose == "Y");
}
void NextFit()//ѭ���״���Ӧ�㷨
{
	int pos = 0;
	bool flag = false;
	int i, j;
	string choose;
	ReadData();
	//Display_PCB();
	/*cout << "����MIN:";
	cin >> MIN;*/
	do
	{

		Display_Partition();
		pcb = (PCB*)realloc(pcb, sizeof(PCB)*(PCB::PCBNum+1));
		cout << "����������ƣ�";
		cin >> pcb[PCB::PCBNum - 1].m_PidName;
		cout << "������̴�С:";
		cin >> pcb[PCB::PCBNum - 1].m_PidSize;
		i = PCB::PCBNum - 1;

		for (j = pos;; j++)
		{
			if (pos >= PCB::PCBNum)
			{
				pos = 0;
			}
			if (pcb[i].m_PidSize <= partition[j].m_PartitionSize)
			{
				partition[j].m_PartitionSize -= pcb[i].m_PidSize;
				partition[j].m_BlockId += partition[j].m_PartitionSize;
				if (partition[j].m_PartitionSize <= MIN)
				{
					partition[j].m_PartitionSize = 0;
				}
				flag = true;
				pos = j + 1;
				if (pos == PCB::PCBNum)
				{
					pos = 0;
				}
				break;
			}
		}
		if (flag)
		{
			flag = false;
			cout << "����" << pcb[i].m_PidName << "���䵽����" << partition[j].m_PartitionId << endl;
		}
		else
		{
			cout << "����" << pcb[i].m_PidName << "����ʧ�ܣ�" << endl;
		}
		Display1();
		cout << "�������䰴Y" << endl;
		cin >> choose;

	} while (choose == "Y");

}
void BestFit()//�����Ӧ�㷨
{
	int pos = 0;
	bool flag = false;
	int i, j;
	multimap<int, Partition*> m;
	multimap<int, Partition*>::iterator ip;
	string choose;
	ReadData();
	//Display_PCB();
	/*cout << "����MIN:";
	cin >> MIN;*/
	do
	{
		Display_Partition();
		pcb = (PCB*)realloc(pcb, sizeof(PCB)*(PCB::PCBNum + 1));
		cout << "����������ƣ�";
		cin >> pcb[PCB::PCBNum - 1].m_PidName;
		cout << "������̴�С:";
		cin >> pcb[PCB::PCBNum - 1].m_PidSize;
		i = PCB::PCBNum - 1;

		m.clear();
		for (j = 0; j < Partition::PartitionNum; j++)//����С��������
		{
			m.insert(make_pair(partition[j].m_PartitionSize, partition + j));
		}

		for (ip = m.begin(); ip != m.end();)
		{
			if (pcb[i].m_PidSize <= ip->first)
			{
				ip->second->m_PartitionSize -= pcb[i].m_PidSize;
				ip->second->m_BlockId += ip->second->m_PartitionSize;
				/*if (ip->second->m_PartitionSize <= MIN)
				{
				ip->second->m_PartitionSize = 0;
				}*/
				flag = true;
				break;
			}
			else
			{
				ip++;
			}
		}
		if (flag)
		{
			flag = false;
			cout << "����" << pcb[i].m_PidName << "���䵽����" << ip->second->m_PartitionId << endl;
		}
		else
		{
			cout << "����" << pcb[i].m_PidName << "����ʧ�ܣ�" << endl;
		}
		Display();
		cout << "�������䰴Y" << endl;
		cin >> choose;

	} while (choose == "Y");
}
void WorstFit()//���Ӧ�㷨
{
	int pos = 0;
	bool flag = false;
	int i, j;
	multimap<int, Partition*, greater<int>> m;
	multimap<int, Partition*>::iterator ip = m.begin();
	string choose;
	ReadData();
	//Display_PCB();
	/*cout << "����MIN:";
	cin >> MIN;*/
	do
	{
		Display_Partition();
		pcb = (PCB*)realloc(pcb, sizeof(PCB)*(PCB::PCBNum + 1));
		cout << "����������ƣ�";
		cin >> pcb[PCB::PCBNum - 1].m_PidName;
		cout << "������̴�С:";
		cin >> pcb[PCB::PCBNum - 1].m_PidSize;
		i = PCB::PCBNum - 1;

		m.clear();
		for (j = 0; j < Partition::PartitionNum; j++)//���Ӵ�С����
		{
			m.insert(make_pair(partition[j].m_PartitionSize, partition + j));
		}

		for (ip = m.begin(); ip != m.end();)
		{
			if (pcb[i].m_PidSize <= ip->first)
			{
				ip->second->m_PartitionSize -= pcb[i].m_PidSize;
				ip->second->m_BlockId += ip->second->m_PartitionSize;
				/*if (ip->second->m_PartitionSize <= MIN)
				{
				ip->second->m_PartitionSize = 0;
				}*/
				flag = true;
				break;
			}
			else
			{
				ip++;
			}
		}
		if (flag)
		{
			flag = false;
			cout << "����" << pcb[i].m_PidName << "���䵽����" << ip->second->m_PartitionId << endl;
		}
		else
		{
			cout << "����" << pcb[i].m_PidName << "����ʧ�ܣ�" << endl;
		}
		Display();
		cout << "�������䰴Y" << endl;
		cin >> choose;

	} while (choose == "Y");
}
void Display()
{
	int i;
	set<int> s;
	for (i = 0; i < Partition::PartitionNum; i++)
	{
		s.insert(partition[i].m_PartitionSize);
	}

	cout << "�հ׷�����:";
	for (auto& e : s)
	{
		cout << e << "->";
	}
	cout << "NULL";
	cout << endl;
}

void Display1()
{
	int i;
	map<int, Partition*> m;
	for (i = 0; i < Partition::PartitionNum; i++)
	{
		m.insert(make_pair(partition[i].m_PartitionId, partition + i));
	}

	cout << "�հ׷�����:";
	for (auto& e : m)
	{
		if (e.second->m_PartitionSize != 0)
		{
			cout << e.second->m_PartitionSize << "->";
		}
	}
	cout << "NULL";
	cout << endl;
}
void Display_Partition()
{
	cout << endl << "������ʼ��ַ ";
	for (int i = 0; i < Partition::PartitionNum; i++)
	{
		printf("%-d  ", partition[i].m_PartitionId);
	}
	cout << endl << "������С:   ";
	for (int i = 0; i < Partition::PartitionNum; i++)
	{

		printf("%-d  ", partition[i].m_PartitionSize);

	}
	cout << endl << endl;
}

void Display_PCB()
{
	cout << endl << "����id:  ";
	for (int i = 0; i < PCB::PCBNum; i++)
	{
		printf("%3s  ", pcb[i].m_PidName.c_str());
	}
	cout << endl << "���̴�С:";
	for (int i = 0; i < PCB::PCBNum; i++)
	{
		printf("%3d  ", pcb[i].m_PidSize);
	}
	cout << endl << endl;
}