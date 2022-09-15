#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

//�޸�set������Ĭ���������(������������)

class MyGreater
{
public:
	bool operator()(int val1, int val2)
	{
		return val1 > val2;
	}
};

bool MyGreaterPlus(int val1, int val2)
{
	return val1 > val2;
}

//void test06()
//{
//	//Ĭ�ϴ�  С->�� ����
//	//�����  ��->С ����
//	//set<int,�������> s;
//
//	//1��ʹ�÷º��� ���set��������������ָ��
//	set<int, MyGreater> s;
//	s.insert(30);
//	s.insert(10);
//	s.insert(50);
//	s.insert(20);
//	s.insert(40);
//
//	for_each(s.begin(), s.end(), [](int val) {
//		cout << val << " ";
//	});
//	cout << endl;
//
//	//2��set����ָ��������� �޷�ʹ����ͨ����ʵ��
//	//set<int, MyGreaterPlus> s; //error
//}


//set������� "�Զ�������" ��ʱ�� "����" ָ���������
class Person
{
private:
	string name;
	int age;
public:
	Person(string name, int age)
	{
		this->name = name;
		this->age = age;
	}
	string getName(void) 
	{
		return this->name;
	}
	int getAge(void) const
	{
		return this->age;
	}

	//����һ ���� < ����� �� С �� ��
	bool operator<(const Person& ob) const
	{
		return this->age < ob.age;
	}
};

class MyGreaterPerson
{
public:
	bool operator()(const Person& ob1, const Person& ob2)
	{
		return ob1.getAge() < ob2.getAge();
	}
};

void test07()
{
	//2�������� ָ���������
	set<Person,MyGreaterPerson> s;
	s.insert(Person("����",50));
	s.insert(Person("����", 24));
	s.insert(Person("Ы��", 500));
	s.insert(Person("�ɶ�", 45));

	for_each(s.begin(), s.end(), [](Person val) {
		cout << "name = " << val.getName() << ", age = " << val.getAge() << endl;
	});
}

//int main(int argc, char* argv[])
//{
//	//test06();
//
//	test07();
//
//	return 0;
//}