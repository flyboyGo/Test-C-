#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printfVectorIntPlus(vector<int>& v)
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

//reserve(int len);// 容器预留 len 个元素长度，预留位置不初始化，元素不可访问。
void test08()
{
	// reserve(int len);// 容器预留 len 个元素长度（不改变容器的元素的个数 但改变元素的容量),
	// 预留位置不初始化，元素不可访问。
	vector<int> v;
	//一次性 给够空间 叫做 空间预留
	v.reserve(100);

	int* p = NULL;
	int count = 0;
	for (int i = 0; i < 100; i++)
	{
		v.push_back(i);
		if (p != &v[0])
		{
			count++;
			p = &v[0];
		}
	}
	cout << "另寻空间的次数: " << count << endl;
	
	cout << "size = " << v.size() << endl;
	cout << "capacity = " << v.capacity() << endl;
	
}

/*
* 3.2.4.4 vector 数据存取操作
at(int idx); // 返回索引 idx 所指的数据，如果 idx 越界，抛出 out_of_range 异常。
operator[];// 返回索引 idx 所指的数据，越界时，运行直接报错, 不抛出 out_of_range 异常。
front();// 返回容器中第一个数据元素
back();// 返回容器中最后一个数据元素
*/
void test09()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);

	cout << v.at(1) << endl;
	cout << v[3] << endl;
	cout << v.front() << endl;
	cout << v.back() << endl;

	//可以进行赋值操作
    v.at(1) = 6;
	v[2] = 7;
	v.front() = 5;
	v.back() = 0;
	printfVectorIntPlus(v);
}

/*
* 3.2.4.5 vector 插入和删除操作
push_back(ele); // 尾部插入元素 ele
*/
void test10()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	printfVectorIntPlus(v);

	//insert(const_iterator pos, int count,ele);// 迭代器指向位置 pos 插入 count个元素 ele.
	v.insert(v.begin() + 2, 3, 100);
	printfVectorIntPlus(v);

	//pop_back();// 删除最后一个元素
	v.pop_back();
	printfVectorIntPlus(v);

	//erase(const_iterator start, const_iterator end);// 删除迭代器从 start 到 end 之间的元素
	v.erase(v.begin() + 2,v.end() -1);
	printfVectorIntPlus(v);
	//容器中元素的个数发生变化 容器的容量不发生变化
	cout << v.size() << endl;
	cout << v.capacity() << endl;

	//erase(const_iterator pos);// 删除迭代器指向的元素
	//容器中元素的个数发生变化 容器的容量不发生变化
	v.erase(v.begin());
	printfVectorIntPlus(v);
	cout << v.size() << endl;
	cout << v.capacity() << endl;

	//clear();// 删除容器中所有元素
	//容器中元素的个数发生变化 容器的容量不发生变化
	v.clear();
	cout << v.size() << endl;
	cout << v.capacity() << endl;
	printfVectorIntPlus(v);

}

int main(int argc, char* argv[])
{
	//test08();

	//test09();

	test10();

	return 0;
}