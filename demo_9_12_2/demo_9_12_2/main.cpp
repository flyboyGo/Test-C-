#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

//deque容器 双端动态数组
/*
* Vector 容器是单向开口的连续内存空间，deque 则是一种双向开口的连续线性空
间。所谓的双向开口，意思是可以在头尾两端分别做元素的插入和删除操作，当
然，vector 容器也可以在头尾两端插入元素，但是在其头部操作效率奇差，无法被接受

Deque 容器和 vector 容器最大的差异，
一在于 deque 允许使用常数项时间对头端进行元素的插入和删除操作(不会因为数据量的大小 改变操作所耗的时间)。
二在于 deque 没有容量的概念，因为它是动态的以分段连续空间组合而成，随时可以增加一段新的空间并链接起来

 Deque 是由一段一段的定量的连续空间构成。一旦有必要在 deque 前端或者尾端增加新的空间，
 便配置一段连续定量的空间，串接在deque 的头端或者尾端。
 Deque 最大的工作就是维护这些分段连续的内存空间的整体性的假象，并提供随机存取的接口，
 避开了重新配置空间，复制，释放的轮回，代价就是复杂的迭代器架构。

 既然 deque 是分段连续内存空间，那么就必须有中央控制，维持整体连续的假象，
 数据结构的设计及迭代器的前进后退操作颇为繁琐。
 Deque 代码的实现远比 vector 或 list 都多得多。 
 Deque 采取一块所谓的map(注意，不是 STL 的 map 容器)作为主控，这里所谓的 map 是一小块连续的内
 存空间，其中每一个元素(此处成为一个结点)都是一个指针，指向另一段连续性内存空间，称作缓冲区。
 缓冲区才是 deque 的存储空间的主体。
*/


//deque容器的API

/*
* 3.3.3.1 deque 构造函数
deque<T> deqT;// 默认构造形式
deque(const deque &deq);// 拷贝构造函数。
*/

void printfDequeInt(deque<int> &d)
{
	for (deque<int>::iterator it = d.begin(); it != d.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test01()
{
	//deque(n, elem);// 构造函数将 n 个 elem 拷贝给本身。
	deque<int> d = deque<int>(5, 10);
	printfDequeInt(d);

	//deque(beg, end);// 构造函数将 [beg, end) 区间中的元素拷贝给本身。
	deque<int> d2 = deque<int>(d.begin() + 1, d.end() - 1);
	printfDequeInt(d2);
}

/*
* 3.3.3.2 deque 赋值操作
assign(beg, end);// 将 [beg, end) 区间中的数据拷贝赋值给本身。
swap(deq);// 将 deq 与本身的元素互换
*/
void test02()
{
	//assign(n, elem);// 将 n 个 elem 拷贝赋值给本身。
	deque<int> d = deque<int>();
	d.assign(6,7);
	printfDequeInt(d);

	//deque& operator=(const deque &deq); // 重载等号操作符
	deque<int> d2 = d;
	printfDequeInt(d);

	deque<int> d3 = deque<int>(5, 1);
	deque<int> d4 = deque<int>(5, 2);
	d3.swap(d4);
	printfDequeInt(d3);
	printfDequeInt(d4);
}


/*
* 3.3.3.3 deque 大小操作
deque.size();// 返回容器中元素的个数
deque.empty();// 判断容器是否为空
deque.resize(num);// 重新指定容器的长度为 num, 若容器变长，则以默认值填充新位置。
                     如果容器变短，则末尾超出容器长度的元素被删除。
deque.resize(num, elem); // 重新指定容器的长度为 num, 若容器变长，则以 elem 值填充新位置 , 
                            如果容器变短，则末尾超出容器长度的元素被删除。
*/


/*
* 3.3.3.4 deque 双端插入和删除操作
*/

void test03()
{
	deque<int> d;

	//push_back(elem);// 在容器尾部添加一个数据
	d.push_back(3);
	d.push_back(4);
	d.push_back(5);
	printfDequeInt(d);

	//push_front(elem);// 在容器头部插入一个数据
	d.push_front(2);
	d.push_front(1);
	printfDequeInt(d);

	//pop_back();// 删除容器最后一个数据
	d.pop_back();
	d.pop_back();
	printfDequeInt(d);

	//pop_front();// 删除容器第一个数据
	d.pop_front();
	printfDequeInt(d);

	cout << "容器是否为空：" << d.empty() << endl; // 0

	cout << "容器的大小：" << d.size() << endl; // 0
}

/*
3.3.3.5 deque 数据存取
*/
void test04()
{
	deque<int> d;
	d.push_back(1);
	d.push_back(2);
	d.push_back(3);
	d.push_back(4);
	d.push_back(5);
	printfDequeInt(d);

	//at(idx);// 返回索引 idx 所指的数据，如果 idx 越界，抛出 out_of_range 。
	cout << d.at(2) << endl;
	//operator[];// 返回索引 idx 所指的数据，如果 idx 越界，不抛出异常，直接出错。
	cout << d[3] << endl;
	//front();// 返回第一个数据。
	cout << d.front() << endl;
	//back();// 返回最后一个数据
	cout << d.back() << endl;

	//可以进行赋值操作
	d.at(2) = 4;
	d[3] = 3;
	d.front() = 5;
	d.back() = 1;
	printfDequeInt(d);
}

/*
3.3.3.6 deque 插入操作
insert(pos,elem);// 在 pos 位置插入一个 elem 元素的拷贝，返回新数据的位置。
insert(pos,n,elem);// 在 pos 位置插入 n 个 elem 数据，无返回值。
insert(pos,beg,end);// 在 pos 位置插入 [beg,end) 区间的数据，无返回值。
*/

void test05()
{
	deque<int> d;
	d.insert(d.begin(),1);
	d.insert(d.begin() + 1, 1, 2);
	d.insert(d.begin() + 2, d.begin(), d.end());
	printfDequeInt(d);
}

/*
3.3.3.7 deque 删除操作
clear();// 移除容器的所有数据
erase(beg,end);// 删除 [beg,end) 区间的数据，返回下一个数据的位置。
erase(pos);// 删除 pos 位置的数据，返回下一个数据的位置。
*/

void test06()
{
	deque<int> d;
	d.push_back(1);
	d.push_back(2);
	d.push_back(3);
	d.push_back(4);
	d.push_back(5);
	printfDequeInt(d);
	d.erase(d.begin() + 1, d.end() - 1);
	printfDequeInt(d);
	d.erase(d.begin());
	printfDequeInt(d);
	d.clear();
	printfDequeInt(d);
}

//int main(int argc, char* argv[])
//{
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
//	test06();
//
//	return 0;
//}