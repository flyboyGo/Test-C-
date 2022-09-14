#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <algorithm>

using namespace std;

class Person
{
friend bool myComparePerson(const Person& ob1, const Person& ob2);
private:
	string name;
	int age;
public:
	Person(string name, int age)
	{
		this->name = name;
		this->age = age;
	}

	int getAge(void)
	{
		return this->age;
	}
	string getName(void)
	{
		return this->name;
	}

	//��Ա�������� == �����
	bool operator==(const Person& ob)
	{
		if (this->name == ob.name && this->age == ob.age)
			return true;
		else
			return false;
	}

	//��Ա�������� < �����
	bool operator<(const Person& ob)
	{
		if (this->age > ob.age)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

};

void printfListPerson(list<Person> &L)
{
	for (list<Person>::iterator it = L.begin(); it != L.end(); it++)
	{
		cout << (*it).getName() << " ," << (*it).getAge() << endl;
	}
}

//1��list�����д���Զ������� ���ɾ��ĳ���ڵ� �������� == �����(��Ա����)
void test01()
{
	//����Զ�������
	list<Person> L;
	L.push_back(Person("jack",48));
	L.push_back(Person("tim", 16));
	L.push_back(Person("rose", 24));

	printfListPerson(L);

	//ɾ���Զ���Ԫ��
	Person p = Person("jack", 48);
	//���� == �����
	L.remove(p);

	printfListPerson(L);
}

//2��list�����д���Զ������� ������Զ����������� ���� ���� > �����(��Ա����)
void test02()
{
	//����Զ�������
	list<Person> L;
	L.push_back(Person("jack", 48));
	L.push_back(Person("tim", 16));
	L.push_back(Person("rose", 24));
	L.push_back(Person("nancy", 18));

	printfListPerson(L);

	L.sort();
}

//3��list��������Զ������� ������Զ����������� ���� ָ��������� ȫ�ֺ���(��Ԫ)
bool myComparePerson(const Person& ob1, const Person& ob2)
{
	//return ob1.age > ob2.age; //�Ӵ�С����
	return ob1.age < ob2.age; //��С��������
}

void test03()
{
	//����Զ�������
	list<Person> L;
	L.push_back(Person("jack", 48));
	L.push_back(Person("tim", 16));
	L.push_back(Person("rose", 24));
	L.push_back(Person("nancy", 18));

	//���ǿ��� ֱ��ָ���������
	L.sort(myComparePerson);

	printfListPerson(L);
}

//4��vector��������Զ������� ������Զ����������� ���� ָ���������
void PrintfVecotrPerson(vector<Person> &v)
{
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << (*it).getName() << " ," << (*it).getAge() << endl;
	}
}

class myComparePersonPlus
{
public:
	bool operator()(Person& ob1, Person& ob2)
	{
		return ob1.getAge() > ob2.getAge();
	}
};

void test04()
{
	vector<Person> v;
	v.push_back(Person("jack", 48));
	v.push_back(Person("tim", 16));
	v.push_back(Person("rose", 24));
	v.push_back(Person("nancy", 18));

	PrintfVecotrPerson(v);
	
	//sortĬ�ϱȽϷ�ʽ ��С����(ֻ���ǻ���������)
	//�Զ������� ���� �������� > ����� ���� �ֶ�ָ���������
	 
	//sort(v.begin(), v.end()); //���� > ����� ��Ա�������
	
	 //�ֶ�ָ������������� ��Ϊ ��ͨȫ�ֺ�������hanshu
	 //1��vector����Զ������� ָ��������� ��ͨȫ�ֺ������
	sort(v.begin(),v.end(),myComparePerson);
	PrintfVecotrPerson(v);

	//2��vector����Զ������� ����ָ��������� (������ָ���������)
	sort(v.begin(), v.end(), myComparePersonPlus());
	PrintfVecotrPerson(v);
}


//int main(int argc, char* argv[])
//{
//
//	return 0;
//}