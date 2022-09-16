#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>

using namespace std;

/*
count(iterator beg, iterator end, value);数值统计
count 算法 统计元素出现次数
@param beg 容器开始迭代器
@param end 容器结束迭代器
@param value 回调函数或者谓词 ( 返回 bool 类型的函数对象 )
@return int 返回元素个数
*/

void test07()
{
	vector<int> v;
	v.push_back(30);
	v.push_back(40);
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);

	cout << "个数为：" << count(v.begin(), v.end(), 30) << endl;
}

/*
count_if(iterator beg, iterator end, _callback); 条件统计
count_if 算法 统计元素出现次数
@param beg 容器开始迭代器
@param end 容器结束迭代器
@param callback 回调函数或者谓词(返回 bool 类型的函数对象)
@return int 返回元素个数
*/

bool myGreaterThan30(int val)
{
	return val > 30;
}

class MyGreater
{
public:
	bool operator()(int val)
	{
		return val > 30;
	}
};

void test08()
{
	vector<int> v;
	v.push_back(40);
	v.push_back(10);
	v.push_back(20);
	v.push_back(40);

	//普通函数实现
	cout << count_if(v.begin(), v.end(), myGreaterThan30) << endl;
	//函数对象(仿函数)
	cout << count_if(v.begin(), v.end(), MyGreater()) << endl;
	//内建函数对象
	cout << count_if(v.begin(), v.end(), bind2nd(greater<int>(),30)) << endl;
}

//int main(int argc, char* argv[])
//{
//	//test07();
//
//	test08();
//
//	return 0;
//}