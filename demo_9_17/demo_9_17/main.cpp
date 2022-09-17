#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
#include <numeric>

using namespace std;

/*
accumulate(iterator beg, iterator end, value)
accumulate 算法 计算容器元素累计总和
@param beg 容器开始迭代器  @param end 容器结束迭代器
@param value 累加值
*/

void test01()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);

	cout << "sum = " << accumulate(v.begin(),v.end(),0) << endl;
}

/*
fill(iterator beg, iterator end, value)
fill 算法 向容器中添加元素
@param beg 容器开始迭代器   @param end 容器结束迭代器
@param value t 填充元素
*/

void test02()
{
	vector<int> v;
	//预先设置大小
	v.resize(5);
	fill(v.begin(),v.end(),100);

	for_each(v.begin(), v.end(), [](int val) {
		cout << val << " ";
	});
	cout << endl;
}


//int main(int argc, char* argv[])
//{
//	test01();
//
//	test02();
//
//	return 0;
//}