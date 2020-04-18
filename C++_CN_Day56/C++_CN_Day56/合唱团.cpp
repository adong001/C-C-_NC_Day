#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>

struct Person
{
	int num;
	int weight;
	int height;

	friend std::istream & operator >> (std::istream &is, Person &p);
	bool operator >(const Person& p)
	{
		return ((weight >= p.weight) && (height >= p.height));
	}
};

std::istream & operator >> (std::istream &is, Person &p)
{
	is >> p.num >> p.weight >> p.height;
	return is;
}

int main()
{
	int N;
	while (std::cin >> N)
	{
		int count = 0;
		Person *p = new Person[N];
		for (int i = 0; i < N; i++)
		{
			std::cin >> p[i];
		}
		
	}
    return 0;
}