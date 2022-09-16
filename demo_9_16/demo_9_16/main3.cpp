#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>

using namespace std;

//链表容器
//list容器(双向链表) 的迭代器 必须具备前移、后移 提供的是双向迭代器

//vector 单端动态数组 (随机访问迭代器)
//deque  双端动态数组 (随机访问迭代器)
//stack 栈容器 (没有迭代器)
//queue 队列容器 (没有迭代器)
//list 链表容器 (双向迭代器)
//set、multiset 只读迭代器 (输入迭代器)
//map、mutlimap 只读迭代器 (输入迭代器)

//C++中的适配器分为容器适配器、迭代器适配器、函数适配器


//函数适配器 (函数适配器用于特化和扩展一元、二元函数对象)

//函数适配器分为绑定适配器、组合适配器(取反适配器)、函数指针适配器、成员函数适配器

//绑定适配器
//扩展函数的参数接口 (加入函数有一个参数 再扩展一个接口 可以传递两个参数)
void myPrint(int val, int tmp)
{
	cout << val + tmp << " ";
}

//val 是 for_each 提供的 tmp
//适配器2、公共继承 binary_function(二元)
//适配器3、参数的萃取 
//适配器4、对operator() 进行const修饰

class MyPrint : public binary_function<int,int,void>
{
public:
	void operator()(int val,int tmp) const
	{
		cout << "val = " << val << ",tmp =  " << tmp << endl;;
	}
};

void test05()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);

	//适配器1、用 bind2nd 或者 bindlst 绑定参数
	for_each(v.begin(), v.end(), bind2nd(MyPrint(),1000));
	cout << endl;
	cout << "---------------" << endl;
	for_each(v.begin(), v.end(), bind1st(MyPrint(), 1000));
	cout << endl;

	//bind2nd、bind1st的区别  绑定的参数位置不同
	//bind2nd 将外界的数据 绑定到第二个参数
	//bind1st 将外界的数据 绑定到第一个参数
}

//取反适配器
//note1  一元取反
//note2  二元取反

//取反适配器2、公共继承unary_function(一元)
//取反适配器3、参数萃取
//取反适配器4、const修饰 operator()
class MyGreaterThan3 : public unary_function<int,bool>
{
public:
	//一元谓词
	bool operator()(int val) const
	{
		return val > 3;
	}
};

void test06()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);

	//找出一个大于3的数
	vector<int>::iterator ret;
	ret = find_if(v.begin(),v.end(), MyGreaterThan3());
	if (ret != v.end())
	{
		cout << *ret << endl;
	}
	else
	{
		cout << "未找到" << endl;
	}
	
	//找出第一个小于3的数
	//取反适配器1、not1修饰
	ret = find_if(v.begin(), v.end(), not1(MyGreaterThan3()));
	if (ret != v.end())
	{
		cout << *ret << endl;
	}
	else
	{
		cout << "未找到" << endl;
	}
}

//二元取反
class MyGreaterReverse : public binary_function<int,int,bool>
{
public:
	bool operator()(int val1,int val2) const
	{
		return val1 > val2;
	}
};

void test07()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);

	for_each(v.begin(), v.end(), [](int val) {
		cout << val << " ";
	});
	cout << endl;

	//默认小 --> 大
	//sort(v.begin(),v.end());
	//更改排序规则 大 -- 小
	//sort(v.begin(), v.end(), MyGreaterReverse());
	//使用not2对MyGreaterReverse取反 小--->大
	//sort(v.begin(), v.end(), not2(MyGreaterReverse()));
	//使用not2对内建函数对象取反
	//greater 从大-->小   less从小-->大
	sort(v.begin(), v.end(), not2(greater<int>()));
	//sort(v.begin(), v.end(), not2(less<int>()));

	for_each(v.begin(), v.end(), [](int val) {
		cout << val << " ";
	});
}

//int main(int argc, char* argv[])
//{
//	//test05();
//
//	//test06();
//
//	test07();
//
//	return 0;
//}