#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

//常用查找算法

/*
find(iterator beg, iterator end, value)
find 算法 查找元素
@param beg 容器开始迭代器  @param end 容器结束迭代器
@param value 查找的元素  @return 返回查找元素的位置(失败返回 容器的end())
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
		cout << "未找到" << endl;
	}

	vector<Person> v2;
	v2.push_back(Person("jack", 23));
	v2.push_back(Person("tim",28));
	v2.push_back(Person("nancy",18));
	v2.push_back(Person("rose", 25));

	Person tmp("tim", 28);
	vector<Person>::iterator ret2;
	//对于 find寻找自定义数据 需要重载==
	ret2 = find(v2.begin(), v2.end(), tmp);
	if (ret2 != v2.end())
	{
		cout << (*(ret2)).getName() << ", " << (*(ret2)).getAge()<< endl;
	}
	else
	{
		cout << "未找到" << endl;
	}
}

/*
find_if(iterator beg, iterator end, _callback);
find_if 算法 条件查找
@param beg 容器开始迭代器   @param end 容器结束迭代器
@param callback 回调函数或者谓词 ( 返回 bool 类型的函数对象 )
@return bool 查找返回 true 否则 false
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

	//寻找第一个大于20的
	vector<int>::iterator ret;
	//普通函数实现
	ret = find_if(v.begin(),v.end(), myGreaterThan20);
	cout << *ret << endl;
	//仿函数实现
	ret = find_if(v.begin(), v.end(), MyGreater());
	cout << *ret << endl;
}


/*
adjacent_find(iterator beg, iterator end, _callback);
adjacent_find 算法 查找相邻重复元素
@param beg 容器开始迭代器    @param end 容器结束迭代器
@param _callback 回调函数或者谓词 ( 返回 bool 类型的函数对象 )
@return 返回相邻元素的第一个位置的迭代器
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
	//对于基本数据类型 不需要回调函数
	ret = adjacent_find(v.begin(),v.end());
	if (ret != v.end())
	{
		cout << "寻找到重复数据：" << *ret << endl;
	}

	vector<PersonPlus> v2;
	vector<PersonPlus>::iterator ret2;
	v2.push_back(PersonPlus("jack", 23));
	v2.push_back(PersonPlus("tim", 28));
	v2.push_back(PersonPlus("nancy", 18));
	v2.push_back(PersonPlus("nancy", 18));
	v2.push_back(PersonPlus("rose", 25));
	//对于自定义数据 需要
	//普通函数作为回调函数指定规则
	ret2 = adjacent_find(v2.begin(), v2.end() ,MyEqual);
	if (ret2 != v2.end())
	{
		cout << "寻找到重复数据：" << (*ret2).getName() << ", " << (*ret2).getAge() << endl;
	}

	//重载==运算符
	ret2 = adjacent_find(v2.begin(), v2.end());
	if (ret2 != v2.end())
	{
		cout << "寻找到重复数据：" << (*ret2).getName() << ", " << (*ret2).getAge() << endl;
	}
}

/*
bool binary_search(iterator beg, iterator end, value);
binary_search 算法 二分查找法
注意 : 在 "无序序列" 中不可用
@param beg 容器开始迭代器   @param end 容器结束迭代器
@param value 查找的元素     @return bool 查找返回 true 否则 false
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
		cout << "找到了" << endl;
	}
	else
	{
		cout << "未到了" << endl;
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