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
	Person ob = Person("李鹏飞", 25);
	cout << ob.getName() << endl;
	ob.setName("flyboy");
	cout << ob.getName() << endl;
}


//二进制文件 写文件
void test04()
{
	//1、包含头文件 fstream

	//2、创建流对象
	//ofstream ofs("person.txt", ios::out | ios::binary);
	ofstream ofs;

	//3、指定文件的打开方式
	ofs.open("person.txt", ios::out | ios::binary);

	//4、写文件
	Person ob = Person("李鹏飞",25);
	ofs.write((const char*)&ob, sizeof(Person));

	//5、关闭文件
	ofs.close();
}

//二进制文件 读文件
void test05()
{
	//1、包含头文件 fstream

	//2、创建流对象
	//ifstream ifs("person.txt", ios::in | ios::binary);
	ifstream ifs;

	//3、指定文件的打开方式并判断是否成功
	ifs.open("person.txt", ios::in | ios::binary);
	if (!ifs.is_open())
	{
		cout << "文件打开失败!" << endl;
		return;
	}

	//4、读文件
	Person p;
	ifs.read((char*)&p, sizeof(Person));
	cout << "姓名：" << p.getName() << ",年龄：" << p.getAge() << endl;

	//5、关闭文件
	ifs.close();
}

int main(int argc, char* argv[])
{
	test03();

	//test04();

	//test05();

	return 0;
}