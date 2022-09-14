#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

//队列容器
/*
* Queue 是一种先进先出(First In First Out,FIFO)的数据结构，它有两个出口，
  queue容器允许从一端新增元素，从另一端移除元素。

  Queue 所有元素的进出都必须符合”先进先出”的条件，只有 queue 的顶端元素，才
  有机会被外界取用。Queue 不提供遍历功能，也不提供迭代器。
*/

/*
* 3.5.3 queue  常用 API

3.5.3.1 queue 构造函数
queue<T> queT;//queue 采用模板类实现， queue 对象的默认构造形式：
queue(const queue &que);// 拷贝构造函数

3.5.3.2 queue 存取、插入和删除操作
push(elem);// 往队尾添加元素
pop();// 从队头移除第一个元素
back();// 返回最后一个元素
front();// 返回第一个元素

3.5.3.3 queue 赋值操作
queue& operator=(const queue &que);// 重载等号操作符

3.5.3.4 queue 大小操作
empty();// 判断队列是否为空
size();// 返回队列的大小
*/

void test02()
{
	queue<int> q = queue<int>();
	q.push(10);
	q.push(20);
	q.push(30);
	q.push(40);

	cout << "队列是否为空：" << q.empty() << endl;
	cout << "队列的大小：" << q.size() << endl;

	cout << "队头元素：" << q.front() << endl;
	cout << "队尾元素：" << q.back() << endl;

	cout << "遍历队列" << endl;
	while (!q.empty())
	{
		cout << q.front() << " ";
		q.pop();
	}
	cout << endl;
}

//int main(int argc, char* argv[])
//{
//	test02();
//
//	return 0;
//}