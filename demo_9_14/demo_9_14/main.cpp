#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

//set容器的概述
/*
* set中所有的容器会根据元素的 "键值" 自动被排序。
* Set 的元素不像 map 那样可以同时拥有实值和键值，set 的元素即是键值又是实值。
* Set 不允许两个元素有相同的键值。
* set容器提供的是"只读迭代器"(不允许用户修改元素的内容)
*/

/*
* 3.7.2.1 set 构造函数
set<T> st;//set 默认构造函数：
mulitset<T> mst; //multiset 默认构造函数 :
set(const set &st);// 拷贝构造函数

3.7.2.2 set 赋值操作
set& operator=(const set &st);// 重载等号操作符
swap(st);// 交换两个集合容器

3.7.2.3 set 大小操作
size();// 返回容器中元素的数目
empty();// 判断容器是否为空

*/
void test01()
{
	set<int> s = set<int>(); //set容器根据键值自动排序
	s.insert(30);
	s.insert(10);
	s.insert(50);
	s.insert(20);
	s.insert(40);

	for_each(s.begin(), s.end(), [](int val) {
		cout << val << " ";
	}); // 10 20 30 40 50
	cout << endl;

	//set容器提供的是只读迭代器const_iterator
	//用户不可以修改set容器的元素
	set<int>::iterator it = s.begin();
	//(*it) = 100; // error

	cout << "size = " << s.size() << endl;
}

/*
3.7.2.4 set 插入和删除操作
insert(elem);// 在容器中插入元素。
clear();// 清除所有元素
erase(pos);// 删除 pos 迭代器所指的元素，返回下一个元素的迭代器。
erase(beg, end);// 删除区间 [beg,end) 的所有元素 ，返回下一个元素的迭代器。
erase(elem);// 删除容器中值为 elem 的元素。
*/

void test02()
{
	set<int> s = set<int>(); //set容器根据键值自动排序
	s.insert(30);
	s.insert(10);
	s.insert(50);
	s.insert(20);
	s.insert(40);

	//根据元素的位置直接删除
	s.erase(s.begin());

	for_each(s.begin(), s.end(), [](int val) {
		cout << val << " ";
		});
	cout << endl;

	//根据元素直接删除
	s.erase(30);

	for_each(s.begin(), s.end(), [](int val) {
		cout << val << " ";
		});
	cout << endl;
}

/*
* 3.7.2.5 set 查找操作
find(key);// 查找键 key 是否存在,若存在,返回该键的元素的"迭代器";若不存在,返回 set.end();
count(key);// 查找键 key 的元素个数
*/

void test03()
{
	set<int> s = set<int>(); //set容器根据键值自动排序
	s.insert(30);
	s.insert(10);
	s.insert(50);
	s.insert(20);
	s.insert(40);

	//find(key);
	//查找键 key 是否存在,若存在,返回该键的元素的"迭代器";若不存在,返回 set.end();
	set<int>::const_iterator ret = s.find(20); //返回元素的迭代器
	if (ret == s.end())
	{
		cout << "没找到" << endl;
	}
	else
	{
		cout << "元素为：" << *ret << endl;
	}

	//count(key);// 查找键 key 的元素个数 返回值只能为 1 或 0
	//set容器的键值 是不重复的
	cout << s.count(10) << endl; //1
	cout << s.count(60) << endl; //0
}

/*
* 3.7.2.5.2 set 查找操作
lower_bound(keyElem);// 返回第一个 key>=keyElem 元素的 "迭代器"(下限)。
upper_bound(keyElem);// 返回第一个 key>keyElem 元素的 "迭代器"(上限)
equal_range(keyElem);// 返回容器中 key 与 keyElem 相等的上下限的 "两个迭代器"。
*/

void test04()
{
	set<int> s = set<int>(); //set容器根据键值自动排序
	s.insert(30);
	s.insert(10);
	s.insert(50);
	s.insert(20);
	s.insert(40);

	for_each(s.begin(), s.end(), [](int val) {
		cout << val << " ";
		});
	cout << endl;
	
	//lower_bound(keyElem);// 返回第一个 key>=keyElem 元素的 "迭代器"(下限)。
	set<int>::const_iterator lower_ret = s.lower_bound(30);
	if (lower_ret == s.end())
	{
		cout << "未找到" << endl;
	}
	else
	{
		cout << "下限为：" << *lower_ret << endl;
	}

	//upper_bound(keyElem);// 返回第一个 key>keyElem 元素的 "迭代器"(上限)
	set<int>::const_iterator upper_ret = s.upper_bound(30);
	if (upper_ret == s.end())
	{
		cout << "未找到" << endl;
	}
	else
	{
		cout << "上限为：" << *upper_ret << endl;
	}

	//equal_range(keyElem);// 返回容器中 key 与 keyElem 相等的上下限的 "两个迭代器"
	//equal_range 返回的是对组
	//first 对组中的第一个值  second 对组中的第二个值 
	pair<set<int>::const_iterator, set<int>::const_iterator> pair_ret;
	pair_ret = s.equal_range(30);
	//下限lower_bound
	if (pair_ret.first == s.end())
	{
		cout << "未找到" << endl;
	}
	else
	{
		cout << "下限为：" << *pair_ret.first << endl;
	}
	//上限upper_bound
	if (pair_ret.second == s.end())
	{
		cout << "未找到" << endl;
	}
	else
	{
		cout << "上限为：" << *pair_ret.second << endl;
	}
}

//int main(int argc, char* argv[])
//{
//
//	//test01();
//
//	//test02();
//
//	//test03();
//
//	test04();
//
//	return 0;
//}