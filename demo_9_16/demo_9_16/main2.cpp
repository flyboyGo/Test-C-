#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//内建函数对象
/*
* STL 内建了一些函数对象。分为:算数类函数对象,关系运算类函数对象，逻辑运算
  类仿函数。这些仿函数所产生的对象，用法和一般函数完全相同，当然我们还可以
  产生无名的临时对象来履行函数功能。使用内建函数对象，需要引入头文件
*/

void test03()
{
	//加法内建函数对象
	plus<int> p;
	cout << p(10, 20) << endl;
	cout << plus<int>()(100, 200) << endl;
}

void test04()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);

	for_each(v.begin(), v.end(), [](int val) {cout << val << " "; });
	cout << endl;

	//使用内建函数对象 排序 改变排序规则
	sort(v.begin(),v.end(),greater<int>());
}

//int main(int argc, char* argv[])
//{
//	//test03();
//
//	test04();
//	
//	return 0;
//}