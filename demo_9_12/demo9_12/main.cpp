#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//1、vector 迭代器
/*
* Vector 维护一个线性空间，所以不论元素的型别如何，普通指针都可以作为
  vector 的迭代器，因为 vector 迭代器所需要的操作行为，如 operaroe, operator->,
  operator++, operator--, operator+, operator-, operator+=, operator-=, 普通指针天生具备。 
  Vector 支持随机存取，而普通指针正有着这样的能力。
  所以 vector 提供的是随机访问迭代器 (Random Access Iterators). 
  根据上述描述，如果我们写如下的代码： Vector::iterator it1; Vector::iterator it2; 
  it1 的型别其实就是 Int,it2 的型别其实就是 Teacher*
*/

//2、vector容器的容量 >= 元素的个数 原因vector的未雨绸缪机制
void test01()
{
	vector<int> v;
	int i = 0;
	for (i = 0; i < 100; i++)
		v.push_back(i);
	cout << "v的容量capacity: " << v.capacity() << endl;
	cout << "v的大小size:" << v.size() << endl;
}

//3、vector 单端动态数组

//4、vector 另寻地址的次数

void test02()
{
	vector<int> v;
	int* p = NULL;
	int count = 0; //记录另寻地址的次数

	for (int i = 0; i < 100; i++)
	{
		v.push_back(i);
		if (p != &v[0]) //如果p不等于&a[0] 说明另寻了一次空间
		{
			count++;
			p = &v[0];
		}
	}

	cout << "另寻地址的次数: " << count << endl;
}

//5、vector的未雨绸缪机制(了解)
void test03()
{
	vector <int>  v;
	cout << "capacity =" << v.capacity() << ", size = " << v.size() << endl; // 0 0
	int* p = NULL;
	int count = 0;
	for (int i = 0; i < 1000; i++)
	{
		v.push_back(i);
		if (p != &v[0])
		{
			cout << "-------------" << count++ << "---------------" << endl;
			p = &v[0];
		}
		cout << "capacity =" << v.capacity() << ", size = " << v.size() << endl;
	}
}

//6、vector的数据结构

//7、vector的常用API

/*
* 3.2.4.1 vector 构造函数
  vector<T> v; // 采用模板实现类实现，默认构造函数
*/

void printfVectorInt(vector<int>& v)
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test04()
{
	//vector(n, elem);// 构造函数将 n 个 elem 拷贝给本身。
	vector<int> v = vector<int>(10, 5);
	printfVectorInt(v);

	//vector(v.begin(), v.end());// 将 v[begin(), end()) 区间中的元素拷贝给本身。
	vector<int> v2 = vector<int>(v.begin()+2, v.end()-2);
	printfVectorInt(v2);

	// vector(const vector &vec);// 拷贝构造函数。
	vector<int> v3 = vector<int>(v2);
	printfVectorInt(v3);
}

/*
* 3.2.4.2 vector 常用赋值操作
*/

void test05()
{
	vector<int> v = vector<int>(5,0);
	vector<int> v2;

	//vector& operator=(const vector &vec);// 重载等号操作符
	v2 = v;
	printfVectorInt(v2);

	//assign(n, elem);// 将 n 个 elem 拷贝赋值给本身。
	vector<int> v3;
	v3.assign(5,4);
	printfVectorInt(v3);

	//assign(beg, end);// 将 [beg, end) 区间中的数据拷贝赋值给本身。
	vector<int> v4;
	v4.assign(v3.begin(), v3.end());
	printfVectorInt(v4);

	//swap(vec);// 将 vec 与本身的元素互换。
	vector<int> v5 = vector<int>(5, 8);
	vector<int> v6 = vector<int>(5, 1);
	printfVectorInt(v5);
	printfVectorInt(v6);
	v5.swap(v6);
	printfVectorInt(v5);
	printfVectorInt(v6);
}

/*
* 3.2.4.3 vector 大小操作
size();// 返回容器中元素的个数
capacity();// 容器的容量
*/

void test06()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	//empty();// 判断容器是否为空
	cout << v.empty() << endl;

	//resieze() 只作用于容器的元素的个数 不会改变容器的容量
	 
	//resize(int num);// 重新指定容器的长度为 num ，若容器变长，则以默认值填充新位
	//置。如果容器变短，则末尾超出容器长度的元素被删除。
	printfVectorInt(v);
	v.resize(6);
	printfVectorInt(v); // 10 20 30 40 50 0
	v.resize(3);
	printfVectorInt(v); // 10 20 30

	//resize(int num, elem);// 重新指定容器的长度为 num ，若容器变长，则以 elem 值填
	//充新位置。如果容器变短，则末尾超出容器长 > 度的元素被删除。
	v.resize(5,70);
	printfVectorInt(v); // 10 20 30 70 70
	v.resize(2);
	printfVectorInt(v); // 10 20

	//reserve(int len);// 容器预留 len 个元素长度（不改变容器的元素的个数 但改变元素的容量),
	//预留位置不初始化，元素不可访问。
	cout << "size = " << v.size() << endl;
	cout << "capacity = " << v.capacity() << endl;
	v.reserve(10);
	cout << "size = " << v.size() << endl;
	cout << "capacity = " << v.capacity() << endl;
}

//需求：收缩容器的容量(使用resize swap)
void test07()
{
	vector<int> v;
	for (int i = 0; i < 1000; i++)
	{
		v.push_back(i);
	}
	cout << "size = " << v.size() << endl;
	cout << "capacity = " << v.capacity() << endl;
	v.resize(10); //不能修改容器的容量 只能修改容器中元素的数量
	cout << "size = " << v.size() << endl;
	cout << "capacity = " << v.capacity() << endl;

	//使用swap收缩容器的容量
	//将v的实际元素的个数 复制给 匿名容器
	//匿名容器 与 v容器 交换空间
	vector<int>(v).swap(v);
	cout << "size = " << v.size() << endl;
	cout << "capacity = " << v.capacity() << endl;
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
//	//test04();
//
//	//test05();
//
//	//test06();
//
//	test07();
//
//	return 0;
//}