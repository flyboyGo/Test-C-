#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>
#include <stdlib.h>
#include <time.h>

using namespace std;

//常用排序算法
/*
merge(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest)
merge 算法 容器元素合并，并存储到另一容器中
注意 : 两个容器必须是 "有序" 的
@param beg1 容器 1 开始迭代器
@param end1 容器 1 结束迭代器
@param beg2 容器 2 开始迭代器
@param end2 容器 2 结束迭代器
@param dest 目标容器开始迭代器
*/

void test09()
{
	vector<int> v1;
	v1.push_back(10);
	v1.push_back(30);
	v1.push_back(50);
	v1.push_back(70);

	vector<int> v2;
	v2.push_back(20);
	v2.push_back(40);
	v2.push_back(60);
	v2.push_back(80);

	vector<int> v3;
	//预先设置v3的大小
	v3.resize(v1.size() + v2.size());

	merge(v1.begin(),v1.end(),v2.begin(),v2.end(),v3.begin());

	for_each(v3.begin(), v3.end(), [](int val) {
		cout << val << " ";
	});
	cout << endl;
}

/*
sort(iterator beg, iterator end, _callback)
sort 算法 容器元素排序
@param beg 容器 1 开始迭代器
@param end 容器 1 结束迭代器
@param _callback 回调函数或者谓词 ( 返回 bool 类型的函数对象 )
*/

/*
random_shuffle(iterator beg, iterator end)
random_shuffle 算法 对指定范围内的元素随机调整次序
@param beg 容器开始迭代器
@param end 容器结束迭代器
*/

void test10()
{
	vector<int> v1;
	v1.push_back(10);
	v1.push_back(30);
	v1.push_back(50);
	v1.push_back(70);

	srand(time(NULL));
	random_shuffle(v1.begin(), v1.end());

	for_each(v1.begin(), v1.end(), [](int val) {
		cout << val << " ";
	});
	cout << endl;
}

/*
reverse(iterator beg, iterator end)
reverse 算法 反转指定范围的元素
@param beg 容器开始迭代器
@param end 容器结束迭代器
*/

void test11()
{
	vector<int> v1;
	v1.push_back(10);
	v1.push_back(30);
	v1.push_back(50);
	v1.push_back(70);

	for_each(v1.begin(), v1.end(), [](int val) {
		cout << val << " ";
	});
	cout << endl;

	reverse(v1.begin(), v1.end());
	for_each(v1.begin(), v1.end(), [](int val) {
		cout << val << " ";
	});
	cout << endl;
}


//int main(int argc, char* argv[])
//{
//
//	//test09();
//
//	//test10();
//
//	//test11();
//
//	return 0;
//}

