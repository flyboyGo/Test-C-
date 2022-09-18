#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Person
{
public:
	char name[32];
	int age;
public:
	Person()
	{
		*(this->name) = 0;
		this->age = 0;
	}
	Person(const char * name, int age)
	{
		strcpy(this->name, name);
		this->age = age;
	}
	char* getName(void)
	{
		return this->name;
	}
	void setName(const char* name)
	{
		strcpy(this->name, name);
	}
	int getAge(void)
	{
		return this->age;
	}
};

void test03()
{
	Person ob = Person("������", 25);
	cout << ob.getName() << endl;
	ob.setName("flyboy");
	cout << ob.getName() << endl;
}


//�������ļ� д�ļ�
void test04()
{
	//1������ͷ�ļ� fstream

	//2������������
	//ofstream ofs("person.txt", ios::out | ios::binary);
	ofstream ofs;

	//3��ָ���ļ��Ĵ򿪷�ʽ
	ofs.open("person.txt", ios::out | ios::binary);

	//4��д�ļ�
	Person ob = Person("������",25);
	ofs.write((const char*)&ob, sizeof(Person));

	//5���ر��ļ�
	ofs.close();
}

//�������ļ� ���ļ�
void test05()
{
	//1������ͷ�ļ� fstream

	//2������������
	//ifstream ifs("person.txt", ios::in | ios::binary);
	ifstream ifs;

	//3��ָ���ļ��Ĵ򿪷�ʽ���ж��Ƿ�ɹ�
	ifs.open("person.txt", ios::in | ios::binary);
	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ��!" << endl;
		return;
	}

	//4�����ļ�
	Person p;
	ifs.read((char*)&p, sizeof(Person));
	cout << "������" << p.getName() << ",���䣺" << p.getAge() << endl;

	//5���ر��ļ�
	ifs.close();
}

int main(int argc, char* argv[])
{
	test03();

	//test04();

	//test05();

	return 0;
}