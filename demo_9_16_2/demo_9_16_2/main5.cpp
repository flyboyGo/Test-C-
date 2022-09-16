#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>
#include <stdlib.h>
#include <time.h>

using namespace std;

//常用拷贝和替换算法

/*
copy(iterator beg, iterator end, iterator dest)
copy 算法 将容器内指定范围的元素拷贝到另一容器中
@param beg 容器开始迭代器
@param end 容器结束迭代器
@param dest 目标起始迭代器
*/

#include <iterator>

void test12()
{
	vector<int> v1;
	v1.push_back(10);
	v1.push_back(30);
	v1.push_back(50);
	v1.push_back(70);

	vector<int> v2;
	v2.resize(v1.size());
	copy(v1.begin(),v1.end(),v2.begin());

	for_each(v2.begin(), v2.end(), [](int val) {
		cout << val << " ";
	});
	cout << endl;

	//copy扩展 用copy输出
	//输出迭代器
	copy(v1.begin(), v1.end(), ostream_iterator<int>(cout," "));
}

/*
replace(iterator beg, iterator end, oldvalue, newvalue)
replace 算法 将容器内指定范围的旧元素修改为新元素
@param beg 容器开始迭代器
@param end 容器结束迭代器
@param oldvalue 旧元素
@param newvalue 新元素
*/

void test13()
{
	vector<int> v1;
	v1.push_back(10);
	v1.push_back(30);
	v1.push_back(50);
	v1.push_back(70);

	//将容器中的30 替换成 3000
	replace(v1.begin(), v1.end(), 30, 3000);

	copy(v1.begin(), v1.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	for_each(v1.begin(), v1.end(), [](int val) {
		cout << val << " ";
	});
	cout << endl;
}

/*
replace_if(iterator beg, iterator end, _callback, newvalue) 条件替换
replace_if 算法 将容器内指定范围满足条件的元素替换为新元素
@param beg 容器开始迭代器
@param end 容器结束迭代器
@param callback 函数回调或者谓词 ( 返回 Bool 类型的函数对象 )
@param oldvalue 新元素
*/

bool myReplace(int val)
{
	return val > 30;
}
class MyReplace
{
public:
	bool operator()(int val)
	{
		return val > 30;
	}
};
void test14()
{
	vector<int> v1;
	v1.push_back(10);
	v1.push_back(30);
	v1.push_back(50);
	v1.push_back(70);

	//将容器中的大于30 替换成 3000
	//普通函数
	replace_if(v1.begin(), v1.end(), myReplace, 3000);

	//函数对象
	replace_if(v1.begin(), v1.end(), MyReplace(), 3000);

	//内建函数对象
	replace_if(v1.begin(), v1.end(), bind2nd(greater<int>(),30), 3000);

	copy(v1.begin(), v1.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
}

/*
swap(container c1, container c2)
swap 算法 互换两个容器的元素
@param c1 容器 1
@param c2 容器 2
*/

int main(int argc, char* argv[])
{
	//test12();
	
	//test13();

	test14();

	return 0;
}