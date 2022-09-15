#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

//������5��Ա�� �ֵ�3������
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
	string getName(void) const
	{
		return this->name;
	}
	int getAge(void) const
	{
		return this->age;
	}
};

void createVectorPerson(vector<Person> &v)
{
	v.push_back(Person("jack",23));
	v.push_back(Person("tim", 37));
	v.push_back(Person("rose", 25));
	v.push_back(Person("nancy", 18));
	v.push_back(Person("flyboy", 25));
}

void PersonByGroup(vector<Person> &v, multimap<int, Person> &m)
{
	//�����Ա�����ɵ� ����������
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		//*it == Person
		cout << "������Ա����" << (*it).getName() << " ��Ҫ����Ĳ��ţ�1��2��3" << endl;
		int num = 0; //���ź�
		cin >> num;
		if (num >= 1 && num <= 3)
		{
			m.insert(make_pair(num, *it));
		}
	}
}

void showPersonList(multimap<int, Person> &m, int num)
{
	switch (num)
	{
	case 1:
		cout << "�з�����" << endl;
		break;
	case 2:
		cout << "���Բ���" << endl;
		break;
	case 3:
		cout << "���²���" << endl;
		break;
	}

	//ע�⣺m�д�ŵ�����(���źš�Ա����Ϣ)
	//ͳ�Ʋ��źŵ�Ԫ�ظ���
	int n = m.count(num);
	cout << "���ŵ��������� ��" << n << endl;
	//���� multimap��key�Զ����� �ظ� ��ͬ��keyֵһ������һ��
	multimap<int, Person>::const_iterator ret;
	ret = m.find(num);
	if (ret != m.end()) //Ѱ�ҵ�keyֵ
	{
		for (int i = 0; i < n; i++,ret++)
		{
			cout << "���źţ�" << (*ret).first << ", Ա����Ϣ" << ((*ret).second).getName() << " " << ((*ret).second).getAge() << endl;
		}
	}

}
void test04()
{
	//vector������5��Ա����Ϣ�洢����
	vector<Person> v;

	//����5��Ա��
	createVectorPerson(v);

	//��Ա�����䵽��ͬ�Ĳ���(Ա��<���źš�Ա����Ϣ>)
	multimap<int, Person> m; //���Ա��<���źš�Ա����Ϣ>
	PersonByGroup(v,m);

	//�����Ų鿴Ա����Ϣ
	showPersonList(m, 1);
	showPersonList(m, 2);
	showPersonList(m, 3);
}

//int main(int argc, char* argv[])
//{
//	test04();
//
//	return 0;
//}