#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//函数对象
/*
* 重载函数调用操作符的类，其对象常称为函数对象（function object），即它们是
行为类似函数的对象，也叫仿函数(functor),其实就是重载“()”操作符，使得类对象
可以像函数那样调用
*/

//谓词
/*
* 返回值类型为bool的普通函数、函数对象(仿函数) 叫做谓词
* 如果普通函数、仿函数 有一个参数 就叫做一元谓词
* 如果普通函数、仿函数 有二个参数 就叫做二元谓词
*/

//普通函数作为一元谓词
bool greaterThan20(int val)
{
	return val > 20;
}
//仿函数作为一元谓词
class MyGreaterThan20
{
public:
	bool operator()(int val)
	{
		return val > 20;
	}
};

void test01()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);

	for_each(v.begin(), v.end(), [](int val) {cout << val << " "; });
	cout << endl;

	//需求：找出第一个大于20的数
	vector<int>::iterator ret;
	//普通函数完成
	//ret = find_if(v.begin(), v.end(), greaterThan20);
	//仿函数完成
	ret = find_if(v.begin(), v.end(), MyGreaterThan20());
	if (ret != v.end())
	{
		cout << *ret << endl;
	}
	else
	{
		cout << "未找到" << endl;
	}
}

//二元谓词
//普通函数作为二元谓词
bool myGreater(int val1, int val2)
{
	return val1 > val2;
}

//仿函数作为二元谓词
class MyGreater
{
public:
	bool operator()(int val1, int val2)
	{
		return val1 > val2;
	}
};

void test02()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);

	for_each(v.begin(), v.end(), [](int val) {cout << val << " "; });
	cout << endl;

	//从大-->小 排序
	//普通函数
	//sort(v.begin(), v.end(), myGreater);
	//仿函数
	sort(v.begin(), v.end(), MyGreater());

	for_each(v.begin(), v.end(), [](int val) {cout << val << " "; });
	cout << endl;
}

//int main(int argc, char* argv[])
//{
//	//test01();
//
//	test02();
//
//	return 0;
//}