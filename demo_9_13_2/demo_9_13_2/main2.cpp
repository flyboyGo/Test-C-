#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <algorithm>

using namespace std;

//防函数概述
class MyAdd
{
public:
	//本质是成员函数 函数名叫  operator()
	int operator()(int a, int b)
	{
		cout << "调用了operator() int int" << endl;
		return a + b;
	}

	int operator()(int a, int b, int c)
	{
		cout << "调用了operator() int int int" << endl;
		return a + b + c;
	}
};

void test05()
{
	MyAdd ob1;
	cout << ob1.operator()(1, 10) << endl;
	//编译会优化运算符重载
	//严格意义：ob1是对象 和 () 结合调用operator()成员函数
	//ob1(1, 10) ob1本质是对象不是函数名 只是形式像函数调用
	//叫做防函数
	cout << ob1(1, 10) << endl;

	cout << MyAdd()(100, 200) << endl;
}

//lambda表达式
void printfVectorInt(vector<int> &v)
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << endl;
	}
}

//指定打印方式
void myPrint(int val)
{
	cout << val << " ";
}

void test06()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);

	//方法一：访问v容器 普通函数
	printfVectorInt(v);

	//方法二：访问v容器 系统算法for_each
	for_each(v.begin(),v.end(),myPrint);
	cout << endl;

	//方法三：访问v容器 lambda表达式 
	//[]表示函数名 ()参数列表 {}函数体
	for_each(v.begin(), v.end(), [](int val) {
		cout << val << " ";
	});
}

int main(int argc, char* argv[])
{
	test05();

	return 0;
}