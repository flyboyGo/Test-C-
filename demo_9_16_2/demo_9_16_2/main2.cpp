#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

//���ò����㷨

/*
find(iterator beg, iterator end, value)
find �㷨 ����Ԫ��
@param beg ������ʼ������  @param end ��������������
@param value ���ҵ�Ԫ��  @return ���ز���Ԫ�ص�λ��(ʧ�ܷ��� ������end())
*/
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
	int getAge(void)const
	{
		return this->age;
	}
	string getName(void)const
	{
		return this->name;
	}

	bool operator==(const Person & ob)
	{
		if (this->age == ob.getAge() && this->name == ob.getName())
		{
			return true;
		}
		return false;
	}
};

void test03()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);

	vector<int>::iterator ret = find(v.begin(), v.end(), 200);
	if (ret != v.end())
	{
		cout << *ret << endl;
	}
	else
	{
		cout << "δ�ҵ�" << endl;
	}

	vector<Person> v2;
	v2.push_back(Person("jack", 23));
	v2.push_back(Person("tim",28));
	v2.push_back(Person("nancy",18));
	v2.push_back(Person("rose", 25));

	Person tmp("tim", 28);
	vector<Person>::iterator ret2;
	//���� findѰ���Զ������� ��Ҫ����==
	ret2 = find(v2.begin(), v2.end(), tmp);
	if (ret2 != v2.end())
	{
		cout << (*(ret2)).getName() << ", " << (*(ret2)).getAge()<< endl;
	}
	else
	{
		cout << "δ�ҵ�" << endl;
	}
}

/*
find_if(iterator beg, iterator end, _callback);
find_if �㷨 ��������
@param beg ������ʼ������   @param end ��������������
@param callback �ص���������ν�� ( ���� bool ���͵ĺ������� )
@return bool ���ҷ��� true ���� false
*/

bool myGreaterThan20(int val)
{
	return val > 20;
}

class MyGreater
{
public:
	bool operator()(int val)
	{
		return val > 20;
	}
};

void test04()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);

	//Ѱ�ҵ�һ������20��
	vector<int>::iterator ret;
	//��ͨ����ʵ��
	ret = find_if(v.begin(),v.end(), myGreaterThan20);
	cout << *ret << endl;
	//�º���ʵ��
	ret = find_if(v.begin(), v.end(), MyGreater());
	cout << *ret << endl;
}


/*
adjacent_find(iterator beg, iterator end, _callback);
adjacent_find �㷨 ���������ظ�Ԫ��
@param beg ������ʼ������    @param end ��������������
@param _callback �ص���������ν�� ( ���� bool ���͵ĺ������� )
@return ��������Ԫ�صĵ�һ��λ�õĵ�����
*/

class PersonPlus
{
private:
	string name;
	int age;
public:
	PersonPlus(string name, int age)
	{
		this->name = name;
		this->age = age;
	}
	int getAge(void)const
	{
		return this->age;
	}
	string getName(void)const
	{
		return this->name;
	}

	bool operator==(const PersonPlus& ob)
	{
		if (this->age == ob.getAge() && this->name == ob.getName())
		{
			return true;
		}
		return false;
	}
};

bool MyEqual(PersonPlus& ob1, PersonPlus& ob2)
{
	if (ob1.getAge() == ob2.getAge() && ob1.getName() == ob2.getName())
	{
		return true;
	}
	return false;
}

void test05()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);
	v.push_back(50);

	vector<int>::iterator ret;
	//���ڻ����������� ����Ҫ�ص�����
	ret = adjacent_find(v.begin(),v.end());
	if (ret != v.end())
	{
		cout << "Ѱ�ҵ��ظ����ݣ�" << *ret << endl;
	}

	vector<PersonPlus> v2;
	vector<PersonPlus>::iterator ret2;
	v2.push_back(PersonPlus("jack", 23));
	v2.push_back(PersonPlus("tim", 28));
	v2.push_back(PersonPlus("nancy", 18));
	v2.push_back(PersonPlus("nancy", 18));
	v2.push_back(PersonPlus("rose", 25));
	//�����Զ������� ��Ҫ
	//��ͨ������Ϊ�ص�����ָ������
	ret2 = adjacent_find(v2.begin(), v2.end() ,MyEqual);
	if (ret2 != v2.end())
	{
		cout << "Ѱ�ҵ��ظ����ݣ�" << (*ret2).getName() << ", " << (*ret2).getAge() << endl;
	}

	//����==�����
	ret2 = adjacent_find(v2.begin(), v2.end());
	if (ret2 != v2.end())
	{
		cout << "Ѱ�ҵ��ظ����ݣ�" << (*ret2).getName() << ", " << (*ret2).getAge() << endl;
	}
}

/*
bool binary_search(iterator beg, iterator end, value);
binary_search �㷨 ���ֲ��ҷ�
ע�� : �� "��������" �в�����
@param beg ������ʼ������   @param end ��������������
@param value ���ҵ�Ԫ��     @return bool ���ҷ��� true ���� false
*/

void test06()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);
	v.push_back(60);
	v.push_back(70);

	bool ret = binary_search(v.begin(),v.end(),200);
	if (ret == true)
	{
		cout << "�ҵ���" << endl;
	}
	else
	{
		cout << "δ����" << endl;
	}
	
}

//int main(int argc, char* argv[])
//{
//	//test03();
//
//	//test04();
//
//	//test05();
//
//	test06();
//
//	return 0;
//}