#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

//栈容器
/*
* stack 是一种先进后出(First In Last Out,FILO)的数据结构，它只有一个出口，形式
如图所示。stack 容器允许新增元素，移除元素，取得栈顶元素，但是除了最顶端
外，没有任何其他方法可以存取 stack 的其他元素。换言之，stack 不允许有遍历
行为。 有元素推入栈的操作称为:push,将元素推出 stack 的操作称为 pop

* 先进先出的数据结构
* push入栈、pop出栈、top永远指向栈顶元素
* 栈容器没有迭代器(重点！！！！)
*/

/*
* 3.4.3 stack 常用 API
3.4.3.1 stack 构造函数
stack<T> stkT;//stack 采用模板类实现， stack 对象的默认构造形式：
3.4.3.2 stack 赋值操作
3.4.3.3 stack 数据存取操作
3.4.3.4 stack 大小操作
*/
void test01()
{
	stack<int> s;
	//push(elem);// 向栈顶添加元素
	s.push(10);
	s.push(20);
	s.push(30);

	//size();// 返回堆栈的大小
	//empty();// 判断堆栈是否为空
	cout << "size = " << s.size() << endl;
	cout << "是否为空 = " << s.empty() << endl;

	//pop();// 从栈顶移除第一个元素
	s.pop();

	//stack(const stack &stk);// 拷贝构造函数
	stack<int> s2 = stack<int>(s);

	//top();// 返回栈顶元素
	cout << s2.top() << endl;

	//stack& operator=(const stack &stk);// 重载等号操作符
	stack<int> s3 = s2;
	cout << s3.top() << endl;
}

//int main(int argc, char* argv[])
//{
//	test01();
//
//	return 0;
//}