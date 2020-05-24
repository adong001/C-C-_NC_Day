#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<mutex>
#include<map>
#include<string>
using namespace std;

map<string, string> g_m;
mutex mu;

void Set(const string& key, const string& value)//设置key-value
{
	mu.lock();
	g_m[key] = value;
	mu.unlock();
}

string Get(const string& key)//根据key查询value，如果key不存在，返货字符none
{
	mu.lock();
	if (g_m.count(key))
	{
		mu.unlock();
		return g_m[key];
	}
	mu.unlock();
	return "none";
}

int main()
{
    return 0;
}