#include"�ڴ�����㷨.h"

int main()
{
	int choose;
	/*map<int, string, greater<int>> m;
	m.insert(make_pair(3, "C"));
	m.insert(make_pair(1, "A"));
	m.insert(make_pair(7, "E"));
	m.insert(make_pair(2, "B"));
	m.insert(make_pair(5, "D"));
	for (auto& e : m)
	{
		cout << e.first << " " << e.second << endl;
	}*/

	while (1)
	{
		cout << "��ѡ��ʵ�ֵ��㷨��" << endl;
		cout << "*****  1 - �״���Ӧ�㷨     *****" << endl;
		cout << "*****  2 - ѭ���״���Ӧ�㷨 *****" << endl;
		cout << "*****  3 - �����Ӧ�㷨     *****" << endl;
		cout << "*****  4 - ���Ӧ�㷨     *****" << endl;
		cout << "*****  0 - ����             *****" << endl;
		cout << "�������ѡ�� �� ";
		cin >> choose;
		switch (choose)
		{
			
			case 0:exit(0); break;
			case 1:FirstFit(); break;
			case 2:NextFit(); break;
			case 3:BestFit(); break;
			case 4:WorstFit(); break;
			default:cout << "��������ȷ����ţ�" << endl;
		}
	}
    system("pause");
    return 0;
}