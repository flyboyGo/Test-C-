#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

//1��set���������������ͬ��keyֵ
void test08()
{
	
	set<int> s;
	s.insert(10);
	s.insert(10);

	pair<set<int>::const_iterator, bool> ret1;
	pair<set<int>::const_iterator, bool> ret2;
	ret1 = s.insert(10);
	if (ret1.second == true)
	{
		cout << "��һ�β���ɹ�!" << endl;
	}
	else
	{
		cout << "��һ�β���ʧ��!" << endl;
	}

	ret2 = s.insert(10);
	if (ret2.second == true)
	{
		cout << "�ڶ��β���ɹ�!" << endl;
	}
	else
	{
		cout << "�ڶ��β���ʧ��!" << endl;
	}

	for_each(s.begin(), s.end(), [](int val) {
		cout << val << " ";
		});
	cout << endl;
}

void test09()
{
	multiset<int> s;
	s.insert(10);
	s.insert(10);

	for_each(s.begin(), s.end(), [](int val) {
		cout << val << " ";
		});
	cout << endl;
}

int main(int argc, char* argv[])
{
	test08();

	test09();

	return 0;
}