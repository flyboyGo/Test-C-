#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

/*
* 3.7.3  对组(pair)
对组(pair)将一对值组合成一个值，这一对值可以具有不同的数据类型，
两个值可以分别用 pair 的两个公有属性 first 和 second 访问。 
类模板：template <class T1,class T2> struct pair. 如何创建对组?
*/

void test05()
{
	//定义对组的方式一
	//pair<int, string> pair(9527, "星爷");
	//cout << "编号：" << pair.first << ", 人物：" << pair.second << endl;

	//定义对组的方式二
	pair<int, string> pair2 = make_pair(10086,"移动");
	cout << "编号：" << pair2.first << ", 人物：" << pair2.second << endl;
}

//int main(int argc, char* argv[])
//{
//	test05();
//
//	return 0;
//}