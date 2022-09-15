#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std;

//map容器概述
/*
* 
1、Map 的特性是，所有元素都会根据元素的键值自动排序。
2、Map 所有的元素都是pair,同时拥有实值和键值,pair 的第一元素被视为键值,第二元素被视为实值
   map 不允许两个元素有相同的键值
3、我们可以通过 map 的迭代器改变 map 的键值吗？答案是不行,因为 map 的键值关系到 map 元素的排列规则，
   任意改变 map键值将会严重破坏 map 组织。如果想要修改元素的实值，那么是可以的。
   Map容器的键值不可变,实值不可变
4、Multimap 和 map 的操作类似，唯一区别 multimap 键值可重复。Map 和 multimap 都是以红黑树为底层实现机制
*/

/*
* 3.8.2 map/multimap  常用 API

3.8.2.1 map 构造函数
map<T1, T2> mapTT;//map 默认构造函数 :
map(const map &mp);// 拷贝构造函数

3.8.2.2 map 赋值操作
map& operator=(const map &mp);// 重载等号操作符
swap(mp);// 交换两个集合容器

3.8.2.3 map 大小操作
size();// 返回容器中元素的数目
empty();// 判断容器是否为空

3.8.2.4 map 插入数据元素操作
map.insert(...); // 往容器插入元素，返回 pair<iterator,bool>
map<int, string> mapStu;
// 第一种 通过 pair 的方式插入对象
mapStu.insert(pair<int, string>(3, "小张"));
// 第二种 通过 pair 的方式插入对象
mapStu.inset(make_pair(-1, "校长"));
// 第三种 通过 value_type 的方式插入对象
mapStu.insert(map<int, string>::value_type(1, "小李"));
// 第四种 通过数组的方式插入值
mapStu[3] = "小刘";
mapStu[5] = "小王";
*/

void myPrintfMap(map<int, string> &map)
{
	for (auto it = map.begin(); it != map.end(); it++)
	{
		cout << (*it).first << " = " << (*it).second << endl;
	}
}

void test01()
{
	
	//int 为键值的类型 string是为实值的类型
	map<int, string> map;

	//插入的第一种方式
	map.insert(pair<int,string>(9527,"星爷"));

	//插入的第二种方式
	map.insert(make_pair(10086,"移动"));

	//插入的第三种方式
	//map.insert(map<int, string>::value_type(10010, "联通"));

	//插入的第四种方式 读取map容器时 推荐
	map[10010] = "电信"; //等价于map.insert(pair<int,string>(10010,"电信"));
	
	//map[10] 寻找key为10的实值
	//cout << map[10] << endl;(这种形式的访问 10最好是存在的)
	//但是如果 容器中没有 key为10  会创建一个 key为10 实值为空值 的对组
	//如果容器中有key为10 那么map[10]代表key = 10的实值

	//只想查看key == 9527的 实值(实值确实存在)
	cout << map[9527] << endl;

	//(实值不一定存在)
	auto ret = map.find(10086);
	if (ret == map.end())
	{
		cout << "未找到" << endl;
	}
	else
	{
		//ret代表的是key为10085的对组的迭代器
		cout << "找到相关节点：" << "key = "<< (*ret).first << "，value = " << (*ret).second << endl;
	}
	

	//遍历map容器 第一种方式
	for_each(map.begin(), map.end(), [](pair<int,string> val) {
		cout << val.first << " = " << val.second << endl;
	});

	//遍历map容器 第二种方式
	myPrintfMap(map);
}

/*
* 3.8.2.5 map 删除操作
clear();// 删除所有元素
erase(pos);// 删除 pos 迭代器所指的元素，返回下一个元素的迭代器。
erase(beg,end);// 删除区间 [beg,end) 的所有元素 ，返回下一个元素的迭代器。
erase(keyElem);// 删除容器中 key 为 keyElem 的对组。

3.8.2.6 map 查找操作
find(key);// 查找键 key 是否存在 , 若存在，返回该键的元素的迭代器；若不存在，返回 map.end();
count(keyElem);// 返回容器中 key 为 keyElem 的对组个数。
               对 map 来说，要么是 0 ，要么是 1 。对 multimap 来说，值可能大于 1 。

lower_bound(keyElem);// 返回第一个 key>=keyElem 元素的迭代器。
upper_bound(keyElem);// 返回第一个 key>keyElem 元素的迭代器。
equal_range(keyElem);// 返回容器中 key 与 keyElem 相等的上下限的两个迭代器。
*/

//map容器与vector容器配合使用
//案例：4个战队 随机抽签出场 请打印出场顺序
#include<numeric> //极少的算法
void test02()
{
	//战队容器(战队编号、战队名称)
	map<int, string> map;
	map.insert(make_pair(1, "RNG"));
	map.insert(make_pair(2, "IG"));
	map.insert(make_pair(3, "EDG"));
	map.insert(make_pair(4, "WE"));

	//使用vector容器存放站队编号
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);

	//随机抽签(洗牌) 打乱容器中的元素顺序
	//设置随机种子
	srand(time(NULL));
	random_shuffle(v.begin(),v.end());

	//随机出场
	//= 是读操作 外部数据 &是传递外部数据的引用 可以读写操作
	for_each(v.begin(), v.end(), [&](int key) {
		//val 就是map容器中的key值
		cout << map[key] << endl;
	});
}


//multimap容器允许key相同，map不允许key相同
void test03()
{

	//战队容器(战队编号、战队名称)
	map<int, string> map;
	map.insert(make_pair(1, "RNG"));
	map.insert(make_pair(1, "IG"));

	cout << map[1] << endl;
	cout << map.count(1) << endl; //1

	multimap<int, string> m1;
	m1.insert(make_pair(1,"RNG"));
	m1.insert(make_pair(1, "IG"));
	cout << m1.count(1) << endl; //2
}

//int main(int argc, char* argv[])
//{
//	//test01();
//
//	//test02();
//
//	test03();
//
//	return 0;
//}