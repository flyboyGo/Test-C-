#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>

using namespace std;

class Person
{
private:
	string name;
	int age;
public:
	Person()
	{

	}
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

	void showPerson(void)
	{
		cout << "name = " << this->name << " , age = " << this->age << endl;
	}
};

void MyPrintfPerson(Person &ob)
{
	cout << "name = " << ob.getName() << " , age = " << ob.getAge() << endl;
}

//成员函数适配器
void test08()
{
	vector<Person> v;
	v.push_back(Person("jack",23));
	v.push_back(Person("tim", 38));
	v.push_back(Person("nancy", 18));
	v.push_back(Person("helle", 25));

	//lambda表达式
	for_each(v.begin(), v.end(), [](Person &ob) {
		cout << "name = " << ob.getName() << " , age = " << ob.getAge() << endl;
	});

	//普通函数
	for_each(v.begin(), v.end(), MyPrintfPerson);

	//成员函数 
	// 利用 mem_fun_ref 将 Person 内部成员函数适配
	for_each(v.begin(), v.end(), mem_fun_ref(&Person::showPerson));
}


//函数指针适配器
void MyPrintInt(int val,int tmp)
{
	cout << val + tmp << " ";
}
void test09()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(5);

	//普通函数需要使用ptr_fun 转换成函数指针
	for_each(v.begin(),v.end(), bind2nd(ptr_fun(MyPrintInt),1000));
	cout << endl;
}

int main(int argc, char* argv[])
{
	//test08();

	test09();

	return 0;
}