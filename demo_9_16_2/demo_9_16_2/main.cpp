#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//遍历算法

/*
* for_each(iterator beg, iterator end, _callback);  遍历算法 遍历容器元素
@param beg 开始迭代器   @param end 结束迭代器
@param _callback 函数回调或者函数对象  @return 函数对象
*/
void test01()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);

	for_each(v.begin(), v.end(), [](int val) {
		cout << val << " ";
	});
	cout << endl;
}

/*
transform(iterator beg1, iterator end1, iterator beg2, _callbakc);
transform 算法 将指定容器区间元素搬运到另一容器中
注意 : transform 不会给目标容器分配内存，所以需要我们 "提前分配好内存"
@param beg1 源容器开始迭代器    @param end1 源容器结束迭代器
@param beg2 目标容器开始迭代器  @param _cakkback 回调函数或者函数对象(将函数返回值 传递给目标容器)
@return 返回目标容器迭代器
*/

int myTransInt(int val)
{
	return val;
}

class MyTransInt
{
public:
	int operator()(int val)
	{
		return val;
	}
};

void test02()
{
	vector<int> v1;
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);

	vector<int> v2;
	//预先：设置v2的大小
	//v2.reserve(v1.size()); //error 只是预留了足够的空间 空间还需申请、初始化,无法直接使用
	v2.resize(v1.size());
	cout << "size = " << v2.size() << endl; // 0
	cout << "capacity = " << v2.capacity() << endl; // 4
	

	//将v1中的元素搬运到v2中
	//搬运的过程 不会主动申请空间 只是单纯将函数的返回值 赋值给 目标容器
	//普通函数
	//transform(v1.begin(), v1.end() - 1, v2.begin(), myTransInt);
	//仿函数
	transform(v1.begin(), v1.end(), v2.begin(), MyTransInt());

	for_each(v2.begin(), v2.end(), [](int val) {
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