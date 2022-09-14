#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <algorithm>
#include <list>

using namespace std;

//链表容器
//list容器(双向链表) 的迭代器 必须具备前移、后移 提供的是双向迭代器

//vector 单端动态数组 (随机访问迭代器)
//deque  双端动态数组 (随机访问迭代器)
//stack 栈容器 (没有迭代器)
//queue 队列容器 (没有迭代器)
//list 链表容器 (双向迭代器)

void printfListInt(list<int>& L)
{
	for (list<int>::iterator it = L.begin(); it != L.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

/*3.6.4 list  常用 API
* 
* 3.6.4.1 list 构造函数
list<T> lstT;//list 采用采用模板类实现 , 对象的默认构造形式：
list(beg,end);// 构造函数将 [beg, end) 区间中的元素拷贝给本身。
list(n,elem);// 构造函数将 n 个 elem 拷贝给本身。
list(const list &lst);// 拷贝构造函数。
*/

/*
* 3.6.4.2 list 数据元素插入和删除操作
push_back(elem);// 在容器尾部加入一个元素
pop_back();// 删除容器中最后一个元素
push_front(elem);// 在容器开头插入一个元素
pop_front();// 从容器开头移除第一个元素
insert(pos,elem);// 在 pos 位置插 elem 元素的拷贝，返回新数据的位置。
insert(pos,n,elem);// 在 pos 位置插入 n 个 elem 数据，无返回值。
insert(pos,beg,end);// 在 pos 位置插入 [beg,end) 区间的数据，无返回值。
clear();// 移除容器的所有数据
erase(beg,end);// 删除 [beg,end) 区间的数据，返回下一个数据的位置。
erase(pos);// 删除 pos 位置的数据，返回下一个数据的位置。
remove(elem);// 删除容器中所有与 elem 值匹配的元素。
*/

void test03()
{
	list<int> L = list<int>();
	L.push_back(10);
	L.push_back(20);
	L.push_back(30);
	L.push_back(40);
	L.push_back(50);
	printfListInt(L);

	//迭代器+n  只有随机访问迭代器支持
	//list容器的迭代器是双向迭代器
	//L.insert(L.begin() + 2,3,50); //error
	list<int>::iterator it = L.begin();
	//++  随机访问迭代器 以及 双向迭代器 都支持
	it++; it++;
	L.insert(it, 3, 50);
	printfListInt(L);

	//remove(elem);// 删除容器中所有与 elem 值匹配的元素。
	L.remove(50); //删除容器中所有的元素50
	printfListInt(L);
}


/*
* 3.6.4.3 list 大小操作
size();// 返回容器中元素的个数
empty();// 判断容器是否为空
resize(num);// 重新指定容器的长度为 num ，
若容器变长，则以默认值填充新位置。
如果容器变短，则末尾超出容器长度的元素被删除。
resize(num, elem);// 重新指定容器的长度为 num ，
若容器变长，则以 elem 值填充新位置。
如果容器变短，则末尾超出容器长度的元素被删除。
*/

/*
* 3.6.4.4 list 赋值操作
assign(beg, end);// 将 [beg, end) 区间中的数据拷贝赋值给本身。
assign(n, elem);// 将 n 个 elem 拷贝赋值给本身。
list& operator=(const list &lst);// 重载等号操作符
swap(lst);// 将 lst 与本身的元素互换。
*/


/*
* 3.6.4.5 list 数据的存取
front();// 返回第一个元素。
back();// 返回最后一个元素。
*/

/*
* 3.6.4.6 list 反转排序
reverse();// 反转链表，比如 lst 包含 1,3,5 元素，运行此方法后， lst 就包含 5,3,1
元素。
sort(); //list 排序(默认从小到大排序)
*/

void test04()
{
	list<int> L = list<int>();
	L.push_back(50);
	L.push_back(20);
	L.push_back(10);
	L.push_back(40);
	L.push_back(30);
	printfListInt(L);

	L.reverse();
	printfListInt(L);

	//sort是系统提供的算法 仅支持 随机访问迭代器(不支持list)
	//list容器不能使用系统算法 list会自己提供算法
	//sort(L.begin(),L.end());
	L.sort(); 
	printfListInt(L);
}

int main(int argc, char* argv[])
{
	//test03();

	test04();

	return 0;
}