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

	//成员函数重载 == 运算符
	bool operator==(const Person& ob)
	{
		if (this->name == ob.name && this->age == ob.age)
			return true;
		else
			return false;
	}

	//成员函数重载 < 运算符
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

//1、list容器中存放自定义数据 如果删除某个节点 必须重载 == 运算符(成员函数)
void test01()
{
	//存放自定义数据
	list<Person> L;
	L.push_back(Person("jack",48));
	L.push_back(Person("tim", 16));
	L.push_back(Person("rose", 24));

	printfListPerson(L);

	//删除自定义元素
	Person p = Person("jack", 48);
	//重载 == 运算符
	L.remove(p);

	printfListPerson(L);
}

//2、list容器中存放自定义数据 如果对自定义数据排序 可以 重载 > 运算符(成员函数)
void test02()
{
	//存放自定义数据
	list<Person> L;
	L.push_back(Person("jack", 48));
	L.push_back(Person("tim", 16));
	L.push_back(Person("rose", 24));
	L.push_back(Person("nancy", 18));

	printfListPerson(L);

	L.sort();
}

//3、list容器存放自定义数据 如果对自定义数据排序 可以 指定排序规则 全局函数(友元)
bool myComparePerson(const Person& ob1, const Person& ob2)
{
	//return ob1.age > ob2.age; //从大到小排列
	return ob1.age < ob2.age; //从小到大排列
}

void test03()
{
	//存放自定义数据
	list<Person> L;
	L.push_back(Person("jack", 48));
	L.push_back(Person("tim", 16));
	L.push_back(Person("rose", 24));
	L.push_back(Person("nancy", 18));

	//我们可以 直接指定排序规则
	L.sort(myComparePerson);

	printfListPerson(L);
}

//4、vector容器存放自定义数据 如果对自定义数据排序 可以 指定排序规则
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
	
	//sort默认比较方式 从小到大(只能是基本数类型)
	//自定义类型 我们 可以重载 > 运算符 或者 手动指定排序规则
	 
	//sort(v.begin(), v.end()); //重载 > 运算符 成员函数完成
	
	 //手动指定排序排序规则 分为 普通全局函数、防hanshu
	 //1、vector存放自定义数据 指定排序规则 普通全局函数完成
	sort(v.begin(),v.end(),myComparePerson);
	PrintfVecotrPerson(v);

	//2、vector存放自定义数据 可以指定排序规则 (防函数指定排序规则)
	sort(v.begin(), v.end(), myComparePersonPlus());
	PrintfVecotrPerson(v);
}


//int main(int argc, char* argv[])
//{
//
//	return 0;
//}