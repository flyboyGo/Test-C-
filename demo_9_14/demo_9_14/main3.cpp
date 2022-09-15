#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

//修改set容器的默认排序规则(基本数据类型)

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
//	//默认从  小->大 排列
//	//需求从  大->小 排列
//	//set<int,排序规则> s;
//
//	//1、使用仿函数 完成set容器的排序规则的指定
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
//	//2、set容器指定排序规则 无法使用普通函数实现
//	//set<int, MyGreaterPlus> s; //error
//}


//set容器存放 "自定义数据" 的时候 "必须" 指定排序规则
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

	//方法一 重载 < 运算符 从 小 到 大
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
	//2、方法二 指定排序规则
	set<Person,MyGreaterPerson> s;
	s.insert(Person("德玛",50));
	s.insert(Person("皇子", 24));
	s.insert(Person("蝎子", 500));
	s.insert(Person("蒙多", 45));

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