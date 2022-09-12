#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

//���������Զ�����������

class Person;

void myPrintPerson(Person& ob);

class Person
{
	friend void myPrintPerson(Person& ob);
private:
	string name;
	int age;
public:
	Person(string name, int age)
	{
		this->name = name;
		this->age = age;
	}
};

void myPrintPerson(Person& ob)
{
	cout << "name = " << ob.name << " age = " << ob.age << endl;
}

void test03()
{
	Person ob = Person("flyboy", 23);
	Person ob2 = Person("������", 24);
	Person ob3 = Person("jack", 35);

	//����һ��vector���� ����Զ�������Person
	vector<Person> v;
	v.push_back(ob);
	v.push_back(ob2);
	v.push_back(ob3);

	//for_each��ӡ����
	for_each(v.begin(), v.end(), myPrintPerson);
}

//����Ƕ��
void test04()
{
	vector<int> v1;
	vector<int> v2;
	vector<int> v3;

	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);

	v2.push_back(100);
	v2.push_back(200);
	v2.push_back(300);
	v2.push_back(400);

	v3.push_back(1000);
	v3.push_back(2000);
	v3.push_back(3000);
	v3.push_back(4000);

	//������ һ��vector ��� v1��v2��v3
	vector<vector<int>> v;
	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);


	//forѭ������
	for (vector<vector<int>>::iterator it = v.begin(); it != v.end(); it++)
	{
		//*it �ȼ��� vector<int> v1��v2��v3
		for (vector<int>::iterator mit = (*it).begin(); mit != (*it).end(); mit++)
		{
			//*mit �ȼ��� int
			cout << *mit << " ";
		}
		cout << endl;
	}
}


int main(int argc, char* argv[])
{
	//test03();

	test04();

	return 0;
}